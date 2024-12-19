/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:27:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/19 05:46:50 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
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

long long getMicroseconds() {
	struct timeval time;
	gettimeofday(&time, NULL);
	return static_cast<long long>(time.tv_sec) * 1000000LL + time.tv_usec;
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " <positive int 1> <positive int 2> <positive int 3> <...>" << std::endl;
		return 0;
	}

	bool isValid = true;
	std::vector<int> beforeVec;
	for (int i = 1; i < argc; ++i) {
		try {
			int num = std::stoi(argv[i]);
			if (num <= 0) {
				isValid = false;
				break;
			}
			beforeVec.push_back(num);
		} catch (std::exception &e) {
			isValid = false;
			break;
		}
	}

	if (!isValid) {
		std::cout << "Error" << std::endl;
		return EXIT_FAILURE;
	}
	
	PmergeMe sorter;
	
	// manualTests(sorter);
	// std::srand(std::time(0)); // seed rand(), once in the program
	// automaticTests(sorter, 3, 1, 4000000, 50000, false);
	// automaticTests(sorter, 3, 1, 40, 15, true);
	// return 0;
	
	long long startTime = getMicroseconds();
	std::vector<int> beforeVecSorted = sorter.sort(beforeVec, false);
	long long endTime = getMicroseconds();

	long long vectorSortTime = endTime - startTime;
	
	sorter.printList("Before:\t", beforeVec);
	sorter.printList("After:\t", beforeVecSorted);
	std::cout << std::fixed << "Time to process a range of " << beforeVec.size() << " elements with std::vector : " << vectorSortTime << " us" << std::endl;
	// Display time taken by second container	Time to process a range of 5 elements with std::[..] : 0.00014 us
	
	return 0;
}
