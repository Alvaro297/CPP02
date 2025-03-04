#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	fracBits = 8;
	public:
		Fixed();
		Fixed (int nmbr);
		Fixed (float nmbr);
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits( int const raw );
		int toInt(void) const;
		float toFloat(void) const;
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		static const Fixed &min(const Fixed &f, const Fixed &f2);
		static Fixed &min(Fixed &f, Fixed &f2);
		static const Fixed &max(const Fixed &f, const Fixed &f2);
		static Fixed &max(Fixed &f, Fixed &f2);
};

std::ostream &operator<<(std::ostream &str, const Fixed &opCopy);
#endif