/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:27:11 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/19 06:31:15 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

// -----------------------------------------------------------------------------
// Orthodox Canonical Form
// -----------------------------------------------------------------------------
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const & other) { (void) other; }

PmergeMe& PmergeMe::operator=(PmergeMe const & rhs) {
	if (this != &rhs) {}
	return *this;
}

PmergeMe::~PmergeMe() {}

// -----------------------------------------------------------------------------
// Vector
// -----------------------------------------------------------------------------
void PmergeMe::printPairs(std::string msg, std::vector<std::vector<int>> pairs) {
	std::cout << msg;
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::cout << "(";
		for (size_t j = 0; j < pairs[i].size(); ++j) {
			std::cout << pairs[i][j] << " ";
		}
		std::cout << ") ";
	}
	std::cout << std::endl;
}

void PmergeMe::printList(std::string msg, std::vector<int> lst) {
	std::cout << msg;
	for (size_t i = 0; i < lst.size(); ++i) {
		std::cout << lst[i] << " ";
	}
	std::cout << std::endl;
}

size_t PmergeMe::binarySearch(std::vector<int> arr, int val) {
	size_t low = 0;
	size_t high = arr.size();

	while (low < high) {
		size_t mid = (low + high) / 2;
		if (arr[mid] < val) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}

	return low;
}

std::vector<int> PmergeMe::generateGroupLengths(std::vector<int> rem) {
	size_t currLen = 0;
	size_t n = 1;
	size_t nextLen = generateNthJacobsthal(n) * 2;

	std::vector<int> groupLengths;
	while (currLen + nextLen < rem.size()) {
		currLen += nextLen;
		groupLengths.push_back(generateNthJacobsthal(n) * 2);
		++n;
		nextLen = generateNthJacobsthal(n) * 2;
	}

	return groupLengths;
}

std::vector<std::vector<int>> PmergeMe::merge(const std::vector<std::vector<int>>& left, const std::vector<std::vector<int>>& right) {
	std::vector<std::vector<int>> result;
	size_t i = 0, j = 0;

	while (i < left.size() && j < right.size()) {
		// Compare the larger element of each pair and decide the order
		if (std::max(left[i][0], left[i][1]) < std::max(right[j][0], right[j][1])) {
			result.push_back(left[i]);
			i++;
		} else {
			result.push_back(right[j]);
			j++;
		}
	}

	// Add remaining elements from the left half
	while (i < left.size()) {
		result.push_back(left[i]);
		i++;
	}

	// Add remaining elements from the right half
	while (j < right.size()) {
		result.push_back(right[j]);
		j++;
	}

	return result;
}

std::vector<std::vector<int>> PmergeMe::sortPairsByLarger(const std::vector<std::vector<int>>& pairs) {
	if (pairs.size() <= 1) {
		return pairs;
	}

	size_t mid = pairs.size() / 2;
	std::vector<std::vector<int>> left(pairs.begin(), pairs.begin() + mid);
	std::vector<std::vector<int>> right(pairs.begin() + mid, pairs.end());

	left = sortPairsByLarger(left);
	right = sortPairsByLarger(right);

	return merge(left, right);
}

void PmergeMe::sortEachPairAscending(std::vector<std::vector<int>> &pairs) {
	for (std::vector<std::vector<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		std::sort(it->begin(), it->end());
	}
}

