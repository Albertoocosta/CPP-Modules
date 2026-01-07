#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Form
{
	private:
		const std::string _name;
		bool isSigned;
		const int gradeToSign;
		const int gradeRequired;
	public:
		Form();
		Form(Form const& src);
		Form& operator=(Form const& rhs);
		~Form();
		
};

#endif
