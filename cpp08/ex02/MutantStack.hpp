/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:24:01 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/14 20:22:32 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
private:
public:
	// Inherit and call the default constructor of the std::stack
	// Initialize base class part of the constructed object including internal container c
	MutantStack() : std::stack<T, Container>() {}

	// Again call copy constructor of the inherited class
	MutantStack(MutantStack<T, Container> const & from) : std::stack<T, Container>(from) {}

	// Again call assignment operator overload of the inherited class
	MutantStack<T, Container>& operator=(MutantStack<T, Container> const & rhs) {
		if (this != &rhs) {
			std::stack<T, Container>::operator=(rhs);
		}
		return *this;
	}
	
	~MutantStack() {}

	// Stack is not iteratable, but internal container of stack is.
	// We want to get the iterator to the internal container of the stack,
	// and expose it through our MutantStack class unline std::stack.
	//
	// `iterator` is a type: `typename Container::iterator`
	//
	// It is an iterator of whatever the internal container is.
	typedef typename Container::iterator iterator;
	iterator begin() {
		// `c` is underlying data structure of the stack
		// https://en.cppreference.com/w/cpp/container/stack
		return this->c.begin();
	}
	
    iterator end() {
		return this->c.end();
	}
};

#endif
