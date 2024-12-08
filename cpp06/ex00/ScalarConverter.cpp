/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:03:31 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/08 21:27:59 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
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
	} else if (input.length() == 1 && std::isprint(input[0])) {
		converter.handleChar(input);
	} else if(converter.printIfPseudo(input)) {
		;
	} else {
		if (!converter.isValidNumber(input)) {
			return; // error message is printed in the function
		}
		
		if (converter.strContainsChar(input, 'f') || converter.strContainsChar(input, 'F')) {
			if (converter.checkFloat(input)) converter.handleFloat(input);
		} else if (converter.strContainsChar(input, '.')) {
			if (converter.checkDouble(input)) converter.handleDouble(input);
		} else {
			if (converter.checkInt(input)) converter.handleInt(input);
		}
	}
}

void ScalarConverter::handleChar(std::string input) {
	char charVal = input[0];
	
	std::cout << "char: " << charVal << std::endl;
	int intVal = static_cast<int>(charVal);
	std::cout << "int: " << intVal << std::endl;
	float floatVal = static_cast<float>(charVal);
	std::cout << "float: " << floatVal << (std::floor(floatVal) == floatVal ? ".0" : "") << "f" << std::endl;
	double doubleVal = static_cast<double>(charVal);
	std::cout << "double: " << doubleVal << (std::floor(doubleVal) == doubleVal ? ".0" : "") << std::endl;
}

bool ScalarConverter::checkInt(std::string input) {
	ScalarConverter converter;
	
	// Range check
	long double range_check = converter.parseToLongDouble(input);
	if (range_check < std::numeric_limits<int>::min() || range_check > std::numeric_limits<int>::max()) {
		// Int overflows
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		// Check if float overflows
		double floatVal;
		if (range_check > std::numeric_limits<double>::max() || range_check < std::numeric_limits<double>::lowest()) {
			std::cout << "double: impossible" << std::endl;
		} else {
			floatVal = static_cast<double>(range_check);
			std::cout << "double: " << floatVal << (std::floor(floatVal) == floatVal ? ".0" : "") << std::endl;
		}

		// Check if double overflows
		double doubleVal;
		if (range_check > std::numeric_limits<double>::max() || range_check < std::numeric_limits<double>::lowest()) {
			std::cout << "double: impossible" << std::endl;
		} else {
			doubleVal = static_cast<double>(range_check);
			std::cout << "double: " << doubleVal << (std::floor(doubleVal) == doubleVal ? ".0" : "") << std::endl;
		}
		return false;
	}
	return true;
}

void ScalarConverter::handleInt(std::string input) {
	// Int is valid, in range
	int intVal = 0;
	try {
		intVal = std::stoi(input);
	} catch (std::exception& e) {
		std::cout << "Invalid input: " << e.what() << std::endl;
	}

	// char
	char charVal = 0;
	if (intVal < std::numeric_limits<char>::min() || intVal > std::numeric_limits<char>::max()) {
		std::cout << "char: impossible" << std::endl;
	} else {
		charVal = static_cast<char>(intVal);
		
		if (!std::isprint(charVal)) {
			std::cout << "char: Not displayable" << std::endl;
		} else {
			std::cout << "char: '" << charVal << "'" << std::endl;
		}
	}

	// int
	std::cout << "int: " << intVal << std::endl;
	
	// float -- no range check. if it can fit float, it can fit double
	float floatVal = static_cast<float>(intVal);
	std::cout << "float: " << floatVal << (std::floor(floatVal) == floatVal ? ".0" : "") << "f" << std::endl;
	
	// double -- no range check. if it can fit int, it can fit double
	double doubleVal = static_cast<double>(intVal);
	std::cout << "double: " << doubleVal << (std::floor(doubleVal) == doubleVal ? ".0" : "") << std::endl;
}

bool ScalarConverter::checkFloat(std::string input) {
	ScalarConverter converter;
	
	// Range check
	long double range_check = converter.parseToLongDouble(input);
	if (range_check > std::numeric_limits<float>::max() || range_check < std::numeric_limits<float>::lowest()) {
		// Float overflows
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		
		// Check if double overflows
		double doubleVal;
		if (range_check > std::numeric_limits<double>::max() || range_check < std::numeric_limits<double>::lowest()) {
			std::cout << "double: impossible" << std::endl;
		} else {
			doubleVal = static_cast<double>(range_check);
			std::cout << "double: " << doubleVal << (std::floor(doubleVal) == doubleVal ? ".0" : "") << std::endl;
		}
		return false;
	}
	return true;
}
	
