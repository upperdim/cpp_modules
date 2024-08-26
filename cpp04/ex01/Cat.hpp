/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:54:12 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/26 15:21:17 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain *_brain;
public:
	Cat();
	Cat(Cat const &from);
	~Cat();
	Cat& operator=(Cat const & rhs);

	void makeSound() const;
};

#endif
