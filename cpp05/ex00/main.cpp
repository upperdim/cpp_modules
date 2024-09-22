/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 20:43:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/22 20:49:28 by tunsal           ###   ########.fr       */
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
	}

	Bureaucrat low = Bureaucrat("Low", GRADE_LOWEST);
	try {
		low.decrementGrade();
	} catch (std::exception & e) {
		std::cout << "Catched exception of following bureaucrat:" << std::endl;
		std::cout << low << std::endl << "Exception = " << e.what() << std::endl;
	}
}
