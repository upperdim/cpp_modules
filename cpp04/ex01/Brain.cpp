/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:17:51 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/26 15:23:57 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Brain.hpp"

Brain::Brain() {
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
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &from) {
		for (int i = 0; i < NUM_IDEAS; ++i) {
			this->_ideas[i] = from._ideas[i];
		}
	}
	return *this;
}
