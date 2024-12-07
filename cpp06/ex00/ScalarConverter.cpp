/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:03:31 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/07 19:14:20 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Form
// -----------------------------------------------------------------------------
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const & from) { (void) from; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(ScalarConverter const & rhs) {
	(void) rhs;
	return (*this);
}

// -----------------------------------------------------------------------------
// Member functions
// -----------------------------------------------------------------------------
void ScalarConverter::convert(std::string input) {
	ScalarConverter converter;

	if (input.length() == 0) {
		std::cout << "Invalid input, empty string." << std::endl;
	} else if (input.length() == 1 && !std::isdigit(input[0]) && std::isprint(input[0])) {
		converter.printResult(input); // char
	} else if(converter.printIfPseudo(input)) {
		;
	} else {
		if (!converter.isValidNumber(input)) {
			return; // error message is printed in the function
		}
		
		if (converter.strContainsChar(input, 'f') || converter.strContainsChar(input, 'F')) {
			if (converter.isValidFloat(input))
				converter.printResult(input);
		} else if (converter.strContainsChar(input, '.')) {
			if (converter.isValidDouble(input))
				converter.printResult(input);
		} else {
			if (converter.isValidInt(input))
				converter.printResult(input);
		}
	}
}

bool ScalarConverter::printIfPseudo(std::string input) {
	if (input == "-inf" || input == "+inf" || input == "inf" || input == "nan") {
		// double
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return true;
	} else if (input == "-inff" || input == "+inff" || input == "inff" || input == "nanf") {
		// float
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		return true;
	}
	return false;
}

bool ScalarConverter::isValidNumber(std::string input) {
	if (!isdigit(input[0]) && input[0] != '+' && input[0] != '-' && input[0] != '.') {
		std::cout << "Invalid input, invalid character." << std::endl;
		return false;
	}
	
	// Only a single dot or 'f' is allowed
	int dot_count = input[0] == '.' ? 1 : 0;
	int f_count = 0;
	
	for (size_t i = 1; i < input.length(); ++i) {
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

bool ScalarConverter::strContainsChar(const std::string& str, char ch) {
    return str.find(ch) != std::string::npos;
}

void ScalarConverter::printResult(std::string input) {
	long double input_num = 0;
	try {
		input_num = std::stold(input);
	} catch (std::exception e) {
		std::cout << "Invalid input: " << e.what();
	}

	// Print char
	if (input_num < std::numeric_limits<char>::min() || input_num > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(input_num)))
		std::cout << "char: Not displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(input_num) << "'" << std::endl;
	
	// Print int
	if (input_num < std::numeric_limits<int>::min() || input_num > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(input_num) << std::endl;

	// Print float
	if (input_num > std::numeric_limits<float>::max() || input_num < std::numeric_limits<float>::lowest())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << input_num << "f" << std::endl;
	
	// Print double
	if (input_num > std::numeric_limits<double>::max() || input_num < std::numeric_limits<double>::lowest())
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << input_num << std::endl;
}

bool ScalarConverter::isValidFloat(std::string input) {
	float input_num = 0;
	try {
		input_num = std::stof(input);
	} catch (std::exception e) {
		std::cout << "Invalid input: " << e.what();
		return false;
	}
	return true;
}

bool ScalarConverter::isValidDouble(std::string input) {
	double input_num = 0;
	try {
		input_num = std::stod(input);
	} catch (std::exception e) {
		std::cout << "Invalid input: " << e.what();
		return false;
	}
	return true;
}

bool ScalarConverter::isValidInt(std::string input) {
	int input_num = 0;
	try {
		input_num = std::stoi(input);
	} catch (std::exception e) {
		std::cout << "Invalid input: " << e.what();
		return false;
	}
	return true;
}
