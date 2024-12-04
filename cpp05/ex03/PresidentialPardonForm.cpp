/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:44:07 by tunsal            #+#    #+#             */
/*   Updated: 2024/11/21 17:58:03 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Form
// -----------------------------------------------------------------------------
PresidentialPardonForm::PresidentialPardonForm() : 
AForm("Presidential Pardon Form", PRESPARDONFORM_DEFAULT_REQ_GRADE_SIGN, PRESPARDONFORM_DEFAULT_REQ_GRADE_EXEC),
_target("defaultTarget") {
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("Presidential Pardon Form", PRESPARDONFORM_DEFAULT_REQ_GRADE_SIGN, PRESPARDONFORM_DEFAULT_REQ_GRADE_EXEC),
	_target(target) {
	std::cout << "PresidentialPardonForm created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & from) :
AForm(from),
_target(from._target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = from;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

// -----------------------------------------------------------------------------
// Member functions
// -----------------------------------------------------------------------------
void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	executionChecks(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
