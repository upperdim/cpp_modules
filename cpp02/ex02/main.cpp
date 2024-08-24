/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:24:17 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/24 15:45:45 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	
	std::cout <<   a   << std::endl;
	std::cout << ++a   << std::endl;
	std::cout <<   a   << std::endl;
	std::cout <<   a++ << std::endl;
	std::cout <<   a   << std::endl;
	
	std::cout <<   b   << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;
	
	return 0;
}
