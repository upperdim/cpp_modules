/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:36:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/17 15:30:15 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, double>	_exchangeRates;

	void 			printDb();
	void			printMap(std::map<std::string, double> m);
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & other);
	BitcoinExchange& operator=(BitcoinExchange const & rhs);
	~BitcoinExchange();
	
	void			readDb(const std::string dbFilename);
	bool			validateDateStr(std::string date);
	double			getBitcoinValue(std::string date, double amount);
	std::string		getEarliestDate();
};

#endif
