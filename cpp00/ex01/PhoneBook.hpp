/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:47:07 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/03 14:47:05 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define NUM_CONTACTS 8

class PhoneBook {
private:
	Contact contacts[NUM_CONTACTS];
	int topContactIndex; // index of the contact that was added last
	std::string inputField(std::string fieldName); // get an input for a field
public:
	PhoneBook();
	~PhoneBook();
	void add();
	void search();
};

#endif
