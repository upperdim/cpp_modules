/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 03:18:31 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/25 03:18:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat created" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat & from) : WrongAnimal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = from; // calls = operator overload
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const & rhs) {
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meow" << std::endl;
}
