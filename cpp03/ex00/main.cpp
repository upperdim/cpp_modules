/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:54:44 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/20 07:26:33 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

static void printHeader(std::string header) {
	std::cout                                                   << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << header                                         << std::endl;
	std::cout << "============================================" << std::endl;
}

int main() {
	printHeader("Constructors, assignment, destructor");
	{
		ClapTrap n = ClapTrap();
		ClapTrap j = ClapTrap("Joe");
		
		ClapTrap j_cpy = ClapTrap(j);
		std::cout << "j_cpy name  = " << j_cpy.getName() << std::endl;
		
		// TODO: why does this call Copy constructor before copy assignment operator?
		ClapTrap j_cpy2 = j_cpy;
		std::cout << "j_cpy2 name = " << j_cpy2.getName() << std::endl;
	}

	// TODO: tests for
	// - attack, takeDamage, beRepaired
	// - insufficient energy, insufficient hitPoints
	// - takeDamage underflow protection, beRepaired overflow protection

	return 0;
}
