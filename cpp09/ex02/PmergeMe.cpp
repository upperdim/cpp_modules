/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:27:11 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/18 23:27:11 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm> // sort
#include <iostream>
#include <utility>   // pair
#include <string>
#include <vector>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const & other) { (void) other; }

PmergeMe& PmergeMe::operator=(PmergeMe const & rhs) {
	if (this != &rhs) {}
	return *this;
}

PmergeMe::~PmergeMe() {

}



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
	std::cout << " -------------" << std::endl;

	// Recursion terminal condition
	if (lst.size() <= 1)
		return lst;

	// Determine if it has an unpairable straggler at the end
	bool has_stray = lst.size() % 2 == 1;
	int stray = lst[lst.size() - 1];
	if (prints) std::cout << "has_stray = " << has_stray << ", stray = " << stray << std::endl;

	// Pair numbers
	std::vector<std::vector<int>> pairs;
	for (size_t i = 0; i < lst.size() - 1; i += 2) {
		std::cout << "i = " << i << std::endl;
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






	return s;
}
