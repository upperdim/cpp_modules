/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:39:12 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/08 19:25:35 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
	std::cout << "Weapon " << type << " created" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "Weapon " << this->_type << " destroyed" << std::endl;
}

std::string& Weapon::getType() {
	return this->_type;
}

void Weapon::setType(std::string type) {
	std::cout << "Weapon " << this->_type << " changed into " << type << std::endl;
	this->_type = type;
}
