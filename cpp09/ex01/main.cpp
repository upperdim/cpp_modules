/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:43:03 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/16 00:02:42 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "RPN.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << "\"Reverse Polish Notation expression>\"" << std::endl;
		return 0;
	}
	
	std::string rpnExpr = argv[1];
	
	try {
		int result = RPN::solveRPN(rpnExpr);
		std::cout << result << std::endl;
	} catch (std::runtime_error& e) {
		std::cout << "Error" << std::endl;
	}
}
