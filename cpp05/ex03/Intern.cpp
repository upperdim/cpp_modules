/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:27:54 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/04 12:49:09 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Form
// -----------------------------------------------------------------------------
Intern::Intern() {
	std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern & from) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void) from;
}

Intern::~Intern() {
	std::cout << "Intern destroyed" << std::endl;
}

Intern &Intern::operator=(Intern const & rhs) {
	(void) rhs;
	return *this;
}

// -----------------------------------------------------------------------------
// Member functions
// -----------------------------------------------------------------------------

AForm* Intern::createPresidentialPardonForm(std::string formTarget) {
	return (new PresidentialPardonForm(formTarget));
}

AForm* Intern::createRobotomyRequestForm(std::string formTarget) {
	return (new RobotomyRequestForm(formTarget));
}

AForm* Intern::createShrubberyCreationForm(std::string formTarget) {
	return (new ShrubberyCreationForm(formTarget));
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
	std::string formNames[] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	
	AForm* (Intern::*funcPtrs[])(std::string) = {
		&Intern::createPresidentialPardonForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createShrubberyCreationForm
	};
	
	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*funcPtrs[i])(formTarget);
		}
	}
	std::cout << "Intern failed to create form. Form name \"" << formName << "\" not found." << std::endl;
	return NULL;
}
