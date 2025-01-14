#include "projected_model.h"

///
ProjEdge::ProjEdge(const Point &p_1, double i1,
                   const Point &p_2, double i2)
{
    Point p1=p_1, p2=p_2;
    if (p1.y < p2.y)
    {
        swap(p1, p2);
        swap(i1, i2);
    }

    ymax = static_cast<int>(round(p1.y));
    x0 = p1.x;
    z0 = p1.z;
    i0 = i1;
    y0 = ymax - static_cast<int>(round(p2.y));

    if (y0)
    {
//        dx = (p2.x - p1.x) / y0;
//        dz = (p2.z - p1.z) / y0;
//        di = (i2 - i1) / y0;

        dx = (p2.x - p1.x) / (p1.y-p2.y);
        dz = (p2.z - p1.z) / (p1.y-p2.y);
        di = (i2 - i1) / (p1.y-p2.y);
    }
    else
    {
        dx = 0;
        dz = 0;
        di = 0;
    }

    this->reset();
}
ProjEdge::ProjEdge(const ProjEdge& other)
{
    x = other.x;
    y = other.y;
    z = other.z;
    i = other.i;

    x0 = other.x0;
    y0 = other.y0;
    z0 = other.z0;
    i0 = other.i0;

    dx = other.dx;
    dz = other.dz;
    di = other.di;
    ymax = other.ymax;
}

ProjEdge::~ProjEdge() {}

void ProjEdge::reset()
{
    x = x0;
    z = z0;
    i = i0;
    y = y0;
}
bool ProjEdge::step()
{
    x += dx;
    z += dz;
    y -= 1;
    i += di;
//    if (i>1 || i<0.29)
//        cout << "------------------------------ " << i << endl;
    return y <= 0;
}
void ProjEdge::print()
{
    printf("PE: [%7.3f, %7.3d, %7.3f] (y0:%d, ymax:%d)\n", x, y, z, y0, ymax);
}

bool ProjEdge::is_done() const
{
    return y <= 0;
}
bool ProjEdge::is_horizontal() const
{
    return y0 == 0;
}


///
ProjSide::ProjSide() {}
ProjSide::ProjSide(ProjSide&& other):
    edges(other.edges)
{
    this->temp_y = other.temp_y;
    this->edges = std::move(other.edges);
    this->active_edges = std::move(other.active_edges);
    this->waiting_edges = std::move(other.waiting_edges);
}
ProjSide::~ProjSide()
{
    edges.clear();
    active_edges.clear();
    waiting_edges.clear();
}

void ProjSide::init()
{
    temp_y = edges[0].ymax;
    size_t i = 0;
    while (edges[i].ymax == temp_y && i < edges.size())
        active_edges.push_back(edges[i++]);
    for (; i < edges.size(); i++)
        waiting_edges.push_back(edges[i]);
}
void ProjSide::add_edge(const ProjEdge &edge)
{
    if (edge.is_horizontal())
        return;
    edges.push_back(edge);

    for (size_t i=edges.size()-1; i>0; i--)
    {
        if (edges[i-1].ymax < edges[i].ymax)
            swap(edges[i-1], edges[i]);
        else if (edges[i-1].ymax == edges[i].ymax)
        {
            if (edges[i-1].x > edges[i].x)
                swap(edges[i-1], edges[i]);
            else if (edges[i-1].x >= edges[i].x &&
                     edges[i-1].dx > edges[i].dx)
                swap(edges[i-1], edges[i]);
            else
                break;
        }
        else
            break;
    }
}
bool ProjSide::step()
{
    temp_y -= 1;
    for (auto i=active_edges.begin(); i < active_edges.end();)
    {
        if (i->step())
        {
            active_edges.erase(i);
        }
        else
            i++;
    }

    auto i = waiting_edges.begin();
    while (i < waiting_edges.end() && i->ymax == temp_y)
    {
        active_edges.push_back(*i);
        for (size_t j=active_edges.size()-1; j>0; j--)
        {
            if (active_edges[j-1].x > active_edges[j].x)
                swap(active_edges[j-1], active_edges[j]);
            else
                break;
        }

        waiting_edges.erase(i);
    }
    return is_done();
}
bool ProjSide::is_done()
{
    return active_edges.size() == 0;
}
bool ProjSide::is_empty()
{
    return this->edges.size() == 0;
}
