/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:36:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/17 10:47:46 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float>	_exchangeRates;

	void 			printDb();
	void			printMap(std::map<std::string, float> m);
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & other);
	BitcoinExchange& operator=(BitcoinExchange const & rhs);
	~BitcoinExchange();
	
	void			readDb(const std::string dbFilename);
	bool			validateDateStr(std::string date);
	float			getBitcoinValue(std::string date, float amount);
	std::string		getEarliestDate();
};

#endif
