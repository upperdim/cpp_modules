/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:31 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/09 19:53:29 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

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
	int lvl = -1;
	
	// bad code ikr
	if      (level == "debug")   { lvl = 0; }
	else if (level == "info")    { lvl = 1; }
	else if (level == "warning") { lvl = 2; }
	else if (level == "error")   { lvl = 3; }
	else                         { return;  }
	
	void (Harl::*funcPtrs[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i <= lvl; ++i) {
		(this->*funcPtrs[i])();
	}
}
