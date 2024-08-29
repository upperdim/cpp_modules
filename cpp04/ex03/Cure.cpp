/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:32:54 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 07:41:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure() : AMateria() {
	// std::cout << "Cure created" << std::endl;
	this->_type = "cure";
}

Cure::Cure(const Cure & from) : AMateria() {
	// std::cout << "Cure copy constructor called" << std::endl;
	this->_type = "cure";
	*this = from; // calls = operator overload
}

Cure::~Cure() {
	// std::cout << "Cure destroyed" << std::endl;
}

Cure &Cure::operator=(Cure const & from) {
	if (this != &from) {
		//this->_type = from._type;
	}
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
