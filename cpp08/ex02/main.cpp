/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:24:00 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/14 20:42:19 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm> // find()
#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

void subjectTestWithList() {
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << " Running Subject Test (Replaced with list) " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	
	// .top()
	auto l_it = mstack.begin();
	std::advance(l_it, mstack.size() - 1);
	std::cout << *l_it << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;
	
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	// std::stack<int> s(mstack);
}

void subjectTest() {
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << " Running Subject Test                      " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void exampleSearchInStack() {
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << " Running Example Search Test               " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	
	MutantStack<int> mstack;
	
	// Put numbers into the stack
	for (int i = 1; i < 100; ++i) {
		mstack.push(i);
	}
	
	// Search for a number with iterator
	{
		int searchFor = 50;
		
		typename MutantStack<int>::iterator it = std::find(mstack.begin(), mstack.end(), searchFor);
		
		// if `find` can't find the target, `it` becomes `.end()`
		if (it == mstack.end()) {
			std::cout << "Could not find target number " << searchFor << std::endl;
		} else {
			std::cout << "Found target number " << searchFor << std::endl;
		}
	}

	// Search for a number with iterator
	{
		int searchFor = 200;
		
		typename MutantStack<int>::iterator it = std::find(mstack.begin(), mstack.end(), searchFor);
		
		// if `find` can't find the target, `it` becomes `.end()`
		if (it == mstack.end()) {
			std::cout << "Could not find target number " << searchFor << std::endl;
		} else {
			std::cout << "Found target number " << searchFor << std::endl;
		}
	}
}

int main() {
	subjectTest();
	subjectTestWithList();
	exampleSearchInStack();
}
