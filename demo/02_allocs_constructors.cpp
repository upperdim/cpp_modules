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
	Demo d1;

	Demo d2 = Demo();

	Demo d3 = Demo("d3");

	Demo *p_d4 = new Demo("d4");

	Demo d5;
	Demo *p_d5 = &d5;
	delete p_d5;

	delete p_d4;
}
