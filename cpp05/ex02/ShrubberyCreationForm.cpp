/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:44:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/03 16:00:03 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Form
// -----------------------------------------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm("Robotomy Request Form", SHRUBBERYCREATIONFORM_DEFAULT_REQ_GRADE_SIGN, SHRUBBERYCREATIONFORM_DEFAULT_REQ_GRADE_EXEC),
_target("defaultTarget") {
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("Robotomy Request Form", SHRUBBERYCREATIONFORM_DEFAULT_REQ_GRADE_SIGN, SHRUBBERYCREATIONFORM_DEFAULT_REQ_GRADE_EXEC),
	_target(target) {
	std::cout << "ShrubberyCreationForm created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & from) :
AForm(from),
_target(from._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = from;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

// -----------------------------------------------------------------------------
// Member functions
// -----------------------------------------------------------------------------
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	executionChecks(executor);
	// Create file <target>_shubbery in working directory
	
	// Write ASCII trees inside it
}
