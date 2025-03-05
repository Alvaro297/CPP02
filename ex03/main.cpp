#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

static float area(Point const &p1, Point const &p2, Point const &p3) {
	return std::abs(
		(p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
		 p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
		 p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) / 2.0f );
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float areaABC = area(a, b, c);
	float areaABP = area(a, b, point);
	float areaBCP = area(b, c, point);
	float areaCAP = area(c, a, point);

	return (areaABC == (areaABP + areaBCP + areaCAP));
}

int main() {
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);
	Point inside(5, 5);
	std::cout << "El punto (5,5) está dentro del triángulo? " << (bsp(a, b, c, inside) ? "Sí" : "No") << std::endl;
	Point onEdge(5, 0);
	std::cout << "El punto (5,0) está dentro del triángulo? " << (bsp(a, b, c, onEdge) ? "Sí" : "No") << std::endl;
	Point outside(10, 10);
	std::cout << "El punto (10,10) está dentro del triángulo? " << (bsp(a, b, c, outside) ? "Sí" : "No") << std::endl;
}
