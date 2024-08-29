/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:54:02 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 02:07:47 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::~AAnimal() {
	std::cout << "Animal type is destroyed" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &from) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &from) {
		this->_type = from._type;
	}
	return *this;
}

void AAnimal::makeSound() const {
	std::cout << "No sound, ambigious animal" << std::endl;
}
