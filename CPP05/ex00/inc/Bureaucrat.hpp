
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:

		Bureaucrat(void);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat&	operator=(const Bureaucrat &other);
		~Bureaucrat(void);
	
	private:

		std::string	_name;
		int			_grade;
};

#endif // BUREAUCRAT_HPP
