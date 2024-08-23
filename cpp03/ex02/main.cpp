/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:54:44 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/21 06:45:48 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "FragTrap.hpp"

static void printHeader(std::string header) {
	std::cout                                                   << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << header                                         << std::endl;
	std::cout << "============================================" << std::endl;
}

static void legacyTests() {
	printHeader("Constructors, assignment, destructor");
	{
		FragTrap n = FragTrap();
		FragTrap j = FragTrap("Joe");
		
		FragTrap j_cpy = FragTrap(j);
		std::cout << "j_cpy name  = " << j_cpy.getName() << std::endl;
		
		FragTrap j_cpy2 = j_cpy; // calls copy constructor too due to temporary compiler object
		std::cout << "j_cpy2 name = " << j_cpy2.getName() << std::endl;
	}

	printHeader("Attack, takeDamage, beRepaired, underflow, overflow");
	{
		FragTrap felon = FragTrap("Felon");
		
		felon.attack("victim");
		felon.takeDamage(2);
		felon.beRepaired(1);
	}

	printHeader("underflow, overflow");
	{
		FragTrap victim = FragTrap("Victim");
		
		victim.beRepaired(std::numeric_limits<unsigned int>::max());
		victim.beRepaired(std::numeric_limits<unsigned int>::max());
		
		victim.takeDamage(1000);
		victim.takeDamage(std::numeric_limits<unsigned int>::max());
	}

	printHeader("Insufficent energy");
	{
		FragTrap tired = FragTrap("Tired");

		for (int i = 0; i < FT_DEFAULT_ENERGYPOINTS + 1; ++i) {
			tired.attack("victim");
		}
	}
	
	printHeader("Insufficient hitpoints");
	{
		FragTrap dead = FragTrap("Dead");

		dead.takeDamage(FT_DEFAULT_HITPOINTS);
		dead.attack("Chicken");
	}
}

int main() {
	legacyTests();

	printHeader("High five");
	{
		FragTrap s = FragTrap("F");

		s.highFivesGuys();
		s.highFivesGuys();
	}

	return 0;
}
