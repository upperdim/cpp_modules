/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tunsal <tunsal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:44:19 by tunsal            #+#    #+#             */
/*   Updated: 2024/12/03 15:56:54 by tunsal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM

#include <string>
#include <AForm.hpp>
#include "Bureaucrat.hpp"

#define SHRUBBERYCREATIONFORM_DEFAULT_REQ_GRADE_SIGN 145
#define SHRUBBERYCREATIONFORM_DEFAULT_REQ_GRADE_EXEC 137

class ShrubberyCreationForm : public AForm {
private:
	std::string _target;
	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm const &from);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(ShrubberyCreationForm const & rhs);

	void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& output, AForm const &toPrint);

#endif
