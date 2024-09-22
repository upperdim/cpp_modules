/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:21:44 by tunsal            #+#    #+#             */
/*   Updated: 2024/09/22 13:51:24 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

#define GRADE_HIGHEST 1
#define GRADE_LOWEST 150
#define GRADE_DEFAULT GRADE_LOWEST

class Bureaucrat {
private:
	std::string const _name;
	unsigned int _grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, unsigned int grade);
	Bureaucrat(Bureaucrat const &from);
	~Bureaucrat();
	Bureaucrat& operator=(Bureaucrat const & rhs);

	void incrementGrade();
	void decrementGrade();

	std::string getName();
	unsigned int getGrade();
};

#endif
