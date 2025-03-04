#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		this->value = f.value;
	return (*this);
}

Fixed::Fixed(int nmbr)
{
	this->value = nmbr << fracBits;
}

Fixed::Fixed(float nmbr)
{
	this->value = static_cast<int>(roundf(nmbr * (1 << fracBits))); 
}

Fixed::Fixed(const Fixed &f)
{
	this->value = f.value;
}
Fixed::Fixed(){}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const { return this->value; }
void Fixed::setRawBits(int const raw){ this->value = raw * (1 << fracBits);}

int Fixed::toInt(void) const { return (value >> fracBits);}

float Fixed::toFloat(void) const { return (float)value / (1 << fracBits);}

std::ostream &operator<<(std::ostream &str, const Fixed &opCopy)
{
	str << opCopy.toFloat();
	return (str);
}