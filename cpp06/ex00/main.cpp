/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:35:18 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/07 18:12:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Usage: ./convert <number literal>" << std::endl;
		return 0;
	}

	ScalarConverter::convert(argv[1]);
	return 0;
}
