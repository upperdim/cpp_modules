/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:14:54 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/09 19:42:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int main() {
	Harl harl;

	harl.complain("no sense");
	
	harl.complain("debug");
	std::cout << std::endl;
	
	harl.complain("info");
	std::cout << std::endl;
	
	harl.complain("warning");
	std::cout << std::endl;
	
	harl.complain("error");
}
