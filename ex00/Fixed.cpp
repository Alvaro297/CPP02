#include "Fixed.hpp"

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		this->value = f.value;
	return (*this);
}

Fixed::Fixed(const Fixed &f){
	this->value = f.value;
}

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;

}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const { return this->value; }
void Fixed::setRawBits(int const raw){ this->value = raw * (1 << fracBits);}