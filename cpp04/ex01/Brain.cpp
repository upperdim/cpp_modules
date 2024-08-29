/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:17:51 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 02:15:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain() : _ideaCount(0) {
	std::cout << "Brain created" << std::endl;
}

Brain::Brain(const Brain &from) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = from; // will call operator overload for assignment (=)
}

Brain::~Brain() {
	std::cout << "Brain is destroyed" << std::endl;
}

Brain& Brain::operator=(const Brain &from) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &from) {
		for (int i = 0; i < NUM_IDEAS; ++i) {
			this->_ideas[i] = from._ideas[i];
		}
		this->_ideaCount = from._ideaCount;
	}
	return *this;
}

// Add an idea to the brain, return true if successful, false if not
bool Brain::addIdea(std::string idea) {
	if (this->_ideaCount < NUM_IDEAS) {
		this->_ideas[_ideaCount] = idea;
		this->_ideaCount++;
		return true;
	}
	return false;
}

void Brain::printIdeas() {
	for (int i = 0; i < this->_ideaCount; ++i) {
		std::cout << "Idea " << (i + 1) << ": " << this->_ideas[i] << std::endl;
	}
}
