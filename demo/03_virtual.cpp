#include <iostream>
#include <string>

static void printHeader(std::string header) {
	std::cout                                                   << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << header                                         << std::endl;
	std::cout << "============================================" << std::endl;
}

class A {
	public:
		A()                  { std::cout << "A default constructor" << std::endl; }
		virtual ~A()         { std::cout << "A destroyed" << std::endl; }
		void talk()          { std::cout << "A talks" << std::endl; }
		virtual void vtalk() { std::cout << "A vtalks" << std::endl; }
};

class B : public A {
	public:
		B()                  { std::cout << "B default constructor" << std::endl; }
		~B()                 { std::cout << "B destroyed" << std::endl; }
		void talk()          { std::cout << "B talks" << std::endl; }
		virtual void vtalk() { std::cout << "B vtalks" << std::endl; }
};

int main() {
	printHeader("Stack default constructor");
	{
		A a;
		B b;

		a.talk();
		b.talk();
	}

	printHeader("Stack default constructor (explicit)");
	{
		A a = A();
		B b = B();

		a.talk();
		b.talk();
	}

	printHeader("Stack pointer");
	{
		A a;
		B b;
		
		A *pa = &a;
		B *pb = &b;

		pa->talk();
		pb->talk();
	}

	printHeader("Heap pointer");
	{
		A *pa = new A();
		B *pb = new B();

		pa->talk();
		pb->talk();

		delete pb;
		delete pa;
	}

	printHeader("Needs virtual");
	{
		// Polymorphism gets involved with base class pointer to derived object
		A *pa = new B();

		pa->talk();
		pa->vtalk();

		// A destructor also needs to be virtual
		// otherwise A is destroyed but B is not, can create undefined behaviour
		delete pa;
	}
}
