#include <iostream>
#include <string>

class Demo {
	private:
		std::string _name;
	public:
		Demo() {
			std::cout << "Default constructor called" << std::endl;
			this->_name = "Default";
		}

		Demo(std::string name) {
			std::cout << "Name constructor called with " << name << std::endl;
			this->_name = name;
		}

		~Demo() {
			std::cout << this->_name << " destroyed" << std::endl;
		}

		std::string getName() const {
			return this->_name;
		}
};

int main() {
	// Stack default constructor
	Demo d1;
	std::cout << "d1 name = " << d1.getName() << std::endl;

	// Stack default constructor (explicit)
	Demo d2 = Demo();
	std::cout << "d2 name = " << d2.getName() << std::endl;

	// Stack name constructor
	Demo d3 = Demo("d3");
	std::cout << "d3 name = " << d3.getName() << std::endl;

	// Heap name constructor
	Demo *p_d4 = new Demo("d4");
	std::cout << "*p_d4 name = " << p_d4->getName() << std::endl;
	delete p_d4;

	// Stack pointer
	Demo d5;
	std::cout << "d5 name = " << d5.getName() << std::endl;
	Demo *p_d5 = &d5;
	std::cout << "*p_d5 name = " << p_d5->getName() << std::endl;
	delete p_d5;
}
