/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:41:38 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/19 07:32:19 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN & other) { (void) other; }
RPN::~RPN() {}
RPN& RPN::operator=(const RPN & rhs) { (void) rhs; return *this; }

int RPN::doOperation(int operand1, char operator_, int operand2) {
	if (operator_ == '+') { return operand1 + operand2; }
	else if (operator_ == '-') { return operand1 - operand2; }
	else if (operator_ == '*') { return operand1 * operand2; }
	else if (operator_ == '/') {
		if (operand2 == 0) {
			throw std::runtime_error("Division by 0 in doOperation()");
		}
		return operand1 / operand2;
	} else {
		throw std::runtime_error("Invalid operator in doOperation()");
	}
}

int RPN::solveRPN(std::string &rpnExpr) {
	std::stack<int> solveStack;
	for (size_t i = 0; i < rpnExpr.length(); ++i) {
		char elem = rpnExpr[i];
		
		if (elem == ' ') {
			continue;
		} if (std::isdigit(elem)) {
			solveStack.push(elem - '0');
		} else if (elem == '+' || elem == '-' || elem == '*' || elem == '/') {
			if (solveStack.size() < 2) {
				throw std::runtime_error("Invalid expression");
			}
			int operand2 = solveStack.top();
			solveStack.pop();
			int operand1 = solveStack.top();
			solveStack.pop();
			
			try {
				solveStack.push(doOperation(operand1, elem, operand2));
			} catch (std::runtime_error& e) {
				throw e;
			}
		} else {
			throw std::runtime_error("Invalid character");
		}
	}
	
	int result = solveStack.top();
	solveStack.pop();

	if (!solveStack.empty()) {
		throw std::runtime_error("Invalid expression");
	}

	return result;
}
	