void ScalarConverter::handleFloat(std::string input) {
	// Float is valid, in range
	float floatVal = 0;
	try {
		floatVal = std::stof(input);
	} catch (std::exception& e) {
		std::cout << "Invalid input: " << e.what() << std::endl;
	}
	
	// char
	char charVal = 0;
	if (floatVal < std::numeric_limits<char>::min() || floatVal > std::numeric_limits<char>::max()) {
		std::cout << "char: impossible" << std::endl;
	} else {
		charVal = static_cast<char>(floatVal);
		
		if (!std::isprint(charVal)) {
			std::cout << "char: Not displayable" << std::endl;
		} else {
			std::cout << "char: '" << charVal << "'" << std::endl;
		}
	}
	
	// int
	if (floatVal < std::numeric_limits<int>::min() || floatVal > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		int intVal = static_cast<int>(floatVal);
		std::cout << "int: " << intVal << std::endl;
	}

	// float
	std::cout << "float: " << floatVal << (std::floor(floatVal) == floatVal ? ".0" : "") << "f" << std::endl;
	
	// double -- no range check. if it can fit float, it can fit double
	double doubleVal = static_cast<double>(floatVal);
	std::cout << "double: " << doubleVal << (std::floor(doubleVal) == doubleVal ? ".0" : "") << std::endl;
}

bool ScalarConverter::checkDouble(std::string input) {
	ScalarConverter converter;
	
	// Range check
	long double range_check = converter.parseToLongDouble(input);
	if (range_check > std::numeric_limits<double>::max() || range_check < std::numeric_limits<double>::lowest()) {
		// Double overflows
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return false;
	}
	return true;
}
	
void ScalarConverter::handleDouble(std::string input) {
	// Double is valid, in range
	double doubleVal = 0;
	try {
		doubleVal = std::stod(input);
	} catch (std::exception& e) {
		std::cout << "Invalid input: " << e.what() << std::endl;
	}
	
	// char
	char charVal = 0;
	if (doubleVal < std::numeric_limits<char>::min() || doubleVal > std::numeric_limits<char>::max()) {
		std::cout << "char: impossible" << std::endl;
	} else {
		charVal = static_cast<char>(doubleVal);
		
		if (!std::isprint(charVal)) {
			std::cout << "char: Not displayable" << std::endl;
		} else {
			std::cout << "char: '" << charVal << "'" << std::endl;
		}
	}
	
	// int
	if (doubleVal < std::numeric_limits<int>::min() || doubleVal > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
	} else {
		int intVal = static_cast<int>(doubleVal);
		std::cout << "int: " << intVal << std::endl;
	}

	// float
	if (doubleVal > std::numeric_limits<float>::max() || doubleVal < std::numeric_limits<float>::lowest())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << doubleVal << (std::floor(doubleVal) == doubleVal ? ".0" : "") << "f" << std::endl;

	// double
	std::cout << "double: " << doubleVal << (std::floor(doubleVal) == doubleVal ? ".0" : "") << std::endl;
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
	if (input.length() == 1 && !isdigit(input[0])) {
		std::cout << "Invalid input, invalid character." << std::endl;
		return false;
	} else if (input.length() > 1 && !isdigit(input[0]) && input[0] != '+' && input[0] != '-' && input[0] != '.') {
		std::cout << "Invalid input, invalid character." << std::endl;
		return false;
	}
	
	// Only a single dot or 'f' is allowed
	int dot_count = input[0] == '.' ? 1 : 0;
	int f_count = 0;
	
	for (size_t i = 1; i < input.length(); ++i) {
		if (f_count > 0) {
			std::cout << "Invalid input, characters encountered after 'f'." << std::endl;
			return false;
		} else if (input[i] == '.') {
			if (f_count > 0) {
				std::cout << "Invalid input, 'f' encountered before the dot." << std::endl;
				return false;
			}
			dot_count++;
			if (dot_count > 1) {
				std::cout << "Invalid input, multiple dots." << std::endl;
				return false;
			}
		} else if (input[i] == 'f' || input[i] == 'F') {
			f_count++;
			if (f_count > 1) {
				std::cout << "Invalid input, multiple 'f'." << std::endl;
				return false;
			}
		} else if (!isdigit(input[i])) {
			std::cout << "Invalid input, invalid character." << std::endl;
			return false;
		}
	}

	if (dot_count == 1 && f_count == 1 && input.length() == 2) {
		std::cout << "Invalid input, no digits encountered." << std::endl;
		return false;
	}

	return true;
}

long double ScalarConverter::parseToLongDouble(std::string input) {
	long double range_check = 0;
	try {
		range_check = std::stold(input);
	} catch (std::exception& e) {
		std::cout << "Invalid input: " << e.what() << std::endl;
	}
	return range_check;
}

bool ScalarConverter::strContainsChar(const std::string& str, char ch) {
    return str.find(ch) != std::string::npos;
}
