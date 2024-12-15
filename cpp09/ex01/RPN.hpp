/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:43:07 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/15 23:19:39 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
private:
	RPN();
	RPN(const RPN & other);
	~RPN();
	RPN& operator=(const RPN & rhs);

	static int doOperation(int operand1, char operator_, int operand2);
public:
	static int solveRPN(std::string &rpnExpr);
};

#endif
