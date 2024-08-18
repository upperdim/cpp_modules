/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:14:54 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/18 23:48:50 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main() {
	Harl harl;

	harl.complain("no sense");
	std::cout << std::endl;
	
	harl.complain("DEBUG");
	std::cout << std::endl;
	
	harl.complain("INFO");
	std::cout << std::endl;
	
	harl.complain("WARNING");
	std::cout << std::endl;
	
	harl.complain("ERROR");
}
