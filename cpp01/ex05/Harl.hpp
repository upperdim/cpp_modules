/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:15:32 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/09 19:26:06 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	void complain(std::string level);
};
