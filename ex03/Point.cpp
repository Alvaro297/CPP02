#include "Point.hpp"

Point::Point() : x(0), y(0){}
Point::Point(const Point &p): x(p.x), y(p.y) {}

Point::~Point()
{
}