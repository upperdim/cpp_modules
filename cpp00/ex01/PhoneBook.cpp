/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:47:08 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/03 14:48:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <PhoneBook.hpp>

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

std::string PhoneBook::inputField(std::string fieldName) {
	std::string field;
	bool valid_input = false;
	
	while (valid_input == false) {
		std::cout << fieldName << ": ";
		std::cin >> field;
		
		if (field.empty()) {
			std::cout << "Invalid input, " << fieldName << " cannot be empty." << std::endl;
		} else {
			valid_input = true;
		}
	}
	
	return field;
}

void PhoneBook::add() {
	int newContactIndex = (this->topContactIndex + 1) % NUM_CONTACTS;
	
	this->contacts[newContactIndex].setName(inputField("Name"));
	this->contacts[newContactIndex].setSurname(inputField("Surname"));
	this->contacts[newContactIndex].setNickname(inputField("Nickname"));
	this->contacts[newContactIndex].setPhoneNumber(inputField("PhoneNumber"));
	this->contacts[newContactIndex].setDarkestSecret(inputField("DarkestSecret"));
	
	this->topContactIndex = newContactIndex;
}

void PhoneBook::search() {}



