/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:27:04 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/19 06:43:28 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include "PmergeMe.hpp"

static void printHeader(std::string header) {
	std::cout                                                   << std::endl;
	std::cout << "============================================" << std::endl;
	std::cout << header                                         << std::endl;
	std::cout << "============================================" << std::endl;
}

// -----------------------------------------------------------------------------
// Vector
// -----------------------------------------------------------------------------
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

void automaticTestsVec(PmergeMe sorter, size_t repeatCount, size_t minVal, size_t maxVal, size_t numCount, bool prints) {
	printHeader("Running Automatic Tests (Vector)");
	
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

void manualTestsVec(PmergeMe sorter) {
	printHeader("Running Manual Tests (Vector)");

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

// -----------------------------------------------------------------------------
// Deque
// -----------------------------------------------------------------------------
bool areDequesSame(const std::deque<int>& vec1, const std::deque<int>& vec2) {
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

void automaticTestsDeque(PmergeMe sorter, size_t repeatCount, size_t minVal, size_t maxVal, size_t numCount, bool prints) {
	printHeader("Running Automatic Tests (Deque)");

	if (minVal > maxVal || minVal == 0 || maxVal == 0) {
		std::cout << "Invalid arguments in automatic tests!" << std::endl;
		return;
	}

	for (size_t i = 0; i < repeatCount; ++i) {
		std::cout << i << " - Sorting " << numCount << " random numbers between " << minVal << " and " << maxVal << "...";

		std::deque<int> randomList;
		for (size_t j = 0; j < numCount; ++j) {
			int randomNum = minVal + std::rand() % (maxVal - minVal + 1);
			randomList.push_back(randomNum);
		}

		std::deque<int> actual = sorter.sort(randomList, prints);

		std::deque<int> expected = randomList;
		std::sort(expected.begin(), expected.end());

		if (areDequesSame(actual, expected)) {
			std::cout << "OK" << std::endl;
		} else {
			std::cout << "FAIL!" << std::endl;
		}
	}
}

void manualTestsDeque(PmergeMe sorter) {
	printHeader("Running Manual Tests (Deque)");

	std::deque<std::deque<int>> tests = {
		{6, 7, 8, 5, 12, 9, 3, 1, 2, 4, 11},
		{1, 9, 2, 8, 3, 7, 4, 6, 5, 10, 20, 11, 19, 12, 18, 13, 17, 14, 16, 15, 10},
		{2, 2, 2, 2, 6, 6, 6, 6, 4}
	};

	for (size_t t = 0; t < tests.size(); ++t) {
		std::cout << "\n\n\n\nList = ";
		sorter.printDeque("", tests[t]);

		std::deque<int> sorted = sorter.sort(tests[t], true);
		sorter.printDeque("Sorted = ", sorted);
	}
}

// -----------------------------------------------------------------------------
// Main
// -----------------------------------------------------------------------------
long long getMicroseconds() {
	struct timeval time;
	gettimeofday(&time, NULL);
	return static_cast<long long>(time.tv_sec) * 1000000LL + time.tv_usec;
}

int main(int argc, char *argv[]) {
	PmergeMe sorter;
	std::srand(std::time(0)); // seed rand() for tests, once in the program
	
	// Tests (Vector)
	// manualTestsVec(sorter);
	// automaticTestsVec(sorter, 25, 1, 4000000, 50000, false);
	// automaticTestsVec(sorter, 1, 1, 40, 15, true);
	// return 0;

	// Tests (Deque)
	// manualTestsDeque(sorter);
	// automaticTestsDeque(sorter, 25, 1, 4000000, 50000, false);
	// automaticTestsDeque(sorter, 1, 1, 40, 15, true);
	// return 0;
	
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
	
	// Vector
	long long startTime = getMicroseconds();
	std::vector<int> afterVec = sorter.sort(beforeVec, false);
	long long endTime = getMicroseconds();
	long long vectorSortTime = endTime - startTime;
	
	// Deque
	std::deque<int> beforeDeque(beforeVec.begin(), beforeVec.end());
	startTime = getMicroseconds();
	std::deque<int> afterDeque = sorter.sort(beforeDeque, false);
	endTime = getMicroseconds();
	long long dequeSortTime = endTime - startTime;

	// Print
	sorter.printList("Before:\t", beforeVec);
	sorter.printList("After:\t", afterVec);
	std::cout << std::fixed << "Time to process a range of " << beforeVec.size()   << " elements with std::vector : " << vectorSortTime << " us" << std::endl;
	std::cout << std::fixed << "Time to process a range of " << beforeDeque.size() << " elements with std::deque  : "  << dequeSortTime  << " us" << std::endl;
	
	return 0;
}
