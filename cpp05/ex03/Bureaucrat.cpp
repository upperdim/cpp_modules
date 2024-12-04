/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:21:41 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/03 15:49:17 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Form
// -----------------------------------------------------------------------------
Bureaucrat::Bureaucrat() : _name("Default Name") {
	std::cout << "Bureaucrat created" << std::endl;
	this->_grade = GRADE_DEFAULT;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	// Higher numeric values are lower grades, lower numeric values are higher grades
	if (grade > GRADE_LOWEST) {
		throw Bureaucrat::GradeTooLowException();
	} else if (grade < GRADE_HIGHEST) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade = grade;
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & from) : _name(from._name), _grade(from._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	// Doesn't call assignment operator overload.
	// Because const string field CANNOT be assigned, it can only be initialized.
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		this->_grade = rhs._grade;
		// const string field CANNOT be assigned, leaving it alone.
	}
	return *this;
}

// -----------------------------------------------------------------------------
// Member functions
// -----------------------------------------------------------------------------

// Increments grade, lower numeric values are higher grades
void Bureaucrat::incrementGrade() {
	if (this->_grade <= GRADE_HIGHEST) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

// Decrements grade, higher numeric values are lower grades
void Bureaucrat::decrementGrade() {
	if (this->_grade >= GRADE_LOWEST) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	if (form.getIsSigned()) {
		std::cout << "Form " << form.getName() << " is already signed." << std::endl;
		return;
	}

	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (GradeTooHighException &e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	} catch (GradeTooLowException &e) {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " could not execute " << form.getName() << ": " << e.what() << std::endl;
	}
}

// -----------------------------------------------------------------------------
// Getters & Setters
// -----------------------------------------------------------------------------
std::string Bureaucrat::getName() const {
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
}

// -----------------------------------------------------------------------------
// Exceptions
// -----------------------------------------------------------------------------
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low.";
}

// -----------------------------------------------------------------------------
// Non member functions
// -----------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& output, Bureaucrat const &toPrint) {
	output << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade() << ".";
	return output;
}
