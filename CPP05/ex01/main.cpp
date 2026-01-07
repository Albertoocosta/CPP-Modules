#include "Bureaucrat.hpp"

int main()
{
	std::cout << " Test #1 " << std::endl;
	try{
		Bureaucrat john("John Doe", 100);
		std::cout << john << std::endl;

		std::cout << "Increment and decrement grade: " << std::endl;
		john.increment();
		std::cout << john << std::endl;

		john.decrement();
		std::cout << john << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << " Test #2 " << std::endl;

	try{
		Bureaucrat loser("Joseph Loser", 151);
		std::cout << loser << std::endl; // this line never show
	} 
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << " Test #3 " << std::endl;
	try{
		Bureaucrat exodia("Above Everybody", 0);
		std::cout << exodia << std::endl; // this line never show
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << " Test #4 " << std::endl;
	try{
		Bureaucrat boss("John Cena", 1);
		std::cout << boss << std::endl;

		std::cout << "If I try to increment John Cena..." << std::endl;
		boss.increment();
		std::cout << boss << std::endl; // this line never show
	} 
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << " Test #5 " << std::endl;
	try{
		Bureaucrat parker("Peter Parker", 150);
		std::cout << parker << std::endl;

		std::cout << "If I try to decrement Peter Parker..." << std::endl;
		parker.decrement();
		std::cout << parker << std::endl; // this line never show
	} 
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}