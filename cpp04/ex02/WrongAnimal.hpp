/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 03:18:49 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/25 03:18:49 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>

class WrongAnimal {
protected:
	std::string _type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &from);
	~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal &from);

	std::string getType() const;
	void makeSound() const; // supposed to be virtual but it's not for demonsteration
};

#endif
