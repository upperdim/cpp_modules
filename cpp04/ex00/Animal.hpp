/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:54:06 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/24 13:54:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
protected:
	std::string _type;
public:
	Animal();
	Animal(const Animal &from);
	~Animal();
	Animal& operator=(const Animal &from);

	std::string getType() const;
	virtual void makeSound() const;
};

#endif
