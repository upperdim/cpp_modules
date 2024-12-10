/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 05:05:51 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 05:36:34 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
private:
	Span();
public:
	Span(unsigned int N);
	Span(Span const & from);
	~Span();
	Span& operator=(Span const & rhs);
	
	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif
