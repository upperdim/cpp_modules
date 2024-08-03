/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:47:08 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/03 17:26:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {this->topContactIndex = -1;}
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

// Reserve 10 characters of space
// Align to the right
// Replace last character with '.' if longer than 10 chars
// Print the field, and a '|' afterwards
void PhoneBook::printField(std::string field) {
	if (field.length() > 10) {
		field.resize(10);
		field[9] = '.';
	}

	std::cout << std::setw(10) << field;
	std::cout << "|";
}

void PhoneBook::search() {
	if (this->contacts[0].isEmpty()) {
		std::cout << "No contacts" << std::endl;
		return;
	}

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	
	// Print each contact
	for (int i = 0; i < NUM_CONTACTS; ++i) {
		if (this->contacts[i].isEmpty())
			break;
		
		std::cout << "|";
		printField(std::to_string(i));
		printField(this->contacts[i].getName());
		printField(this->contacts[i].getSurname());
		printField(this->contacts[i].getNickname());
		std::cout << std::endl<< "+----------+----------+----------+----------+" << std::endl;
	}

	// Print a detailed one
	int index;
	bool valid_input = false;
	while (valid_input == false) {
		std::string indexStr;
		std::cout << "Please enter index of the contact: ";
		std::cin >> indexStr;
		
		if (indexStr.length() != 1
			|| !isdigit(indexStr[0])
			|| indexStr[0] - '0' >= NUM_CONTACTS
			|| this->contacts[indexStr[0] - '0'].isEmpty()) {
			std::cout << "Invalid input." << std::endl;
		} else {
			index = indexStr[0] - '0';
			valid_input = true;
		}
	}
	
	this->contacts[index].print();
}
