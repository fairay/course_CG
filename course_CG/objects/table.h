#ifndef TABLE_H
#define TABLE_H

#define MIN_H_TABLE 100
#define MIN_LW_TABLE 200

#include "composite_object.h"

#include "leg.h"
#include "plate.h"
#include "rails.h"


class Table: public CompositeObject
{
public:
    Table();
    Table(double leg_h, double len, double wide, double r);
    explicit Table(const Table& other);
    virtual ~Table();

    virtual void accept(ObjectVisitor& visitor);
    virtual SceneObject* clone();

    Point get_min_border();
    Point get_max_border();
private:
    double _leg_h = 750;
    double _len = 2800;
    double _wide = 1530;
    double _hole_r = 100;

    const double _plate_h = 100;
    const double _rail_w = 100;

    void _init_models();
    void _init_legs();
    void _init_plates();
    void _init_rails();
};

#endif // TABLE_H
