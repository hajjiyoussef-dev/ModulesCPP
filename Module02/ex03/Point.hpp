#ifndef POINT_HPP
#define POINT_HPP


#include "Fixed.hpp"
#include <iostream>



class Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point(/* args */);
        Point(float value_x, float value_y);
        Point(const Point &obj);
        Point &operator=(const Point &obj); 
        ~Point();
       Fixed  getX( void ) const;
       Fixed  getY( void ) const;

};

bool bsp( Point const a, Point const b, Point const c, Point const point );


#endif 