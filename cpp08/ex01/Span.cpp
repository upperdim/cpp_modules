/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:05:49 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 09:05:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <limits>  // numeric_limits
#include "Span.hpp"

Span::Span() : _data(std::vector<int>()), _maxSize(0) {
	std::cout << "Span default constructor" << std::endl;
}

Span::Span(unsigned int N) : _data(std::vector<int>()), _maxSize(N) {
	std::cout << "Span created with capacity " << N << std::endl;
}

Span::Span(Span const & from) : _data(from._data), _maxSize(from._maxSize) {}

Span::~Span() {
	std::cout << "Span destroyed" << std::endl;
}

Span& Span::operator=(Span const & rhs) {
	if (this != &rhs) {
		_maxSize = rhs._maxSize;
		_data = rhs._data;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_data.size() >= _maxSize) {
		throw std::runtime_error("Span capacity is full");
	}
	_data.push_back(num);
}

int Span::shortestSpan() {
	if (_data.size() < 2) {
		throw std::runtime_error("Span is undefined for less than 2 elements");
	}

	std::vector<int> sorted(_data);
	std::sort(sorted.begin(), sorted.end());
	
	int min = std::numeric_limits<int>::max();
	for (size_t i = 0; i < _data.size() - 1; ++i) {
		int currSpan = sorted[i + 1] - sorted[i];
		if (currSpan < min) {
			min = currSpan;
		}
	}
	return min;
}

int Span::longestSpan() {
	if (_data.size() < 2) {
		throw std::runtime_error("Span is undefined for less than 2 elements");
	}

	std::vector<int> sorted(_data);
	std::sort(sorted.begin(), sorted.end());

	return sorted[sorted.size() - 1] - sorted[0];
}
