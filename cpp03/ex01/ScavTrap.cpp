/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 06:31:52 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/21 06:31:53 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_name = "NamelessScavTrap";
	this->_attackDamage = ST_DEFAULT_ATTACKDAMAGE;
	this->_energyPoints = ST_DEFAULT_ENERGYPOINTS;
	this->_hitPoints    = ST_DEFAULT_HITPOINTS;
	std::cout << "ScavTrap created with the default name \"NamelessScavTrap\"" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_attackDamage = ST_DEFAULT_ATTACKDAMAGE;
	this->_energyPoints = ST_DEFAULT_ENERGYPOINTS;
	this->_hitPoints    = ST_DEFAULT_HITPOINTS;
	std::cout << "ScavTrap created with name " << name << std::endl;
}

// Calls copy constructor of ClapTrap with `from`, which does the copying of the inherited fields
// ScavTrap specific fields must still be copied over in this function
ScavTrap::ScavTrap(const ScavTrap &from) : ClapTrap(from) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &from) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(from);
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (!hasResourcesFor("attack"))
		return;
	
	std::cout
		<< "ScavTrap " << this->_name 
		<< " attacks " << target 
		<< ", causing " << this->_attackDamage 
		<< " points of damage! "
		<< "(Energy: " << this->_energyPoints << " -> " << this->_energyPoints - 1 << ")"
		<< std::endl;
	
	this->_energyPoints--;
}
