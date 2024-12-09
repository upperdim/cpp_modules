/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:22:53 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/08 22:29:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t

// Iterate an array of types T and apply a function to each element
//
// Param 1: arr_addr
// Param 2: arr_len
// Param 3: function to be applied to each elem (function takes parameter type T pointer obviously)
template <typename T>
void iter(T* arr_addr, size_t arr_len, void(*f)(T*)) {
	for (size_t i = 0; i < arr_len; ++i) {
		f(&arr_addr[i]); // TODO: pointer or reference?
	}
}

#endif
