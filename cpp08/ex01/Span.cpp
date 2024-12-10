/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:05:49 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 08:46:32 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
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
	
}

int Span::longestSpan() {

}
