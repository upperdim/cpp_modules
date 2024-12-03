/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:44:15 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/03 15:52:59 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <AForm.hpp>
#include "Bureaucrat.hpp"

#define ROBOTOMYREQUESTFORM_DEFAULT_REQ_GRADE_SIGN 72
#define ROBOTOMYREQUESTFORM_DEFAULT_REQ_GRADE_EXEC 45

class RobotomyRequestForm : public AForm {
private:
	std::string _target;
	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm const &from);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(RobotomyRequestForm const & rhs);

	void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& output, AForm const &toPrint);

#endif
