#include "Dog.hpp"

Dog::Dog() {
}

Dog::Dog( const Dog & src ) {
}

Dog::~Dog() {
}

Dog &				Dog::operator=( Dog const & rhs ) {
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}
