/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:28:20 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/08 15:36:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main() {
	std::string s = "HI THIS IS BRAIN";

	std::string *stringPTR = &s;
	std::string &stringREF = s;

	std::cout << "Memory address of the string variable = " << &s << std::endl;
	std::cout << "Memory address held by the stringPTR  = " << stringPTR << std::endl;
	std::cout << "Memory address held by the stringREF  = " << &stringREF << std::endl;
	// Reference is an alias of a variable, it doesn't exist in the memory in the runtime.
	// Therefore it doesn't have its own address.
	// Address of the reference is the same as address of the variable it points to.

	std::cout << std::endl;

	std::cout << "Value of the string variable = " << s << std::endl;
	std::cout << "Value pointed by stringPTR   = " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF   = " << stringREF << std::endl;
}
