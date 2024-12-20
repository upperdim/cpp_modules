/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:03:29 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/08 05:13:07 by tunsal           ###   ########.fr       */
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

	bool checkInt(std::string input);
	bool checkFloat(std::string input);
	bool checkDouble(std::string input);
	
	void handleChar(std::string input);
	void handleInt(std::string input);
	void handleFloat(std::string input);
	void handleDouble(std::string input);
	
	bool printIfPseudo(std::string input);

	bool isValidNumber(std::string input);
	bool strContainsChar(const std::string& str, char ch);
	long double parseToLongDouble(std::string input);
public:
	static void convert(std::string input);
};

#endif
