
#include "Point.hpp"


Point::Point() : x(0), y(0){}

Point::~Point() {}


Point::Point(float value_x, float value_y): x(value_x), y(value_y) {}

Point::Point(const Point &obj) : x(obj.x), y(obj.y){}

Point &Point::operator=(const Point &obj){

    (void)obj;
    return (*this);
}

Fixed Point::getX( void ) const {

    return (x);
}

Fixed  Point::getY( void ) const {

    return (y);
}

float area(float x1 ,float y1, float x2, float y2, float x3, float y3){

    return std::fabs(((x1 *(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f));
}

bool bsp( Point const a, Point const b, Point const c, Point const point ){

    float A = area(a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat()); // ABC

    float A1 = area(point.getX().toFloat(), point.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat()); // PBC

    float A2 = area(point.getX().toFloat(), point.getY().toFloat(), a.getX().toFloat(), a.getY().toFloat(), b.getX().toFloat(), b.getY().toFloat()); //PAB

    float A3 = area(point.getX().toFloat(), point.getY().toFloat(), a.getX().toFloat(), a.getY().toFloat(), c.getX().toFloat(), c.getY().toFloat()); // PAC

    if (A1 == 0 || A2 == 0 || A3 == 0)
        return false;
    return (std::fabs(A - (A1 + A2 + A3)) < 0.0001f);
}