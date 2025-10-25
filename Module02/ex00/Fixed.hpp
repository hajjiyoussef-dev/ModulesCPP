#ifndef FIXED_HPP
#define FIXED_HPP

#include "iostream"

class Fixed
{
    private:
        int number;
        static const int fractionBits;
    public:
        Fixed();
        Fixed(const Fixed &obj);
        Fixed &operator=(const Fixed &obj);
        ~Fixed(); 
        int getRawBits( void ) const;
        void setRawBits(int const raw);
};





#endif