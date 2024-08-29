/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:54:02 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 02:44:34 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "Animal created" << std::endl;
	this->_type = "Animal";
}

AAnimal::AAnimal(const AAnimal &from) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = from; // will call operator overload for assignment (=)
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal type " << this->_type << " is destroyed" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &from) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &from) {
		this->_type = from.getType();
	}
	return *this;
}

std::string AAnimal::getType() const {
	return this->_type;
}
