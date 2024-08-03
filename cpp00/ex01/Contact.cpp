/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:57:15 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/03 12:42:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

Contact::Contact() {
	
}

Contact::~Contact() {
	
}

std::string Contact::getName()          {return this->name;}
std::string Contact::getSurname()       {return this->surname;}
std::string Contact::getNickname()      {return this->nickname;}
std::string Contact::getPhoneNumber()   {return this->phoneNumber;}
std::string Contact::getDarkestSecret() {return this->darkestSecret;}

void Contact::setName(std::string name)                   {this->name = name;}
void Contact::setSurname(std::string surname)             {this->surname = surname;}
void Contact::setNickname(std::string nickname)           {this->nickname = nickname;}
void Contact::setPhoneNumber(std::string phoneNumber)     {this->phoneNumber = phoneNumber;}
void Contact::setDarkestSecret(std::string darkestSecret) {this->darkestSecret = darkestSecret;}
