#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits( int const raw );
	private:
			int					value;
			static const int	fracBits = 8;
};

#endif