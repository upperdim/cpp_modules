/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:05:51 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 08:22:08 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
	std::vector<int> _data;
	unsigned int _maxSize;
	Span();
public:
	Span(unsigned int N);
	Span(Span const & from);
	~Span();
	Span& operator=(Span const & rhs);
	
	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
};

#endif
