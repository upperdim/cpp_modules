/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:43:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/10/23 17:22:27 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main() {
	Bureaucrat high = Bureaucrat("High", GRADE_HIGHEST);
	try {
		high.incrementGrade();
	} catch (std::exception & e) {
		std::cout << "Catched exception of following bureaucrat:" << std::endl;
		std::cout << high << std::endl << "Exception = " << e.what() << std::endl;
		std::cout << std::endl;
	}

	Bureaucrat low = Bureaucrat("Low", GRADE_LOWEST);
	try {
		low.decrementGrade();
	} catch (std::exception & e) {
		std::cout << "Catched exception of following bureaucrat:" << std::endl;
		std::cout << low << std::endl << "Exception = " << e.what() << std::endl;
		std::cout << std::endl;
	}

	try {
		Bureaucrat high = Bureaucrat("High", GRADE_HIGHEST - 1);
	} catch (std::exception & e) {
		std::cout << "Catched exception of following bureaucrat:" << std::endl;
		std::cout << high << std::endl << "Exception = " << e.what() << std::endl;
		std::cout << std::endl;
	}

	try {
		Bureaucrat low = Bureaucrat("Low", GRADE_LOWEST + 1);
	} catch (std::exception & e) {
		std::cout << "Catched exception of following bureaucrat:" << std::endl;
		std::cout << low << std::endl << "Exception = " << e.what() << std::endl;
		std::cout << std::endl;
	}
}