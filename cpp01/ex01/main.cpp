/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:13:44 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/08 15:22:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
	const int N = 5;

	Zombie *zombieArr = zombieHorde(N, "NPC Zombie");

	for (int i = 0; i < N; ++i) {
		zombieArr[i].announce();
	}

	delete [] zombieArr;
}
