/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:39:07 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/08 19:27:33 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->_name = name;
	this->_weaponPtr = NULL;
	std::cout << "HumanB " << name << " created without weapon" << std::endl;
}

HumanB::~HumanB() {
	std::cout << "HumanB " << this->_name << " destroyed" << std::endl;
}

void HumanB::attack() {
	std::cout
		<< this->_name 
		<< " attacks with their " 
		<< (this->_weaponPtr == NULL ? "fists" : this->_weaponPtr->getType())
		<< std::endl;
}

void HumanB::setWeapon(Weapon &weaponRef) {
	this->_weaponPtr = &weaponRef;
	std::cout << this->_name << " picked up weapon " << weaponRef.getType() << std::endl;
}
