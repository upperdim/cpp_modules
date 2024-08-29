/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 04:52:39 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 05:13:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define CHAR_INV_SIZE 4

class Character : public ICharacter {
private:
	std::string	_name;
	AMateria *_inventory[CHAR_INV_SIZE];
	int _inventoryItemCount;
public:
	Character();
	Character(std::string const & name);
	Character(const Character &from);
	virtual ~Character();
	Character& operator=(const Character &from);

	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
