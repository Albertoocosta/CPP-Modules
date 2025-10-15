#include <iostream>
#include <cctype>

char	*megaphone(char *word)
{
	for (int i = 0; word[i]; i++)
		word[i] = toupper(word[i]);
		
	return (word);
}

int	main(int ac, char **av)
{
	(void)ac;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; av[i]; i++)
	{
		megaphone(av[i]);
		std::cout << av[i] << (av[i + 1] ? " " : "");
	}
	std::cout << std::endl;
}