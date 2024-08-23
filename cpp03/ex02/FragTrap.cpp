#include <iostream>
#include <string>
#include <limits>
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_name = "NamelessFragTrap";
	this->_attackDamage   = FT_DEFAULT_ATTACKDAMAGE;
	this->_energyPoints   = FT_DEFAULT_ENERGYPOINTS;
	this->_hitPoints      = FT_DEFAULT_HITPOINTS;
	// this->_gateKeeperMode = false;
	std::cout << "FragTrap created with the default name \"NamelessFragTrap\"" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_attackDamage   = FT_DEFAULT_ATTACKDAMAGE;
	this->_energyPoints   = FT_DEFAULT_ENERGYPOINTS;
	this->_hitPoints      = FT_DEFAULT_HITPOINTS;
	// this->_gateKeeperMode = false;
	std::cout << "FragTrap created with name " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &from) : ClapTrap(from) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	// this->_gateKeeperMode = from.getGateKeeperMode();
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->_name << " is destroyed" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &from) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(from);
	// this->_gateKeeperMode = from.getGateKeeperMode();
	return *this;
}

void FragTrap::attack(const std::string& target) {
	if (!hasResourcesFor("attack"))
		return;
	
	std::cout
		<< "FragTrap " << this->_name 
		<< " attacks " << target 
		<< ", causing " << this->_attackDamage 
		<< " points of damage! "
		<< "(Energy: " << this->_energyPoints << " -> " << this->_energyPoints - 1 << ")"
		<< std::endl;
	
	this->_energyPoints--;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "Give FragTrap a high five" << std::endl;
}
