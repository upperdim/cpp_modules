/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:05:01 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/03 12:31:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

static void menu_add() {
	
}

static void menu_search() {
	
}

int main() {
	PhoneBook phonebook;
	bool quit = false;

	while (quit == false) {
		std::string input;
		std::cout << "Please enter a command [ADD, SEARCH, EXIT]: ";
		std::cin >> input;

		if (input.compare("ADD") == 0) {
			phonebook.showAddMenu();
		} else if (input.compare("SEARCH") == 0) {
			phonebook.showSearchMenu();
		} else if (input.compare("EXIT") == 0) {
			// TODO: Do necessary cleanups here
			quit = true;
		} else {
			std::cout << "Invalid input." << std::endl;
		}
	}
}
