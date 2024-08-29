/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:36:52 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 06:57:03 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource created" << std::endl;
	for (int i = 0; i < MAT_SRC_INV_SIZE; i++){
		this->_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource &from) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = from; // will call operator overload for assignment (=)
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource is destroyed" << std::endl;
	for (int i = 0; i < MAT_SRC_INV_SIZE; i++){
		delete this->_inventory[i];
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &from) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &from) {
		for (int i = 0; i < MAT_SRC_INV_SIZE; ++i) {
			if (this->_inventory[i]) {
				// Delete materias existing in this inventory
				delete this->_inventory[i];
			}
			
			// Copy over materias existing in other inventory
			if (from._inventory[i] == NULL) {
				this->_inventory[i] = NULL;
			} else {	
				this->_inventory[i] = from._inventory[i]->clone();
			}
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MAT_SRC_INV_SIZE; ++i) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return;
		}
	}
	
	std::cout << "MateriaSource is full" << std::endl;
}

// Return the first materia in the inventory that matches the `type`. Return NULL if no match 
AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < MAT_SRC_INV_SIZE; ++i) {
		if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type) {
			return this->_inventory[i]->clone();
		}
	}
	return NULL;
}
