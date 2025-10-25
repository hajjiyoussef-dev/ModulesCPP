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
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
        Fixed operator*(const Fixed &obj) const;
        Fixed operator+(const Fixed &obj) const;
        Fixed operator-(const Fixed &obj) const;
        Fixed operator/(const Fixed &obj) const;
        bool operator>(const Fixed &obj) const;
        bool operator<(const Fixed &obj) const;
        bool operator>=(const Fixed &obj) const;
        bool operator<=(const Fixed &obj) const;
        bool operator!=(const Fixed &obj) const;
        bool operator==(const Fixed &obj) const;
        Fixed &operator++();
        Fixed &operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        
};

std::ostream& operator<<(std::ostream &out, const Fixed &obj);



#endif