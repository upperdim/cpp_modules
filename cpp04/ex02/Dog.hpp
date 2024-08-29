/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:46:47 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/29 02:08:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
	Brain *_brain;
public:
	Dog();
	Dog(Dog const & src);
	~Dog();
	Dog& operator=(Dog const & rhs);

	void makeSound() const;
	Brain& getBrain();
};

#endif
