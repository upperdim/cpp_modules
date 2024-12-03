/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:44:10 by tunsal            #+#    #+#             */
/*   Updated: 2024/11/21 15:20:31 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <AForm.hpp>
#include "Bureaucrat.hpp"

#define PRESPARDONFORM_DEFAULT_REQ_GRADE_SIGN 25
#define PRESPARDONFORM_DEFAULT_REQ_GRADE_EXEC 5

class PresidentialPardonForm : public AForm {
private:
	std::string _target;
	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm const &from);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(PresidentialPardonForm const & rhs);

	void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& output, AForm const &toPrint);

#endif
