/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:11:54 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/24 17:43:48 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept> // invalid_argument
#include <iostream>
#include <cmath> // roundf()
#include "Fixed.hpp"

// Initializes static variable
const int Fixed::_numOfFractionalBits = DEFAULT_FRACTIONAL_BITS;

Fixed::Fixed() {
	this->_val = 0;
}

Fixed::Fixed(const Fixed &from) {
	*this = from; // calls = operator overload to copy fields
}

Fixed::Fixed(const int i) {
	this->_val = i << _numOfFractionalBits;
}

Fixed::Fixed(const float f) {
	float x = f * (1 << this->_numOfFractionalBits); // Shift bits to the left (f * 256)
	x = roundf(x);                                   // Round because we will store it as integer
	this->_val = (int) x;
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed &from) {
	if (this != &from) {
		this->_val = from.getRawBits();
	}
	return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed &compareWith)  const {return this->_val >  compareWith._val;}
bool Fixed::operator>=(const Fixed &compareWith) const {return this->_val >= compareWith._val;}
bool Fixed::operator<(const Fixed &compareWith)  const {return this->_val <  compareWith._val;}
bool Fixed::operator<=(const Fixed &compareWith) const {return this->_val <= compareWith._val;}
bool Fixed::operator==(const Fixed &compareWith) const {return this->_val == compareWith._val;}
bool Fixed::operator!=(const Fixed &compareWith) const {return !(*this == compareWith);} // calls overloaded = operator

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &operand) const {
	Fixed ret;
	ret.setRawBits(this->_val + operand._val);
	return ret;
}

Fixed Fixed::operator-(const Fixed &operand) const {
	Fixed ret;
	ret.setRawBits(this->_val - operand._val);
	return ret;
}

Fixed Fixed::operator*(const Fixed &operand) const {
	Fixed ret;
	int bits = (this->_val * operand._val) >> this->_numOfFractionalBits;
	ret.setRawBits(bits);
	return ret;
}

Fixed Fixed::operator/(const Fixed &operand) const {
	if (operand == Fixed(0)) {
		throw std::invalid_argument("Division by 0");
	}
	
	Fixed ret;
	int bits = (this->_val << this->_numOfFractionalBits) / operand._val;
	ret.setRawBits(bits);
	return ret;
}

// Pre increment/decrement operators
Fixed& Fixed::operator++() {
	++(this->_val);
	return *this;
}

Fixed& Fixed::operator--() {
	--(this->_val);
	return *this;
}

// Post increment/decrement operators
Fixed Fixed::operator++(int) {
	Fixed notIncremented = *this;
	++(*this); // calls preincrement operator overload
	return notIncremented;
}

Fixed Fixed::operator--(int) {
	Fixed notDecremented = *this;
	--(*this); // calls predecrement operator overload
	return notDecremented;
}

// Member functions
Fixed& Fixed::min(Fixed &a, Fixed &b)                   {return a < b ? a : b;}
Fixed& Fixed::max(Fixed &a, Fixed &b)                   {return a > b ? a : b;}
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {return a < b ? a : b;}
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {return a > b ? a : b;}

// Getters/Setters
int Fixed::getRawBits(void) const {
	return this->_val;
}

void Fixed::setRawBits(int const raw) {
	this->_val = raw;
}

float Fixed::toFloat(void) const {
	// C style casts can bypass C++ type system
	// C++ casts are dynamic_cast and static_cast
	// Static cast works the C way, you are responsible for correctness
	// Dynamic cast has runtime checks
	float f = static_cast<float>(this->_val);  // Convert to float form to work with
	f = f / (1 << this->_numOfFractionalBits); // Shift bits to the right (f / 256))
	return f;
}

int Fixed::toInt(void) const {
	return this->_val >> this->_numOfFractionalBits;
}

// Non member functions
std::ostream& operator<<(std::ostream& output, Fixed const &toPrint) {
	float f = toPrint.toFloat();
	
	output << f;
	return output;
}
