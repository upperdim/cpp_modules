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
	this->_attackDamage   = ST_DEFAULT_ATTACKDAMAGE;
	this->_energyPoints   = ST_DEFAULT_ENERGYPOINTS;
	this->_hitPoints      = ST_DEFAULT_HITPOINTS;
	this->_gateKeeperMode = false;
	std::cout << "ScavTrap created with the default name \"NamelessScavTrap\"" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_attackDamage   = ST_DEFAULT_ATTACKDAMAGE;
	this->_energyPoints   = ST_DEFAULT_ENERGYPOINTS;
	this->_hitPoints      = ST_DEFAULT_HITPOINTS;
	this->_gateKeeperMode = false;
	std::cout << "ScavTrap created with name " << name << std::endl;
}

// Calls copy constructor of ClapTrap with `from`, which does the copying of the inherited fields
// ScavTrap specific fields must still be copied over in this function
//
// It's smarter to just call the = operator overload of this class
// Because both copy contructor of ClapTrap and = operator of this class
// calls the same = operator of ClapTrap class
//
// Since I also need to copy ScavTrap specific fields in = operator overload of this class,
// there is no need to duplicate assignment code here.
// But I do it regardless to avoid possible 42 problems
ScavTrap::ScavTrap(const ScavTrap &from) : ClapTrap(from) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->_gateKeeperMode = from.getGateKeeperMode();
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &from) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(from);
	this->_gateKeeperMode = from.getGateKeeperMode();
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

void ScavTrap::guardGate() {
	if (this->_gateKeeperMode) {
		std::cout << "ScavTrap is already guarding the gate!" << std::endl;
		return;
	}

	this->_gateKeeperMode = true;
	std::cout << "ScavTrap is now guarding the gate." << std::endl;
}

bool ScavTrap::getGateKeeperMode() const {
	return this->_gateKeeperMode;
}

void ScavTrap::setGateKeeperMode(bool gateKeeperMode) {
	this->_gateKeeperMode = gateKeeperMode;
}
