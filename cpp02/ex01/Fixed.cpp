/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:11:54 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/16 20:11:01 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

// Initializes static variable
const int Fixed::_numOfFractionalBits = DEFAULT_FRACTIONAL_BITS;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_val = 0;
}

Fixed::Fixed(Fixed &from) {
	std::cout << "Copy constructor called" << std::endl;
	*this = from;
}

Fixed::Fixed(const int i) {
	std::cout << "Integer constructor called" << std::endl;
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

Fixed& Fixed::operator=(Fixed &from) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &from) {
		this->_val = from.getRawBits();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& output, Fixed const &toPrint) {
	float f = toPrint.toFloat();
	
	output << f;
	return output;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_val;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
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
