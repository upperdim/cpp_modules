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
	
}

Fixed::Fixed(const float f) {
	
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed &from) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_val = from.getRawBits();
	return *this;
}

std::ostream& operator<<(Fixed const &toPrint) {
	
}

// An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter.
// ? Fixed::operator<<(Fixed &fixed) {
	
// }

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_val;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}

float Fixed::toFloat(void) const {
	
}

int Fixed::toInt(void) const {
	
}
