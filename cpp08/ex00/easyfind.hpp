/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:18:32 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/11 08:20:24 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_HPP
#define EASY_HPP

#include <algorithm>

// Find an integer in an integer container of type T
// Param 1: Any type T of integer container (array, list, etc.)
// Param 2: An integer
template <typename T>
typename T::iterator easyfind(T& intContainer, int target);

#include "easyfind.tpp"

#endif
