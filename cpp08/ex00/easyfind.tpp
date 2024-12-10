/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 03:45:39 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/10 03:49:42 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Find an integer in an integer container of type T
// Param 1: Any type T of integer container (array, list, etc.)
// Param 2: An integer
template <typename T>
void easyfind(T intContainer, int target) {
	typename T::iterator it;
	for (it = intContainer.begin(); it != intContainer.end(); it++) {
		if (*it == target) {
			std::cout << "Found " << target << std::endl;
		}
	}
}
