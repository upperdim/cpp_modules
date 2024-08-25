// Objects of same type can access each others private fields

#include <iostream>

class Demo {
	private:
		int privField;
	public:
		Demo(int i)           { this->privField = i; }
		int sum(Demo sumWith) { return this->privField + sumWith.privField; }
};

int main() {
	Demo a = Demo(1);
	Demo b = Demo(2);

	std::cout << a.sum(b) << std::endl;
}