std::vector<int> PmergeMe::sort(std::vector<int> lst, bool prints) {
	if (prints) printList("------------- beginning with list = ", lst);

	// Recursion terminal condition
	if (lst.size() <= 1)
		return lst;

	// Determine if it has an unpairable straggler at the end
	bool hasStray = lst.size() % 2 == 1;
	int stray = lst[lst.size() - 1];
	if (prints) std::cout << "hasStray = " << hasStray << ", stray = " << stray << std::endl;

	// Pair numbers
	std::vector<std::vector<int>> pairs;
	for (size_t i = 0; i < lst.size() - 1; i += 2) {
		std::vector<int> pair;
		pair.push_back(lst[i]);
		pair.push_back(lst[i + 1]);
		pairs.push_back(pair);
	}
	if (prints) printPairs("Pairs = ", pairs);

	// Sort each pair in ascending order
	sortEachPairAscending(pairs);
	if (prints) printPairs("Each pair sorted in ascending order, pairs = ", pairs);
	
	// Sort pairs by their larger element recursively
	std::vector<std::vector<int>> sortedPairs = sortPairsByLarger(pairs);
	if (prints) printPairs("Pairs sorted recursively by larger, pairs = ", sortedPairs);

	// Form sequence rem with smaller, sequence S with larger numbers
	std::vector<int> rem;
	std::vector<int> s;
	for (size_t i = 0; i < sortedPairs.size(); ++i) {
		rem.push_back(sortedPairs[i][0]);
		s.push_back(sortedPairs[i][1]);
	}
	if (prints) printList("Formed rem = ", rem);
	if (prints) printList("Formed s = ", s);

	// Insert into beginning of S the element that was paired with the first element of S
	if (prints) std::cout << "Inserting " << rem[0] << " into S (pair of s[0] = " << s[0] << ")" << std::endl;
	s.insert(s.begin(), rem[0]);
	rem.erase(rem.begin());
	if (prints) printList("Inserted, rem = ", rem);
	if (prints) printList("Inserted, s = ", s);

	// Add stray if there is one
	if (hasStray) {
		if (prints) std::cout << "Appended stray " << stray << " to rem" << std::endl;
		rem.push_back(stray);
	}
	if (prints) printList("rem = ", rem);

	// Create insertion sequence
	std::vector<int> groupLengths = generateGroupLengths(rem);
	if (prints) printList("Group lengths = ", groupLengths);

	size_t remIdx = 0;
	// Groups are inserted from first to last
	for (size_t g = 0; g < groupLengths.size(); ++g) {
		// Elements inside groups are inserted last to first
		for (int i = groupLengths[g]-1; i >= 0; --i) {
			int val = rem[remIdx + i];
			size_t destIdx = binarySearch(s, val);
			s.insert(s.begin() + destIdx, val);
			if (prints) { std::cout << "Inserted " << val << " into s => "; printList("", s); }
		}
		remIdx += groupLengths[g];
	}

	// Insert remaining ungrouped items
	if (prints) std::cout << "Inserting ungrouped items" << std::endl;
	while (remIdx < rem.size()) {
		int val = rem[remIdx];
		size_t destIdx = binarySearch(s, val);
		s.insert(s.begin() + destIdx, val);
		++remIdx;
		if (prints) { std::cout << "Inserted " << val << " into s => "; printList("", s); }
	}

	return s;
}

// -----------------------------------------------------------------------------
// Deque
// -----------------------------------------------------------------------------
void PmergeMe::printPairs(std::string msg, std::deque<std::deque<int>> pairs) {
	std::cout << msg;
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::cout << "(";
		for (size_t j = 0; j < pairs[i].size(); ++j) {
			std::cout << pairs[i][j] << " ";
		}
		std::cout << ") ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(std::string msg, std::deque<int> lst) {
	std::cout << msg;
	for (size_t i = 0; i < lst.size(); ++i) {
		std::cout << lst[i] << " ";
	}
	std::cout << std::endl;
}

size_t PmergeMe::binarySearch(std::deque<int> arr, int val) {
	size_t low = 0;
	size_t high = arr.size();

	while (low < high) {
		size_t mid = (low + high) / 2;
		if (arr[mid] < val) {
			low = mid + 1;
		} else {
			high = mid;
		}
	}

	return low;
}

std::deque<int> PmergeMe::generateGroupLengths(std::deque<int> rem) {
	size_t currLen = 0;
	size_t n = 1;
	size_t nextLen = generateNthJacobsthal(n) * 2;

	std::deque<int> groupLengths;
	while (currLen + nextLen < rem.size()) {
		currLen += nextLen;
		groupLengths.push_back(generateNthJacobsthal(n) * 2);
		++n;
		nextLen = generateNthJacobsthal(n) * 2;
	}

	return groupLengths;
}

std::deque<std::deque<int>> PmergeMe::merge(const std::deque<std::deque<int>>& left, const std::deque<std::deque<int>>& right) {
	std::deque<std::deque<int>> result;
	size_t i = 0, j = 0;

	while (i < left.size() && j < right.size()) {
		// Compare the larger element of each pair and decide the order
		if (std::max(left[i][0], left[i][1]) < std::max(right[j][0], right[j][1])) {
			result.push_back(left[i]);
			i++;
		} else {
			result.push_back(right[j]);
			j++;
		}
	}

	// Add remaining elements from the left half
	while (i < left.size()) {
		result.push_back(left[i]);
		i++;
	}

	// Add remaining elements from the right half
	while (j < right.size()) {
		result.push_back(right[j]);
		j++;
	}

	return result;
}

