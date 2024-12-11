/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:24:01 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/11 08:30:32 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

template <typename T>
class MutantStack {
private:
	MutantStack();
	~MutantStack();
	MutantStack(MutantStack const & from);
	MutantStack& operator=(MutantStack const & rhs);
public:
};

#include "MutantStack.tpp"

#endif
