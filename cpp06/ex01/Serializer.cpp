/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:56:33 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/08 19:35:54 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer& other) { (void) other; }
Serializer::~Serializer() {}
Serializer& Serializer::operator=(const Serializer& other) {
	(void)other;
	return (*this);
}

// reinterpret_cast changes how compiler interprets bits/bytes on memory for a variable.
//
// Data that is pointed by an int* would be iterated by skipping 4 bytes by 4 bytes.
// Because the data is being interpreted as 4 byte integers.
//
// Same data that is pointed by char* would be iterated 1 byte by 1 byte.
// Because bits of the data on memory is being interpreted as 1 byte chars.
//
// reinterpret_cast simply converts how you interpret a given data on memory, hence the name reinterpret.
// Meaning it converts one pointer type to another.
uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
