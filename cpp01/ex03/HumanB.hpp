/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:39:09 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/08 19:19:43 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
private:
	std::string _name;
	Weapon *_weaponPtr; // Weapon will be a pointer, HumanB will not always have a weapon
public:
	HumanB(std::string name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &weaponRef);
};

#endif
