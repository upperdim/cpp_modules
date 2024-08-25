/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 02:46:47 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/25 02:50:40 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include <string>
#include "Animal.hpp"

class Dog : public Animal {
private:
public:
	Dog();
	Dog(Dog const & src);
	~Dog();
	Dog& operator=(Dog const & rhs);
};

#endif
