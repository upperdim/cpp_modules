/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 03:18:45 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/25 03:18:45 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal created" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &from) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = from; // will call operator overload for assignment (=)
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal type " << this->_type << " is destroyed" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &from) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &from) {
		this->_type = from.getType();
	}
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::makeSound() const {
	std::cout << "If called from inherited class, this was not supposed to show up" << std::endl;
}
