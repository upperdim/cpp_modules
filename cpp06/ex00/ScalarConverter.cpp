/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:03:31 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/04 17:36:47 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Form
// -----------------------------------------------------------------------------
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & from) {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const & rhs) {}

// -----------------------------------------------------------------------------
// Member functions
// -----------------------------------------------------------------------------
void ScalarConverter::convert(std::string input) {
	if (input.length() == 0) {
		std::cout << "Invalid input, empty string." << std::endl;
	} else if (input.length() == 1 && !std::isdigit(input[0]) && std::isprint(input[0])) {
		printFromChar(input);
	} else if(printIfPseudo(input)) {
		;
	} else {
		if (!isValidNumber(input)) {
			return; // error message is printed in the function
		}
		
		if (strContainsChar(input, 'f') || strContainsChar(input, 'F')) {
			printFromFloat(input);
		} else if (strContainsChar(input, '.')) {
			printFromDouble(input);
		} else {
			printFromInt(input);
		}
	}
}

// -----------------------------------------------------------------------------
// Helper functions
// -----------------------------------------------------------------------------
bool printIfPseudo(std::string input) {
	if (input == "-inf" || input == "+inf" || input == "nan") {
		// double
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return true;
	} else if (input == "-inff" || input == "+inff" || input == "nanf") {
		// float
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		return true;
	}
	return false;
}

bool isValidNumber(std::string input) {
	if (!isdigit(input[0]) && input[0] != '+' && input[0] != '-' && input[0] != '.') {
		return false;
	}
	
	// Only a single dot or 'f' is allowed
	int dot_count = input[0] == '.' ? 1 : 0;
	int f_count = 0;
	
	for (int i = 1; i < input.length(); ++i) {
		if (input[i] == '.') {
			if (f_count > 0) {
				std::cout << "Invalid input, '.' encountered before 'f'." << std::endl;
				return false;
			}
			dot_count++;
			if (dot_count > 1) {
				std::cout << "Invalid input, multiple dots." << std::endl;
				return false;
			}
		}
		else if (input[i] == 'f' || input[0] == 'F') {
			f_count++;
			if (f_count > 1) {
				std::cout << "Invalid input, multiple 'f'." << std::endl;
				return false;
			}
		}
		else if (!isdigit(input[i])) {
			std::cout << "Invalid input, invalid character." << std::endl;
			return false;
		}
	}

	return true;
}

bool strContainsChar(const std::string& str, char ch) {
    return str.find(ch) != std::string::npos;
}

void printFromFloat(std::string input) {
	double finput = 0;
	try {
		finput = std::stod(input);
	} catch (std::exception e) {
		std::cout << "Invalid input: " << e.what();
		return;
	}
	// TODO: print
	// Print char
	if (finput < std::numeric_limits<char>::min() || finput > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(finput)))
		std::cout << "char: Not displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(finput) << std::endl;
	
	
	// Print int
	if (finput < std::numeric_limits<int>::min() || finput > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(finput) << std::endl;

	// Print float
	if (finput > std::numeric_limits<float>::max() || finput < std::numeric_limits<float>::lowest())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << finput << "f" << std::endl;
	
	// Print double
}

void printFromDouble(std::string input) {
	try {
		double dinput = std::stod(input);
	} catch (std::exception e) {
		std::cout << "Invalid input: " << e.what();
	}
	// TODO: print
}

void printFromInt(std::string input) {
	try {
		int iinput = std::stoi(input);
	} catch (std::exception e) {
		std::cout << "Invalid input: " << e.what();
	}
	// TODO: print
}

void printFromChar(std::string input) {
	// TODO
}
