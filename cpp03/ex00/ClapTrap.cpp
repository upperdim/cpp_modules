/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:54:42 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/21 06:21:29 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "ClapTrap.hpp"

// alternative (c++11): 
// ClapTrap::ClapTrap() : ClapTrap("Default Name") {
ClapTrap::ClapTrap() : _name("unnamed"), _hitPoints(DEFAULT_HITPOINTS), _energyPoints(DEFAULT_ENERGYPOINTS), _attackDamage(DEFAULT_ATTACKDAMAGE) {
	std::cout << "ClapTrap created with the default name \"Nameless\"" << std::endl;
	// alternative: ClapTrap("Nameless");
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(DEFAULT_HITPOINTS), _energyPoints(DEFAULT_ENERGYPOINTS), _attackDamage(DEFAULT_ATTACKDAMAGE) {
	std::cout << "ClapTrap created with name " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &from) {
	std::cout << "Copy constructor called" << std::endl;
	*this = from; // will call operator overload for assignment (=)
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &from) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &from) {
		this->_name = from.getName();
		this->_hitPoints = from.getHitPoints();
		this->_energyPoints = from.getEnergyPoints();
		this->_attackDamage = from.getAttackDamage();
	}
	return *this;
}

bool ClapTrap::hasResourcesFor(std::string action) {
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
	if (!hasResourcesFor("attack"))
		return;
	
	std::cout
		<< "ClapTrap " << this->_name 
		<< " attacks " << target 
		<< ", causing " << this->_attackDamage 
		<< " points of damage! "
		<< "(Energy: " << this->_energyPoints << " -> " << this->_energyPoints - 1 << ")"
		<< std::endl;
	
	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is already broken, can't take further damage" << std::endl;
		return;
	}

	// Prevent underflow
	unsigned int newHitPoints;
	if (amount < this->_hitPoints) {
		 newHitPoints = this->_hitPoints - amount;
	} else {
		std::cout << "That's more than enough damage" << std::endl;
		newHitPoints = 0;
	}

	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage. Hit points " << this->_hitPoints << " -> " << newHitPoints << std::endl;

	this->_hitPoints = newHitPoints;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!hasResourcesFor("repair"))
		return;
	
	// Prevent overflow
	if (this->_hitPoints > std::numeric_limits<unsigned int>::max() - amount) {
		std::cout << "Max hitpoints reached" << std::endl;
		amount = std::numeric_limits<unsigned int>::max() - this->_hitPoints;
	}

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

void ClapTrap::setName(std::string name) {
	this->_name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
	this->_hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
	this->_energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
	this->_attackDamage = attackDamage;
}
