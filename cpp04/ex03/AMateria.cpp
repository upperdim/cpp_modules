/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:13:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 07:40:41 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AMateria.hpp"

AMateria::AMateria() {
	// std::cout << "AMateria created" << std::endl;
	this->_type = "Typeless";
}

AMateria::AMateria(std::string const & type) {
	// std::cout << "AMateria with type " << type << " created" << std::endl;
	this->_type = type;
}

AMateria::AMateria(const AMateria &from) {
	// std::cout << "AMateria copy constructor called" << std::endl;
	*this = from; // will call operator overload for assignment (=)
}

AMateria::~AMateria() {
	// std::cout << "AMateria is destroyed" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &from) {
	// std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &from) {
		// this->_type = from.getType();
	}
	return *this;
}

std::string const & AMateria::getType() const {
	return this->_type;
}

// This implementation is mandatory here because signature of this member function was not `const` in the subject
// Overriden versions in Ice and Cure is actually used
void AMateria::use(ICharacter& target) {
	std::cout << "* used " << this->_type << " on " << target.getName() << " *" << std::endl;
}
