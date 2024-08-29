/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 05:36:45 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 05:53:57 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

#define MAT_SRC_INV_SIZE 4

class MateriaSource : public IMateriaSource {
private:
	AMateria *_inventory[MAT_SRC_INV_SIZE];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &from);
	virtual ~MateriaSource();
	MateriaSource& operator=(const MateriaSource &from);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif
