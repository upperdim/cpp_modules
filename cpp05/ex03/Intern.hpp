/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:27:57 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/04 12:28:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
private:
public:
	Intern();
	Intern(Intern const & from);
	~Intern();
	Intern& operator=(Intern const & rhs);

	AForm* createPresidentialPardonForm(std::string formTarget);
	AForm* createRobotomyRequestForm(std::string formTarget);
	AForm* createShrubberyCreationForm(std::string formTarget);
	AForm* makeForm(std::string formName, std::string formTarget);
};

#endif
