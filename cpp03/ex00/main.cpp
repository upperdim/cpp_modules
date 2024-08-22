/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:54:44 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/22 13:12:25 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
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
		
		ClapTrap j_cpy2 = j_cpy; // calls copy constructor too due to temporary compiler object
		std::cout << "j_cpy2 name = " << j_cpy2.getName() << std::endl;
	}

	printHeader("Attack, takeDamage, beRepaired, underflow, overflow");
	{
		ClapTrap felon = ClapTrap("Felon");
		
		felon.attack("victim");
		felon.takeDamage(2);
		felon.beRepaired(1);
	}

	printHeader("underflow, overflow");
	{
		ClapTrap victim = ClapTrap("Victim");
		
		victim.beRepaired(std::numeric_limits<unsigned int>::max());
		victim.beRepaired(std::numeric_limits<unsigned int>::max());
		
		victim.takeDamage(1000);
		victim.takeDamage(std::numeric_limits<unsigned int>::max());
	}

	printHeader("Insufficent energy");
	{
		ClapTrap tired = ClapTrap("Tired");

		for (int i = 0; i < CT_DEFAULT_ENERGYPOINTS + 1; ++i) {
			tired.attack("victim");
		}
	}
	
	printHeader("Insufficient hitpoints");
	{
		ClapTrap dead = ClapTrap("Dead");

		dead.takeDamage(CT_DEFAULT_HITPOINTS);
		dead.attack("Chicken");
	}

	return 0;
}
