/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:16:36 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/26 15:23:37 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>

#define NUM_IDEAS 100

class Brain {
private:
	std::string _ideas[NUM_IDEAS];
public:
	Brain();
	Brain(const Brain &from);
	~Brain();
	Brain& operator=(const Brain &from);
};

#endif
