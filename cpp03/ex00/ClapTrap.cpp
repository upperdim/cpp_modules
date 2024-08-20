/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:54:42 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/20 07:21:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap created with the default name \"Nameless\"" << std::endl;
	this->_name = "Nameless";
	// alternative: ClapTrap("Nameless");
}

ClapTrap::ClapTrap(std::string name) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap created with name " << name << std::endl;
	this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &from) {
	std::cout << "Copy constructor called" << std::endl;
	*this = from; // will call operator overload for assignment (=)
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &from) {
	if (this != &from) {
		std::cout << "Copy assignment operator called" << std::endl;
		this->_name = from.getName();
		this->_hitPoints = from.getHitPoints();
		this->_energyPoints = from.getEnergyPoints();
		this->_attackDamage = from.getAttackDamage();
	}
	return *this;
}

bool ClapTrap::checkResources(std::string action) {
	if (this->_energyPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " doesn't have energy to " << action << std::endl;
		return false;
	}

	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " doesn't have hit points to " << action << std::endl;
		return false;
	}

	return true;
}

void ClapTrap::attack(const std::string& target) {
	if (!checkResources("attack"))
		return;
	
	std::cout
		<< "ClapTrap " << this->_name 
		<< " attacks " << target 
		<< ", causing " << this->_attackDamage 
		<< "points of damage! (Energy: " << this->_energyPoints << " -> " << this->_energyPoints - 1
		<< std::endl;
	
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is already broken, can't take further damage" << std::endl;
		return;
	}

	// Prevent underflow
	if (amount > this->_hitPoints)
		amount = this->_hitPoints;

	unsigned int newHitPoints = this->_hitPoints - amount;

	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage. Hit points " << this->_hitPoints << " -> " << newHitPoints << std::endl;

	this->_hitPoints = newHitPoints;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!checkResources("repair"))
		return;
	
	// Prevent overflow TODO: check!
	if (std::numeric_limits<unsigned int>::max() - amount <= this->_hitPoints)
		amount = std::numeric_limits<unsigned int>::max() - this->_hitPoints;

	unsigned int newHitPoints = this->_hitPoints + amount;
	
	std::cout << "ClapTrap " << this->_name
		<< " repair: Hitpoints " << this->_hitPoints    << " -> " << newHitPoints
		<< ", Energy: "          << this->_energyPoints << " -> " << this->_energyPoints - 1
		<< std::endl;
	
	this->_energyPoints--;
	this->_hitPoints = newHitPoints;
}

std::string ClapTrap::getName() const {
	return this->_name;
}

unsigned int ClapTrap::getHitPoints() const  {
	return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
}
