/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:36:24 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/17 00:49:43 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float>
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const & other);
	BitcoinExchange& operator=(BitcoinExchange const & rhs);
	~BitcoinExchange();
public:
};

#endif
