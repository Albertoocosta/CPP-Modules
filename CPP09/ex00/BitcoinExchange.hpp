#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _csv;

		bool	isValidDate(const std::string& date) const;
		bool	isValidValue(const std::string& valueStr, float& value) const;
		bool	proccessLine(const std::string& line);

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& rhs);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		~BitcoinExchange();

		void	loadDatabase(const std::string& filename);
		void	evaluateInput(const std::string& filename);
};

#endif