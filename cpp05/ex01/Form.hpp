/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:26:39 by tunsal            #+#    #+#             */
/*   Updated: 2024/10/23 19:04:41 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat; // circlular dependency

class Form {
private:
	std::string const _name;
	bool _isSigned;
	const unsigned int _requiredGradeToSign;
	const unsigned int _requiredGradeToExecute;
public:
	Form();
	Form(std::string name, unsigned int requiredGradeToSign, unsigned int requiredGradeToExecute);
	Form(Form const &from);
	~Form();
	Form& operator=(Form const & rhs);

	void beSigned(Bureaucrat bureaucrat);

	std::string getName() const;
	bool getIsSigned() const;
	unsigned int getRequiredGradeToSign() const;
	unsigned int getRequiredGradeToExecute() const;

	class GradeTooHighException : public std::exception {
	public:
        const char* what() const throw();
	};
    class GradeTooLowException  : public std::exception {
	public:
        const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& output, Form const &toPrint);

#endif
