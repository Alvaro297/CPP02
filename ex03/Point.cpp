#include "Point.hpp"

Point::Point() : x(0), y(0){}
Point::Point(const float x, const float y) : x(x), y(y) {}
Point::Point(const Point &p): x(p.x), y(p.y) {}
Point::~Point() {}

Fixed Point::getX(void) const{ return(this->x);}
Fixed Point::getY(void) const{ return(this->y);}
