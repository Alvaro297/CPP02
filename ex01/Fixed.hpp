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
};

std::ostream &operator<<(std::ostream &str, const Fixed &opCopy);
#endif