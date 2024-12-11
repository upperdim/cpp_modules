/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:45:39 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/11 08:18:55 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Find an integer in an integer container of type T
// Param 1: Any type T of integer container (array, list, etc.)
// Param 2: An integer
template <typename T>
typename T::iterator easyfind(T& intContainer, int target) {
	typename T::iterator it = std::find(intContainer.begin(), intContainer.end(), target);
	
	// if `find` can't find the target, `it` becomes `.end()`
	if (it == intContainer.end()) {
		throw std::runtime_error("Target integer is not found in the container");
	}
	
	return it;
}
