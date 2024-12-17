/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:36:23 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/17 10:43:10 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	_exchangeRates = rhs._exchangeRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::validateDateStr(std::string date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
	}

	for (size_t i = 0; i < date.size(); ++i) {
		if ((i != 4 && i != 7) && !std::isdigit(date[i])) {
			return false;
		}
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12) {
		return false;
	}

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Handle if leap year
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		daysInMonth[1] = 29;
	}

	size_t monthIdx = month - 1;	
	if (day < 1 || day > daysInMonth[monthIdx]) {
		return false;
	}

	return true;
}

void BitcoinExchange::readDb(const std::string dbFilename) {
	std::ifstream file(dbFilename);
	if (!file) {
		throw std::runtime_error("Error opening database file!");
	}

	std::string line;

	// Skip the header line
	if (std::getline(file, line)) {
		if (line != "date,exchange_rate") {
			throw std::runtime_error("Incorrect database header!");
		}
	} else {
		throw std::runtime_error("Empty database file!");
	}

	size_t line_num = 1;
	// Read the rest of the file
	while (std::getline(file, line)) {
		++line_num;
		
		size_t delimiterPos = line.find(',');
		if (delimiterPos == std::string::npos) {
			throw std::runtime_error("Invalid line in database! line: " + std::to_string(line_num));
		}

		if (delimiterPos != std::string::npos) {
			std::string date = line.substr(0, delimiterPos);
			std::string rateStr = line.substr(delimiterPos + 1);

			if (!validateDateStr(date)) {
				throw std::runtime_error("Invalid date in database! line: " + std::to_string(line_num));
			}

			float exchangeRate = 0;
			try {
				// Convert rateStr to float
				exchangeRate = static_cast<float>(std::atof(rateStr.c_str()));
			} catch (std::exception & e) {
				throw std::runtime_error("Invalid exchange rate in database! line: " + std::to_string(line_num));
			}
			
			// Insert into map
			_exchangeRates[date] = exchangeRate;
		}
	}

	file.close();
}

void BitcoinExchange::printMap(std::map<std::string, float> m) {
	// Output the map content
	for (std::map<std::string, float>::iterator it = m.begin(); it != m.end(); ++it) {
		std::cout << "Date: " << it->first << ", Exchange Rate: " << it->second << std::endl;
	}
}

void BitcoinExchange::printDb() {
	printMap(_exchangeRates);
}

std::string BitcoinExchange::getEarliestDate() {
	std::map<std::string, float>::iterator it = _exchangeRates.begin();
	return it->first;
}

float BitcoinExchange::getBitcoinValue(std::string date, float amount) {    
    std::map<std::string, float>::reverse_iterator rit = _exchangeRates.rbegin();
    while (rit != _exchangeRates.rend() && rit->first > date) {
        ++rit;
    }
    
    if (rit == _exchangeRates.rend()) {
        throw std::runtime_error("Error: no suitable date found.");
    }
	
	return amount * rit->second;
}
