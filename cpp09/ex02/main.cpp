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

#include <iostream>
#include "PmergeMe.hpp"

void manualTests(PmergeMe sorter) {
	std::vector<std::vector<int>> tests = {
		{6, 7, 8, 5, 12, 9, 3, 1, 2, 4, 11},
		{1, 9, 2, 8, 3, 7, 4, 6, 5, 10, 20, 11, 19, 12, 18, 13, 17, 14, 16, 15, 10},
		{2, 2, 2, 2, 6, 6, 6, 6, 4}
	};

	for (size_t t = 0; t < tests.size(); ++t) {
		std::cout << "\n\n\n\nList = ";
		sorter.printList("", tests[t]);

		std::vector<int> sorted = sorter.sort(tests[t], true);
		sorter.printList("Sorted = ", sorted);
	}
}

int main(int argc, char *argv[]) {
	if (argc != 2) {

	}

	(void)argv;

	std::vector<int> lst = {6, 7, 8, 5, 12, 9, 3, 1, 2, 4, 11};
	
	PmergeMe sorter;	
	manualTests(sorter);
}
