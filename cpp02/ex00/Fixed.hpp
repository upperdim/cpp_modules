/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:50:56 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/09 22:42:47 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FIXED_H_
#define _FIXED_H_

// Classes from now have to be Orhodox Canonical Form, meaning it must have:
// - Default constructor
// - Copy constructor
// - Copy assignment operator
// - Destructor

#define DEFAULT_FRACTIONAL_BITS 8

class Fixed {
private:
	int _val;
	static const int _numOfFractionalBits;
public:
	Fixed();
	Fixed(Fixed &from);
	~Fixed();
	Fixed& operator=(Fixed &from);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
