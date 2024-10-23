/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:26:42 by tunsal            #+#    #+#             */
/*   Updated: 2024/10/23 18:45:47 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Notation
// -----------------------------------------------------------------------------
Form::Form() :
_name("Default Name"), 
_isSigned(false),
_requiredGradeToSign(GRADE_LOWEST), 
_requiredGradeToExecute(GRADE_LOWEST) {
	std::cout << "Form created" << std::endl;
}

Form::Form(std::string name, unsigned int requiredGradeToSign, unsigned int requiredGradeToExecute) :
_name(name),
_isSigned(false),
_requiredGradeToSign(requiredGradeToSign),
_requiredGradeToExecute(requiredGradeToExecute) {
	std::cout << "Form created" << std::endl;
	// Higher numeric values are lower grades, lower numeric values are higher grades
	if (requiredGradeToSign > GRADE_LOWEST || requiredGradeToExecute > GRADE_LOWEST) {
		throw Form::GradeTooLowException();
	} else if (requiredGradeToSign < GRADE_HIGHEST || requiredGradeToExecute < GRADE_HIGHEST) {
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form & from) :
_name(from._name),
_requiredGradeToSign(from._requiredGradeToSign),
_requiredGradeToExecute(from._requiredGradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = from;
}

Form::~Form() {
	std::cout << "Form destroyed" << std::endl;
}

Form &Form::operator=(Form const & rhs) {
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
		// const fields CANNOT be assigned, leaving them alone.
	}
	return *this;
}

// -----------------------------------------------------------------------------
// Member functions
// -----------------------------------------------------------------------------
void Form::beSigned(Bureaucrat bureaucrat) {
	// Higher numeric values are lower grades
	if (bureaucrat.getGrade() > this->_requiredGradeToSign) {
		throw Bureaucrat::GradeTooLowException();
	}
	
	this->_isSigned = true;
}

// -----------------------------------------------------------------------------
// Getters & Setters
// -----------------------------------------------------------------------------
std::string Form::getName() const {
	return this->_name;
}

bool Form::getIsSigned() const {
	return this->_isSigned;
}

unsigned int Form::getRequiredGradeToSign() const {
	return this->_requiredGradeToSign;
}

unsigned int Form::getRequiredGradeToExecute() const {
	return this->_requiredGradeToExecute;
}

// -----------------------------------------------------------------------------
// Exceptions
// -----------------------------------------------------------------------------
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high.";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low.";
}

// -----------------------------------------------------------------------------
// Non member functions
// -----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& output, Form const &toPrint) {
	output
	<< "Form name " << toPrint.getName() 
	<< (toPrint.getIsSigned() ? ", SIGNED, " : ", NOT SIGNED, ") 
	<< "Required grade to sign = " << toPrint.getRequiredGradeToSign()
	<< ", Required grade to execute = " << toPrint.getRequiredGradeToExecute()
	<< ".";
	return output;
}
