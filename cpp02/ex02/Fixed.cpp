/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:11:54 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/24 16:04:00 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath> // roundf()
#include "Fixed.hpp"

// Initializes static variable
const int Fixed::_numOfFractionalBits = DEFAULT_FRACTIONAL_BITS;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
}

Fixed::Fixed(const Fixed &from) {
	std::cout << "Copy constructor called" << std::endl;
	*this = from; // calls = operator overload to copy fields
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	this->_val = i << _numOfFractionalBits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	float x = f * (1 << this->_numOfFractionalBits); // Shift bits to the left (f * 256)
	x = roundf(x);                                   // Round because we will store it as integer
	this->_val = (int) x;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &from) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &from) {
		this->_val = from.getRawBits();
	}
	return *this;
}

// Stream overload functions are non-member but often friend functions
std::ostream& operator<<(std::ostream& output, Fixed const &toPrint) {
	// In this case we use a public method which didn't necessarily need `friend`
	float f = toPrint.toFloat();
	
	output << f;
	return output;
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

// Getters/Setters
int Fixed::getRawBits(void) const {
	return this->_val;
}

void Fixed::setRawBits(int const raw) {
	this->_val = raw;
}

float Fixed::toFloat(void) const {
	float f = static_cast<float>(this->_val);  // Convert to float form to work with
	f = f / (1 << this->_numOfFractionalBits); // Shift bits to the right (f / 256))
	return f;
}

int Fixed::toInt(void) const {
	return this->_val >> this->_numOfFractionalBits;
}
