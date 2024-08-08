/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:13:36 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/08 15:19:19 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Allocate and create an array of zombies on heap memory
Zombie* zombieHorde(int N, std::string name) {
	Zombie *zombieArr = new Zombie[N];
	
	for (int i = 0; i < N; ++i) {
		zombieArr[i].setName(name);
	}

	return zombieArr;
}
