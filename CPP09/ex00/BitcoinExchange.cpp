#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(BitcoinExchange const& rhs) : _csv(rhs._csv){}
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	if (this != &rhs)
		this->_csv = rhs._csv;
	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-')
		return false;
	int year, month, day;
	char dash1, dash2;

	std::istringstream ss(date);

	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail() || !ss.eof())
		return false;
	if (year < 2009)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (isLeapYear && day > 29)
			return false;
		if (!isLeapYear && day > 28)
			return false;
	}

	return true;
}

bool	BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const 
{
	std::istringstream ss(valueStr);
	ss >> value;

	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

void	BitcoinExchange::loadDatabase(const std::string& filename) 
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open Database file. " << std::endl;
		exit(1);
	}
	std::string line;
	std::getline(file, line);

	while(std::getline(file,line))
	{
		size_t commaFind = line.find(',');
		if (commaFind != std::string::npos)
		{
			std::string date = line.substr(commaFind + 1).c_str();
			float rate = std::atof(line.substr(commaFind + 1).c_str());
			_csv[date] = rate;
		}
	}
	file.close();
}

void	BitcoinExchange::evaluateInput(const std::string& filename) 
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open Database file. " << std::endl;
		return ;
	}
	std::string line;
	std::getline(file, line);

	while(std::getline(file,line))
	{
		size_t pipeFind = line.find(" | ");
		if (pipeFind == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ; 
		}
		std::string date = line.substr(0, pipeFind);
		std::string valueStr = line.substr(pipeFind + 3);
		float value;

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue; 
		}

		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: Not a valid number." << std::endl;
			continue; 
		}

		if (value < 0)
		{
			std::cerr << "Error: Not a positive number." << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = _csv.lower_bound(date);

		if (it != _csv.end() && it->first == date)
			std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
		else if (it == _csv.begin())
			std::cerr << "Error: no older date found in database => " << date << std::endl;
		else
		{
			--it;
			std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
		}
	}
	file.close();
}

