/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:44:02 by tunsal            #+#    #+#             */
/*   Updated: 2024/11/21 17:57:51 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm {
private:
	std::string const _name;
	bool _isSigned;
	const unsigned int _requiredGradeToSign;
	const unsigned int _requiredGradeToExecute;
public:
	AForm();
	AForm(std::string name, unsigned int requiredGradeToSign, unsigned int requiredGradeToExecute);
	AForm(AForm const &from);
	~AForm();
	AForm& operator=(AForm const & rhs);

	void beSigned(Bureaucrat bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
	void executionChecks(Bureaucrat const & executor) const;

	std::string getName() const;
	bool getIsSigned() const;
	unsigned int getRequiredGradeToSign() const;
	unsigned int getRequiredGradeToExecute() const;

	// TODO: std::runtime_exception instead of std::exception? (on all excercises!)
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw();
	};
    class GradeTooLowException  : public std::exception {
	public:
		const char* what() const throw();
	};
	class NotSignedException  : public std::exception {
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& output, AForm const &toPrint);

#endif
