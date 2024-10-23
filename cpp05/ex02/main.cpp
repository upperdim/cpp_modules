/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:43:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/10/23 19:35:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	std::string attemptedName = "Attempted Name";
	try {
		Form low = Form(attemptedName, GRADE_LOWEST + 1, GRADE_LOWEST);
	} catch (std::exception & e) {
		std::cout << "Exception when creating " << attemptedName << ":" << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}

	try {
		Form low = Form(attemptedName, GRADE_LOWEST, GRADE_LOWEST + 1);
	} catch (std::exception & e) {
		std::cout << "Exception when creating " << attemptedName << ":" << std::endl;
		std::cout << e.what() << std::endl << std::endl;
	}

	Bureaucrat lowBureaucrat = Bureaucrat("Low Bureaucrat", GRADE_LOWEST);
	Form midForm = Form("Mid Form", (GRADE_LOWEST - GRADE_HIGHEST) / 2, (GRADE_LOWEST - GRADE_HIGHEST) / 2);
	Bureaucrat highBureaucrat = Bureaucrat("High Bureaucrat", GRADE_HIGHEST);

	std::cout << midForm << std::endl;
	lowBureaucrat.signForm(midForm);
	std::cout << midForm << std::endl;
	highBureaucrat.signForm(midForm);
	std::cout << midForm << std::endl;
	highBureaucrat.signForm(midForm);
	
}
