/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:03:29 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/07 18:08:41 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & from);
	~ScalarConverter();
	ScalarConverter& operator=(ScalarConverter const & rhs);

	
	bool printIfPseudo(std::string input);
	bool isValidNumber(std::string input);
	bool strContainsChar(const std::string& str, char ch);
	void printResult(std::string input);
	bool isValidFloat(std::string input);
	bool isValidDouble(std::string input);
	bool isValidInt(std::string input);
public:
	void convert(std::string input);
};

#endif
