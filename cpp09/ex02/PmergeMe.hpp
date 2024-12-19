/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 23:27:13 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/19 06:25:11 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <vector>
#include <deque>

class PmergeMe {
private:
	void							sortEachPairAscending(std::vector<std::vector<int>> &pairs);
	void							sortEachPairAscending(std::deque<std::deque<int>> &pairs);

	std::vector<std::vector<int>>	sortPairsByLarger(const std::vector<std::vector<int>>& pairs);
	std::deque<std::deque<int>>		sortPairsByLarger(const std::deque<std::deque<int>>&   pairs);
	
	std::vector<std::vector<int>>	merge(const std::vector<std::vector<int>>& left, const std::vector<std::vector<int>>& right);
	std::deque<std::deque<int>>		merge(const std::deque<std::deque<int>>&   left, const std::deque<std::deque<int>>&   right);
	
	std::vector<int>				generateGroupLengths(std::vector<int> rem);
	std::deque<int>					generateGroupLengths(std::deque<int>  rem);
	
	size_t							binarySearch(std::vector<int> arr, int val);
	size_t							binarySearch(std::deque<int>  arr, int val);

	void							printPairs(std::string msg, std::vector<std::vector<int>> pairs);
	void							printPairs(std::string msg, std::deque<std::deque<int>>   pairs);

	size_t							generateNthJacobsthal(size_t n);
public:
	PmergeMe();
	PmergeMe(PmergeMe const & other);
	PmergeMe& operator=(PmergeMe const & rhs);
	~PmergeMe();

	std::vector<int>				sort(std::vector<int> lst, bool prints);
	std::deque<int>					sort(std::deque<int> lst, bool prints);
	
	void							printList(std::string msg, std::vector<int> lst);
	void							printDeque(std::string msg, std::deque<int> lst);
};

#endif
