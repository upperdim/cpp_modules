/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 03:32:33 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 03:42:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include <string>
#include "AMateria.hpp"

class Ice : public AMateria {
private:

public:
	Ice();
	Ice(Ice const &from);
	~Ice();
	Ice& operator=(Ice const & from);

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
