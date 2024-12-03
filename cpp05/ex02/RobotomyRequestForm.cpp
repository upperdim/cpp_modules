/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:44:13 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/03 15:55:23 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RobotomyRequestForm.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Form
// -----------------------------------------------------------------------------
RobotomyRequestForm::RobotomyRequestForm() : 
AForm("Robotomy Request Form", ROBOTOMYREQUESTFORM_DEFAULT_REQ_GRADE_SIGN, ROBOTOMYREQUESTFORM_DEFAULT_REQ_GRADE_EXEC),
_target("defaultTarget") {
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("Robotomy Request Form", ROBOTOMYREQUESTFORM_DEFAULT_REQ_GRADE_SIGN, ROBOTOMYREQUESTFORM_DEFAULT_REQ_GRADE_EXEC),
	_target(target) {
	std::cout << "RobotomyRequestForm created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & from) :
AForm(from),
_target(from._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = from;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

// -----------------------------------------------------------------------------
// Member functions
// -----------------------------------------------------------------------------
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	executionChecks(executor);
	std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
}
