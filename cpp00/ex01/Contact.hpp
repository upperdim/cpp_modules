/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 11:57:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/03 12:39:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	Contact();
	~Contact();

	std::string getName();
	std::string getSurname();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
	
	void setName(std::string name);
	void setSurname(std::string surname);
	void setNickname(std::string nickname);
	void setPhoneNumber(std::string phoneNumber);
	void setDarkestSecret(std::string darkestSecret);
};

#endif
