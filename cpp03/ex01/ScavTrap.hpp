/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 06:31:50 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/21 06:49:46 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

#define ST_DEFAULT_HITPOINTS 100
#define ST_DEFAULT_ENERGYPOINTS 50
#define ST_DEFAULT_ATTACKDAMAGE 20

/*

Temporary for reference:

class ClapTrap {
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;

	bool hasResourcesFor(std::string action);
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &from);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap &from);
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;
	unsigned int getHitPoints() const;
	unsigned int getEnergyPoints() const;
	unsigned int getAttackDamage() const;
	
	void setName(std::string name);
	void setHitPoints(unsigned int hitPoints);
	void setEnergyPoints(unsigned int energyPoints);
	void setAttackDamage(unsigned int attackDamage);
};
*/

class ScavTrap : ClapTrap {
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
public:
	
};

#endif
