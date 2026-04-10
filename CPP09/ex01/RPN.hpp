#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <stdexcept>

class RPN {
	private:
		std::stack<int> _stack;

		bool	isOperator(const std::string& token) const;
		void	operation(const std::string& op);

	public:
		RPN();
		RPN(RPN const& rhs);
		RPN& operator=(RPN const& rhs);
		~RPN();

		int	calculate(const std::string& expression);
};

#endif