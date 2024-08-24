/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:11:48 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/16 20:09:28 by tunsal           ###   ########.fr       */
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
	Fixed(const Fixed &from);
	Fixed(const int i);
	Fixed(const float f);
	~Fixed();
	Fixed& operator=(const Fixed &from);


	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

// Alternative: `friend` gives function access to private and protected fields
//              this makes it feel like it's a member function like Java `toString()`
//              but it is forbidden in 42
std::ostream& operator<<(std::ostream& output, Fixed const &toPrint);

#endif
