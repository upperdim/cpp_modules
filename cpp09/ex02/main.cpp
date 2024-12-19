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

#include <algorithm>    // sort()
#include <iostream>
#include <cstdlib>      // rand(), srand()
#include <ctime>        // time()
#include "PmergeMe.hpp"

bool areVectorsSame(const std::vector<int>& vec1, const std::vector<int>& vec2) {
	if (vec1.size() != vec2.size()) {
		return false;
	}

	for (size_t i = 0; i < vec1.size(); ++i) {
		if (vec1[i] != vec2[i]) {
			return false;
		}
	}

	return true;
}

void automaticTests(PmergeMe sorter, size_t repeatCount, size_t minVal, size_t maxVal, size_t numCount, bool prints) {
	if (minVal > maxVal || minVal == 0 || maxVal == 0) {
		std::cout << "Invalid arguments in automatic tests!" << std::endl;
		return;
	}

	for (size_t i = 0; i < repeatCount; ++i) {
		std::cout << i << " - Sorting " << numCount << " random numbers between " << minVal << " and " << maxVal << "...";

		std::vector<int> randomList;
		for (size_t j = 0; j < numCount; ++j) {
			int randomNum = minVal + std::rand() % (maxVal - minVal + 1);
			randomList.push_back(randomNum);
		}

		std::vector<int> actual = sorter.sort(randomList, prints);

		std::vector<int> expected = randomList;
		std::sort(expected.begin(), expected.end());

		if (areVectorsSame(actual, expected)) {
			std::cout << "OK" << std::endl;
		} else {
			std::cout << "FAIL!" << std::endl;
		}
	}
}

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
	 std::srand(std::time(0)); // seed rand(), once in the program

	if (argc != 2) {

	}

	(void)argv;

	std::vector<int> lst = {6, 7, 8, 5, 12, 9, 3, 1, 2, 4, 11};
	
	PmergeMe sorter;	
	// manualTests(sorter);
	automaticTests(sorter, 25, 1, 4000000, 75000, false);
	// automaticTests(sorter, 1, 1, 40, 15, true);
}
