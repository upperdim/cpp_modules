/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:31 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/18 23:46:25 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}
	
void Harl::debug(void) {
	std::cout << "debug msg" << std::endl;
}

void Harl::info(void) {
	std::cout << "info msg" << std::endl;
}

void Harl::warning(void) {
	std::cout << "warning msg" << std::endl;
}

void Harl::error(void) {
	std::cout << "error msg" << std::endl;
}

void Harl::complain(std::string level) {	
	void (Harl::*funcPtrs[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	const int LEVEL_COUNT = 4;
	std::string levels[LEVEL_COUNT] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int lvl = -1;

	for (int i = 0; i < LEVEL_COUNT; ++i) {
		if (levels[i] == level)
			lvl = i;
	}

	if (lvl < 0 || lvl >= LEVEL_COUNT) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return;
	}
	
	for (int i = lvl; i < LEVEL_COUNT; ++i) {
		(this->*funcPtrs[i])();
	}
}
