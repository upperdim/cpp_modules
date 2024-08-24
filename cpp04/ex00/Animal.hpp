#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
	std::string _type;
public:
	Animal();
	Animal(const Animal &from);
	~Animal();
	Animal& operator=(const Animal &from);

	std::string getType() const;
};

#endif
