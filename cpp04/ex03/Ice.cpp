/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:32:41 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 07:41:13 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice() : AMateria() {
	// std::cout << "Ice created" << std::endl;
	this->_type = "ice";
}

Ice::Ice(const Ice & from) : AMateria() {
	// std::cout << "Ice copy constructor called" << std::endl;
	this->_type = "ice";
	*this = from; // calls = operator overload
}

Ice::~Ice() {
	// std::cout << "Ice destroyed" << std::endl;
}

Ice &Ice::operator=(Ice const & from) {
	if (this != &from) {
		//this->_type = from._type;
	}
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
