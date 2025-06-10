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
Fixed::Fixed() : value(0) {}

Fixed::~Fixed(){}

int Fixed::getRawBits(void) const { return this->value; }
void Fixed::setRawBits(int const raw){ this->value = raw * (1 << fracBits);}

int Fixed::toInt(void) const { return (value >> fracBits);}

float Fixed::toFloat(void) const { return (float)value / (1 << fracBits);}


//Sobrecarga de operadores
bool Fixed::operator>(const Fixed &opCopy) const { return (this->value > opCopy.value);}
bool Fixed::operator>=(const Fixed &opCopy) const { return (this->value >= opCopy.value);}
bool Fixed::operator<=(const Fixed &opCopy) const { return (this->value <= opCopy.value);}
bool Fixed::operator==(const Fixed &opCopy) const { return (this->value == opCopy.value);}
bool Fixed::operator!=(const Fixed &opCopy) const { return (this->value != opCopy.value);}
bool Fixed::operator<(const Fixed &opCopy) const { return (this->value < opCopy.value);}

//Sobrecarga de operadores aritmeticos
Fixed Fixed::operator+(const Fixed &opCopy) const { return Fixed(this->toFloat() + opCopy.toFloat()); }
Fixed Fixed::operator-(const Fixed &opCopy) const { return Fixed(this->toFloat() - opCopy.toFloat()); }
Fixed Fixed::operator*(const Fixed &opCopy) const { return Fixed(this->toFloat() * opCopy.toFloat()); }
Fixed Fixed::operator/(const Fixed &opCopy) const { return Fixed(this->toFloat() / opCopy.toFloat()); }

// Pre-incremento
Fixed &Fixed::operator++()
{
	++this->value;
	return *this;
}

// Post-incremento
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->value;
	return temp;
}

// Pre-decremento
Fixed &Fixed::operator--()
{
	--this->value;
	return *this;
}

// Post-decremento
Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->value;
	return temp;
}
//Min y Max
Fixed &Fixed::min(Fixed &f1, Fixed &f2) { return (f1 < f2 ? f1 : f2);}
const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) { return (f1 < f2 ? f1 : f2);}
Fixed &Fixed::max(Fixed &f1, Fixed &f2) { return (f1 > f2 ? f1 : f2);}
const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) { return (f1 > f2 ? f1 : f2);}

std::ostream &operator<<(std::ostream &str, const Fixed &opCopy)
{
	str << opCopy.toFloat();
	return (str);
}