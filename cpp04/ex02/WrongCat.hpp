/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 03:18:39 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/25 03:18:39 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
private:
public:
	WrongCat();
	WrongCat(WrongCat const &from);
	~WrongCat();
	WrongCat& operator=(WrongCat const & rhs);

	void makeSound() const;
};

#endif
