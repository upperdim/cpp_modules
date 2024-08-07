/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 12:05:01 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/07 13:05:37 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int main() {
	PhoneBook phonebook;
	bool quit = false;

	while (quit == false) {
		std::string input;
		std::cout << "Please enter a command [ADD, SEARCH, EXIT]: ";
		std::getline(std::cin, input);

		if (input.compare("ADD") == 0) {
			phonebook.add();
		} else if (input.compare("SEARCH") == 0) {
			phonebook.search();
		} else if (input.compare("EXIT") == 0 || std::cin.eof()) {
			quit = true;
		} else {
			std::cout << "Invalid input." << std::endl;
		}
	}
}
