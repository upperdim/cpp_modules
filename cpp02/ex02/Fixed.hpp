/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:11:48 by tunsal            #+#    #+#             */
/*   Updated: 2024/08/24 16:01:50 by tunsal           ###   ########.fr       */
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
	
	// Comparison operators
	bool operator>(const Fixed &compareWith) const;
	bool operator>=(const Fixed &compareWith) const;
	bool operator<(const Fixed &compareWith) const;
	bool operator<=(const Fixed &compareWith) const;
	bool operator==(const Fixed &compareWith) const;
	bool operator!=(const Fixed &compareWith) const;

	// Arithmetic operators
	Fixed operator+(const Fixed &operand) const;
	Fixed operator-(const Fixed &operand) const;
	Fixed operator*(const Fixed &operand) const;
	Fixed operator/(const Fixed &operand) const;

	// Pre increment/decrement operators
	Fixed& operator++();
	Fixed& operator--();

	// Post increment/decrement operators
	Fixed operator++(int);
	Fixed operator--(int);

	// Member functions
	static Fixed& min(Fixed &a, Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

	// Getters/Setters
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& output, Fixed const &toPrint);

#endif
