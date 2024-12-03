/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:44:00 by tunsal            #+#    #+#             */
/*   Updated: 2024/11/21 17:57:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Form
// -----------------------------------------------------------------------------
AForm::AForm() :
_name("Default Name"), 
_isSigned(false),
_requiredGradeToSign(GRADE_LOWEST), 
_requiredGradeToExecute(GRADE_LOWEST) {
	std::cout << "AForm created" << std::endl;
}

AForm::AForm(std::string name, unsigned int requiredGradeToSign, unsigned int requiredGradeToExecute) :
_name(name),
_isSigned(false),
_requiredGradeToSign(requiredGradeToSign),
_requiredGradeToExecute(requiredGradeToExecute) {
	// Higher numeric values are lower grades, lower numeric values are higher grades
	if (requiredGradeToSign > GRADE_LOWEST || requiredGradeToExecute > GRADE_LOWEST) {
		throw AForm::GradeTooLowException();
	} else if (requiredGradeToSign < GRADE_HIGHEST || requiredGradeToExecute < GRADE_HIGHEST) {
		throw AForm::GradeTooHighException();
	}
	std::cout << "AForm created" << std::endl;
}

AForm::AForm(const AForm & from) :
_name(from._name),
_requiredGradeToSign(from._requiredGradeToSign),
_requiredGradeToExecute(from._requiredGradeToExecute) {
	std::cout << "AForm copy constructor called" << std::endl;
	*this = from;
}

AForm::~AForm() {
	std::cout << "AForm destroyed" << std::endl;
}

AForm &AForm::operator=(AForm const & rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
		// const fields CANNOT be assigned, leaving them alone.
	}
	return *this;
}

// -----------------------------------------------------------------------------
// Member functions
// -----------------------------------------------------------------------------
void AForm::beSigned(Bureaucrat bureaucrat) {
	// Higher numeric values are lower grades
	if (bureaucrat.getGrade() > this->_requiredGradeToSign) {
		throw Bureaucrat::GradeTooLowException();
	}
	
	this->_isSigned = true;
}

void AForm::executionChecks(Bureaucrat const & executor) const {
	if (!this->getIsSigned()) {
		throw AForm::NotSignedException();
	}
	if (executor.getGrade() > this->getRequiredGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
}

// -----------------------------------------------------------------------------
// Getters & Setters
// -----------------------------------------------------------------------------
std::string AForm::getName() const {
	return this->_name;
}

bool AForm::getIsSigned() const {
	return this->_isSigned;
}

unsigned int AForm::getRequiredGradeToSign() const {
	return this->_requiredGradeToSign;
}

unsigned int AForm::getRequiredGradeToExecute() const {
	return this->_requiredGradeToExecute;
}

// -----------------------------------------------------------------------------
// Exceptions
// -----------------------------------------------------------------------------
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high.";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low.";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed.";
}

// -----------------------------------------------------------------------------
// Non member functions
// -----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& output, AForm const &toPrint) {
	output
	<< "AForm name " << toPrint.getName() 
	<< (toPrint.getIsSigned() ? ", SIGNED, " : ", NOT SIGNED, ") 
	<< "Required grade to sign = " << toPrint.getRequiredGradeToSign()
	<< ", Required grade to execute = " << toPrint.getRequiredGradeToExecute()
	<< ".";
	return output;
}
