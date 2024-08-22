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

class ScavTrap : ClapTrap {
private:
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &from);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap &from);
};

#endif
