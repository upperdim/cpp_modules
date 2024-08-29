/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 04:53:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 05:21:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Character.hpp>

Character::Character() {
	std::cout << "Character Nameless created" << std::endl;
	this->_name = "Nameless";
	for (int i = 0; i < CHAR_INV_SIZE; i++){
		this->_inventory[i] = NULL;
	}
	this->_inventoryItemCount = 0;
}

Character::Character(std::string const & name) {
	std::cout << "Character " << name << " created" << std::endl;
	this->_name = name;
	for (int i = 0; i < CHAR_INV_SIZE; i++){
		this->_inventory[i] = NULL;
	}
	this->_inventoryItemCount = 0;
}

Character::Character(const Character &from) {
	std::cout << "Character copy constructor called" << std::endl;
	*this = from; // will call operator overload for assignment (=)
}

Character::~Character() {
	std::cout << "Character " << this->_name << " is destroyed" << std::endl;
	for (int i = 0; i < CHAR_INV_SIZE; i++){
		delete this->_inventory[i];
	}
}

Character& Character::operator=(const Character &from) {
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &from) {
		this->_name = from._name;
		for (int i = 0; i < CHAR_INV_SIZE; ++i) {
			if (from._inventory[i] == NULL) {
				this->_inventory[i] = NULL;
			} else {
				this->_inventory[i] = from._inventory[i]->clone();
			}
		}
		this->_inventoryItemCount = from._inventoryItemCount;
	}
	return *this;
}

std::string const & Character::getName() const {
	return this->_name;
}

void Character::equip(AMateria* m) {
	if (this->_inventoryItemCount >= CHAR_INV_SIZE) {
		std::cout << "Inventory is full";
		return;
	}
	
	this->_inventory[_inventoryItemCount] = m;
	this->_inventoryItemCount++;
	
}

// Unequipped item is not deleted, make sure to save and handle its pointer
void Character::unequip(int idx) {
	if (idx >= 0 && idx < CHAR_INV_SIZE) {
		this->_inventory[idx] = NULL;
	}
	
	for (int i = idx; i < CHAR_INV_SIZE - 1; ++i) {
		this->_inventory[idx] = this->_inventory[idx + 1];
	}
	this->_inventory[CHAR_INV_SIZE - 1] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < CHAR_INV_SIZE) {
		this->_inventory[idx]->use(target);
	}
}
