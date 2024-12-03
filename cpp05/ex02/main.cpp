/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:43:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/03 19:30:46 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static void printHeader(std::string header) {
	std::cout                                                   << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << header                                         << std::endl;
	std::cout << "============================================" << std::endl;
}

void pardonFormTests() {
	printHeader("Presidential Pardon Form tests");
	
	PresidentialPardonForm pardonForm = PresidentialPardonForm("pardon_target"); // exec:   5, sign: 25
	Bureaucrat low = Bureaucrat("low", 30); // can't exec or sign
	Bureaucrat mid = Bureaucrat("mid", 15); // can't exec, can sign
	Bureaucrat high = Bureaucrat("high", 1); // can't exec, can sign

	low.signForm(pardonForm);
	low.executeForm(pardonForm);

	mid.signForm(pardonForm);
	mid.executeForm(pardonForm);

	high.signForm(pardonForm);
	high.executeForm(pardonForm);
}

void robotomyFormTests() {
	printHeader("Robotomy Request Form tests");
	
	RobotomyRequestForm robotomyForm = RobotomyRequestForm("robotomy_target");   // exec:  45, sign: 72
	Bureaucrat low = Bureaucrat("low", 75); // can't exec or sign
	Bureaucrat mid = Bureaucrat("mid", 55); // can't exec, can sign
	Bureaucrat high = Bureaucrat("high", 30); // can't exec, can sign

	low.signForm(robotomyForm);
	low.executeForm(robotomyForm);

	mid.signForm(robotomyForm);
	mid.executeForm(robotomyForm);

	high.signForm(robotomyForm);
	high.executeForm(robotomyForm);
}

void creationFormTests() {
	printHeader("Shrubbery Creation Form tests");
	
	ShrubberyCreationForm creationForm = ShrubberyCreationForm("creationForm");  // exec: 137, sign: 145
	Bureaucrat low = Bureaucrat("low", 147); // can't exec or sign
	Bureaucrat mid = Bureaucrat("mid", 139); // can't exec, can sign
	Bureaucrat high = Bureaucrat("high", 130); // can't exec, can sign

	low.signForm(creationForm);
	low.executeForm(creationForm);

	mid.signForm(creationForm);
	mid.executeForm(creationForm);

	high.signForm(creationForm);
	high.executeForm(creationForm);
}

int main() {
	pardonFormTests();
	robotomyFormTests();
	pardonFormTests();
}
