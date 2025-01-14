#include "plate.h"
#include "3d_prmitives/mplate.h"
#include "visitors/object_visitor.h"

Plate::Plate(double h, double wide, double len, double R, bool is_up)
{
    _color = QColor(Qt::darkGreen).rgba();
    Point p0(-wide/2, h, 0), p1;
    if (is_up)
        p1 = Point(wide/2, h, len/2);
    else
        p1 = Point(wide/2, h, -len/2);

    Model* m_ptr = new TopPlateModel(_color, p1, p0, R);
    this->_model = shared_ptr<Model>(m_ptr);
}
Plate::Plate(double h, double wide, double len)
{
    _color = QColor(101, 67, 33).rgba();
    Point p1(wide/2, h, len/2);
    Point p2(-wide/2, h, -len/2);
    Model* m_ptr = new BottomPlateModel(_color, p1, p2);
    this->_model = shared_ptr<Model>(m_ptr);
}
Plate::Plate(const Plate& other): VisibleObject(other)
{
    _color = other._color;
}
Plate::~Plate() {}


void Plate::accept(ObjectVisitor& visitor)
{
    visitor.visit(*this);
}
SceneObject* Plate::clone()
{
    return (new Plate(*this));
}
