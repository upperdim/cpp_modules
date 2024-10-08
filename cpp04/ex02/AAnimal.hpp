/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:54:06 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 02:43:25 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

#include <string>

class AAnimal {
protected:
	std::string _type;
public:
	AAnimal();
	AAnimal(const AAnimal &from);
	virtual ~AAnimal();
	AAnimal& operator=(const AAnimal &from);

	std::string getType() const;
	virtual void makeSound() const = 0;
};

#endif
