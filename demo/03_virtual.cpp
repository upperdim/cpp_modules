#include <iostream>
#include <string>

class A {
	protected:
		std::string _name;
	public:
		A()                   { this->_name = "A"; }
		std::string getName() { return this->_name; }
		std::string talk()    { std::cout << "A talks" << std::endl; }
};

class B : public A {
	private:
	public:
		B()                   { this->_name = "B"; }
		std::string getName() { return this->_name; }
		std::string talk()    { std::cout << "B talks" << std::endl; }
};

// Base class
class Base {
public:
    // Virtual function that can be overridden
    void showMessage() {
        std::cout << "Message from Base class" << std::endl;
    }
};

// Derived class
class Derived : public Base {
public:
    // Override the base class function
    void showMessage() {
        std::cout << "Message from Derived class" << std::endl;
    }
};

int main() {
	A a = A();
	B b = B();

	std::cout << a.getName() << std::endl;
	std::cout << b.getName() << std::endl;
	a.talk();
	b.talk();

	// A *pa = new A();
	// B *pb = new B();
	
	// std::cout << a.getName() << std::endl;
	// std::cout << b.getName() << std::endl;
	// a.talk();
	// b.talk();

	// delete pa;
	// delete pb;

	Base baseObj;
    Base* ptr = &baseObj;
    ptr->showMessage();

    Derived derivedObj;
	Derived* d_ptr = &derivedObj;    
    d_ptr->showMessage();
}
