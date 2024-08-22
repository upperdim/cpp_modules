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
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

static void printHeader(std::string header) {
	std::cout                                                   << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << header                                         << std::endl;
	std::cout << "============================================" << std::endl;
}

static void legacyTests() {
	printHeader("Constructors, assignment, destructor");
	{
		ScavTrap n = ScavTrap();
		ScavTrap j = ScavTrap("Joe");
		
		ScavTrap j_cpy = ScavTrap(j);
		std::cout << "j_cpy name  = " << j_cpy.getName() << std::endl;
		
		ScavTrap j_cpy2 = j_cpy; // calls copy constructor too due to temporary compiler object
		std::cout << "j_cpy2 name = " << j_cpy2.getName() << std::endl;
	}

	printHeader("Attack, takeDamage, beRepaired, underflow, overflow");
	{
		ScavTrap felon = ScavTrap("Felon");
		
		felon.attack("victim");
		felon.takeDamage(2);
		felon.beRepaired(1);
	}

	printHeader("underflow, overflow");
	{
		ScavTrap victim = ScavTrap("Victim");
		
		victim.beRepaired(std::numeric_limits<unsigned int>::max());
		victim.beRepaired(std::numeric_limits<unsigned int>::max());
		
		victim.takeDamage(1000);
		victim.takeDamage(std::numeric_limits<unsigned int>::max());
	}

	printHeader("Insufficent energy");
	{
		ScavTrap tired = ScavTrap("Tired");

		for (int i = 0; i < ST_DEFAULT_ENERGYPOINTS + 1; ++i) {
			tired.attack("victim");
		}
	}
	
	printHeader("Insufficient hitpoints");
	{
		ScavTrap dead = ScavTrap("Dead");

		dead.takeDamage(ST_DEFAULT_HITPOINTS);
		dead.attack("Chicken");
	}
}

int main() {
	legacyTests();

	printHeader("Gate guarding");
	{
		ScavTrap s = ScavTrap("Guardian");

		s.guardGate();
		s.guardGate();
	}

	return 0;
}
