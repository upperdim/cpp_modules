/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:32:47 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 03:45:08 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include <string>
#include "AMateria.hpp"

class Cure : public AMateria {
private:

public:
	Cure();
	Cure(Cure const &from);
	~Cure();
	Cure& operator=(Cure const & from);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif