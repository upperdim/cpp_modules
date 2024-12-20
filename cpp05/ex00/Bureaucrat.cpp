/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:21:41 by tunsal            #+#    #+#             */
/*   Updated: 2024/10/23 18:59:42 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Name") {
	std::cout << "Bureaucrat created" << std::endl;
	this->_grade = GRADE_DEFAULT;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
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

std::string Bureaucrat::getName() const {
	return this->_name;
}

unsigned int Bureaucrat::getGrade() const {
	return this->_grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low.";
}

// Non member functions
std::ostream& operator<<(std::ostream& output, Bureaucrat const &toPrint) {
	output << toPrint.getName() << ", bureaucrat grade " << toPrint.getGrade() << ".";
	return output;
}
