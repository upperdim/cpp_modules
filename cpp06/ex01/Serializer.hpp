/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:56:35 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/08 19:38:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint> // uintptr_t

struct Data {
	unsigned int  num1; // 4 bytes
	unsigned char ch1;  // 1 byte
	unsigned char ch2;  // 1 byte
	unsigned char ch3;  // 1 byte
	unsigned char ch4;  // 1 byte
	unsigned int  num2; // 4 bytes
};

class Serializer {
private:
	Serializer();
	Serializer(const Serializer & other);
	~Serializer();
	Serializer& operator=(const Serializer & rhs);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
