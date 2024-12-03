/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:43:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/11/14 14:48:36 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
	// AForm aform = AForm("aform name", 100, 100); // Cannot instantiate abstract class
	
	// std::string attemptedName = "Attempted Name";
	// try {
	// 	Form low = Form(attemptedName, GRADE_LOWEST + 1, GRADE_LOWEST);
	// } catch (std::exception & e) {
	// 	std::cout << "Exception when creating " << attemptedName << ":" << std::endl;
	// 	std::cout << e.what() << std::endl << std::endl;
	// }

	// try {
	// 	Form low = Form(attemptedName, GRADE_LOWEST, GRADE_LOWEST + 1);
	// } catch (std::exception & e) {
	// 	std::cout << "Exception when creating " << attemptedName << ":" << std::endl;
	// 	std::cout << e.what() << std::endl << std::endl;
	// }

	// Bureaucrat lowBureaucrat = Bureaucrat("Low Bureaucrat", GRADE_LOWEST);
	// Form midForm = Form("Mid Form", (GRADE_LOWEST - GRADE_HIGHEST) / 2, (GRADE_LOWEST - GRADE_HIGHEST) / 2);
	// Bureaucrat highBureaucrat = Bureaucrat("High Bureaucrat", GRADE_HIGHEST);

	// std::cout << midForm << std::endl;
	// lowBureaucrat.signForm(midForm);
	// std::cout << midForm << std::endl;
	// highBureaucrat.signForm(midForm);
	// std::cout << midForm << std::endl;
	// highBureaucrat.signForm(midForm);
	
}
