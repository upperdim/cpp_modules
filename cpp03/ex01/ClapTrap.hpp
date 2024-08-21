/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 05:54:40 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/21 06:41:59 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#define CT_DEFAULT_HITPOINTS 10
#define CT_DEFAULT_ENERGYPOINTS 10
#define CT_DEFAULT_ATTACKDAMAGE 0

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

#endif
