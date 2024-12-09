/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:22:55 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/09 23:47:25 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath> // floor()
#include "iter.hpp"

void float_make_annoying(float *f) {
	*f += 0.0001;
}

void int_increment(int *i) {
	*i += 1;
}

int main() {
	int int_arr[5] = {1, 2, 3, 4, 5};
	float float_arr[5] = {11.5, 12.5, 13.5, 14.5, 15.5};

	iter(float_arr, 5, float_make_annoying);
	iter(int_arr, 5, int_increment);

	for (size_t i = 0; i < 5; ++i) {
		std::cout << int_arr[i] << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 5; ++i) {
		std::cout << float_arr[i] << " ";
	}
	std::cout << std::endl;
}
