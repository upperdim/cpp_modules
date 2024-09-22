/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:21:41 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/22 13:54:08 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Name") {
	std::cout << "Bureaucrat created" << std::endl;
	this->_grade = GRADE_DEFAULT;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
	std::cout << "Bureaucrat created" << std::endl;
	if (grade < GRADE_LOWEST) {
		// TODO: throw an exception
	} else if (grade > GRADE_HIGHEST) {
		// TODO: throw an exception
	}
	this->_grade = grade;
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
	this->_grade--;
}

// Decrements grade, higher numeric values are lower grades
void Bureaucrat::decrementGrade() {
	this->_grade++;
}

std::string Bureaucrat::getName() {
	return this->_name;
}

unsigned int Bureaucrat::getGrade() {
	return this->_grade;
}
