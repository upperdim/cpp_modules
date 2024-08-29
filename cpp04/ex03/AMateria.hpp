/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:12:51 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 06:29:12 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include "ICharacter.hpp"

class ICharacter; // circular dependency

class AMateria {
protected:
	std::string _type;
	AMateria();
public:
	AMateria(std::string const & type);
	AMateria(const AMateria &from);
	virtual ~AMateria();
	AMateria& operator=(const AMateria &from);

	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
