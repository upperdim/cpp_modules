/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:50:59 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/12 21:36:10 by tunsal           ###   ########.fr       */
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

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed &from) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_val = from.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_val;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_val = raw;
}
