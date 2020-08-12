#include "transform.h"

using namespace command;

Transform::Transform(const shared_ptr<Transformator>& ptr): _trans(ptr) {}
Transform::~Transform() {}
void Transform::execute(weak_ptr<Scene>) {}


Move::Move(const Vector& v):
    Transform(shared_ptr<Transformator>(new Transformator(new transform::Move(v)))) {}
Move::~Move() {}
void Move::execute(weak_ptr<Scene>) {}

MoveCamera::MoveCamera(const Vector& v): Move(v) {}
MoveCamera::~MoveCamera() {}
void MoveCamera::execute(weak_ptr<Scene> scene)
{
    manager::Transform(scene, _trans).exe_camera();
}

MoveLight::MoveLight(const Vector& v): Move(v) {}
MoveLight::~MoveLight() {}
void MoveLight::execute(weak_ptr<Scene> scene)
{
    manager::Transform(scene, _trans).exe_light();
}


Rotate::Rotate(const Point& c, const Vector& v):
    Transform(shared_ptr<Transformator>(new Transformator(new transform::Rotate(c, v)))) {}
Rotate::~Rotate() {}
void Rotate::execute(weak_ptr<Scene>) {}

RotateCamera::RotateCamera(const Vector& v): Rotate(Point(0, 0, 0), v) {}
RotateCamera::~RotateCamera() {}
void RotateCamera::execute(weak_ptr<Scene> scene)
{
    manager::Transform(scene, _trans).exe_camera();
}

RotateLight::RotateLight(const Point& c, const Vector& v): Rotate(c, v) {}
RotateLight::~RotateLight() {}
void RotateLight::execute(weak_ptr<Scene> scene)
{
    manager::Transform(scene, _trans).exe_light();
}