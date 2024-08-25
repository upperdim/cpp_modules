#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog : public Animal {
private:
public:
	Dog();
	Dog( Dog const & src );
	~Dog();
	Dog& operator=(Dog const & rhs);
};

#endif
