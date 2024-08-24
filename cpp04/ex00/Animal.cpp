#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal created" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(const Animal &from) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = from; // will call operator overload for assignment (=)
}

Animal::~Animal() {
	std::cout << "Animal type " << this->_type << " is destroyed" << std::endl;
}

Animal& Animal::operator=(const Animal &from) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &from) {
		this->_type = from.getType();
	}
	return *this;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "No sound, ambigious animal" << std::endl;
}
