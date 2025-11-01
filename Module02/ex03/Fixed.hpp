#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int number;
        static const int fractionBits;
    public:
        Fixed();
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed &obj);
        Fixed &operator=(const Fixed &obj);
        ~Fixed(); 
        int getRawBits( void ) const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;
        
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);



#endif