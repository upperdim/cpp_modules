/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:43:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/04 12:49:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Intern i = Intern();

	AForm *pardonForm = i.makeForm("presidential pardon", "pardon target");
	AForm *robotomyForm = i.makeForm("robotomy request", "robotomy target");
	AForm *creationForm = i.makeForm("shrubbery creation", "shrubbery_target");
	AForm *nonExisting = i.makeForm("skidi ki pap pap ", "pu pu pudrrr boom");
	
	delete pardonForm;
	delete robotomyForm;
	delete creationForm;
	(void) nonExisting;
}