std::deque<std::deque<int>> PmergeMe::sortPairsByLarger(const std::deque<std::deque<int>>& pairs) {
	if (pairs.size() <= 1) {
		return pairs;
	}

	size_t mid = pairs.size() / 2;
	std::deque<std::deque<int>> left(pairs.begin(), pairs.begin() + mid);
	std::deque<std::deque<int>> right(pairs.begin() + mid, pairs.end());

	left = sortPairsByLarger(left);
	right = sortPairsByLarger(right);

	return merge(left, right);
}

void PmergeMe::sortEachPairAscending(std::deque<std::deque<int>> &pairs) {
	for (std::deque<std::deque<int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		std::sort(it->begin(), it->end());
	}
}

std::deque<int> PmergeMe::sort(std::deque<int> lst, bool prints) {
	if (prints) printDeque("------------- beginning with list = ", lst);

	// Recursion terminal condition
	if (lst.size() <= 1)
		return lst;

	// Determine if it has an unpairable straggler at the end
	bool hasStray = lst.size() % 2 == 1;
	int stray = lst[lst.size() - 1];
	if (prints) std::cout << "hasStray = " << hasStray << ", stray = " << stray << std::endl;

	// Pair numbers
	std::deque<std::deque<int>> pairs;
	for (size_t i = 0; i < lst.size() - 1; i += 2) {
		std::deque<int> pair;
		pair.push_back(lst[i]);
		pair.push_back(lst[i + 1]);
		pairs.push_back(pair);
	}
	if (prints) printPairs("Pairs = ", pairs);

	// Sort each pair in ascending order
	sortEachPairAscending(pairs);
	if (prints) printPairs("Each pair sorted in ascending order, pairs = ", pairs);
	
	// Sort pairs by their larger element recursively
	std::deque<std::deque<int>> sortedPairs = sortPairsByLarger(pairs);
	if (prints) printPairs("Pairs sorted recursively by larger, pairs = ", sortedPairs);

	// Form sequence rem with smaller, sequence S with larger numbers
	std::deque<int> rem;
	std::deque<int> s;
	for (size_t i = 0; i < sortedPairs.size(); ++i) {
		rem.push_back(sortedPairs[i][0]);
		s.push_back(sortedPairs[i][1]);
	}
	if (prints) printDeque("Formed rem = ", rem);
	if (prints) printDeque("Formed s = ", s);

	// Insert into beginning of S the element that was paired with the first element of S
	if (prints) std::cout << "Inserting " << rem[0] << " into S (pair of s[0] = " << s[0] << ")" << std::endl;
	s.insert(s.begin(), rem[0]);
	rem.erase(rem.begin());
	if (prints) printDeque("Inserted, rem = ", rem);
	if (prints) printDeque("Inserted, s = ", s);

	// Add stray if there is one
	if (hasStray) {
		if (prints) std::cout << "Appended stray " << stray << " to rem" << std::endl;
		rem.push_back(stray);
	}
	if (prints) printDeque("rem = ", rem);

	// Create insertion sequence
	std::deque<int> groupLengths = generateGroupLengths(rem);
	if (prints) printDeque("Group lengths = ", groupLengths);

	size_t remIdx = 0;
	// Groups are inserted from first to last
	for (size_t g = 0; g < groupLengths.size(); ++g) {
		// Elements inside groups are inserted last to first
		for (int i = groupLengths[g]-1; i >= 0; --i) {
			int val = rem[remIdx + i];
			size_t destIdx = binarySearch(s, val);
			s.insert(s.begin() + destIdx, val);
			if (prints) { std::cout << "Inserted " << val << " into s => "; printDeque("", s); }
		}
		remIdx += groupLengths[g];
	}

	// Insert remaining ungrouped items
	if (prints) std::cout << "Inserting ungrouped items" << std::endl;
	while (remIdx < rem.size()) {
		int val = rem[remIdx];
		size_t destIdx = binarySearch(s, val);
		s.insert(s.begin() + destIdx, val);
		++remIdx;
		if (prints) { std::cout << "Inserted " << val << " into s => "; printDeque("", s); }
	}

	return s;
}

// -----------------------------------------------------------------------------
// Common Utilities
// -----------------------------------------------------------------------------
size_t PmergeMe::generateNthJacobsthal(size_t n) {
	if (n == 0 || n == 1)
		return n;
	return generateNthJacobsthal(n - 1) + 2 * generateNthJacobsthal(n - 2);
}
