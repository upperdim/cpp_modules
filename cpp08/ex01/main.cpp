/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:05:32 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 10:44:40 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "Span.hpp"

void subjectTest() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void rangeTest() {
	std::vector<int> numsToAdd = {6, 3, 17, 9, 11};
	
	Span s = Span(5);
	s.range(numsToAdd.begin(), numsToAdd.end());

	std::cout << "Shortest span of 6, 3, 17, 9, 11 = " << s.shortestSpan() << std::endl;
	std::cout << "Longest  span of 6, 3, 17, 9, 11 = " << s.longestSpan()  << std::endl; 
}

void bigTest() {
	const int NUM_COUNT = 10000;
	
	std::vector<int> numsToAdd;
	for (int i = NUM_COUNT; i > 0; --i) {
		numsToAdd.push_back(i);
	}
	
	Span s = Span(NUM_COUNT);
	s.range(numsToAdd.begin(), numsToAdd.end());

	std::cout << "Shortest span of 10000 numbers = " << s.shortestSpan() << std::endl;
	std::cout << "Longest  span of 10000 numbers = " << s.longestSpan()  << std::endl; 
}

void errorTest() {
	
}

int main() {
	subjectTest();
	rangeTest();
	// Test spans with at least 10 000 numbers, more would be even better
	bigTest();
	errorTest();
}
