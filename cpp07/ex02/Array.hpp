/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 23:50:13 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 02:22:32 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept> // std::exception

template <typename T>
class Array {
private:
	T* _data;
	unsigned int _size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array & other);
	~Array();
	Array& operator=(const Array & rhs);
	
	T& operator[](unsigned int idx);

	unsigned int size(void) const;
};

#include "Array.tpp"

#endif
