/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:56:30 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/08 19:48:52 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

void printData(struct Data* data) {
	std::cout << "num1 = " << data->num1 << std::endl;
	std::cout << "ch1  = " << data->ch1  << std::endl;
	std::cout << "ch2  = " << data->ch2  << std::endl;
	std::cout << "ch3  = " << data->ch3  << std::endl;
	std::cout << "ch4  = " << data->ch4  << std::endl;
	std::cout << "num2 = " << data->num2 << std::endl;
}

int main() {
	struct Data data = {42, 'a', 'b', 'c', 'd', 123};
	
	std::cout << "Initial:" << std::endl;
	printData(&data);

	std::cout << std::endl << "Serializing..." << std::endl;
	uintptr_t serialized = Serializer::serialize(&data);

	std::cout << std::endl << "Deserialized:" << std::endl;
	struct Data *dataPtr = Serializer::deserialize(serialized);
	printData(dataPtr);

}
