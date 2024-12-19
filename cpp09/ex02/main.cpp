/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:27:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/18 23:27:04 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {

	}

	(void)argv;

	std::vector<int> lst = {6, 7, 8, 5, 12, 9, 3, 1, 2, 4, 11};
	
	PmergeMe sorter;	
	sorter.sort(lst, true);
}
