/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:36:22 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/17 06:12:46 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <input file>" << std::endl;
		return 0;
	}

	// Read csv file into a map
    BitcoinExchange bitcoinExchange;
    try {
        bitcoinExchange.readDb("data.csv");
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
    
    // Read input file
    std::string inputFileName = argv[1];
    std::ifstream file(inputFileName);
    if (!file) {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }

    std::string line;
    
    // Skip the header line
    if (std::getline(file, line)) {
        if (line != "date | value") {
			std::cout << "Warning: skipped an unexpected input header." << std::endl;
		}
    }

    // For each input file line
    while (std::getline(file, line)) {
        if (line.length() < 13 || line[10] != ' ' || line[11] != '|' || line[12] != ' ') {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Split
        size_t delimiterPos = line.find('|');
		if (delimiterPos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
            continue;
		}

        // Date
        std::string date = line.substr(0, delimiterPos - 1);
        if (!bitcoinExchange.validateDateStr(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Amount
        std::string amountStr = line.substr(delimiterPos + 1);
        float amount = 0;
        try {
            amount = static_cast<float>(std::atof(amountStr.c_str()));
        } catch (std::exception & e) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        if (amount < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        } else if (amount > 1000) {
            std::cout << "Error: too large number." << std::endl;
            continue;
        }
        
        // Calculate value and print
        float value = bitcoinExchange.getBitcoinValue(date, amount);
        std::cout << date << " => " << value << std::endl;
    }

    file.close();
    return 0;
}
