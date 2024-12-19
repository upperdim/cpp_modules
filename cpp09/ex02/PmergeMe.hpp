/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:27:13 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/18 23:27:13 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>

class PmergeMe {
private:
	void sortEachPairAscending(std::vector<std::vector<int>> &pairs);
	std::vector<std::vector<int>> sortPairsByLarger(const std::vector<std::vector<int>>& pairs);
	std::vector<std::vector<int>> merge(const std::vector<std::vector<int>>& left, const std::vector<std::vector<int>>& right);
	std::vector<int> generateGroupLengths(std::vector<int> rem);
	size_t generateNthJacobsthal(size_t n);
	size_t binarySearch(std::vector<int> arr, int val);

	void printPairs(std::string msg, std::vector<std::vector<int>> pairs);
public:
	PmergeMe();
	PmergeMe(PmergeMe const & other);
	PmergeMe& operator=(PmergeMe const & rhs);
	~PmergeMe();

	std::vector<int> sort(std::vector<int> lst, bool prints);
	
	void printList(std::string msg, std::vector<int> lst);
};

#endif
