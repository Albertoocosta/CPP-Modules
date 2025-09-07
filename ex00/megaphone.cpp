#include <iostream>

char	*megaphone(char *word)
{
	for (int i = 0; word[i]; i++)
	{
			if (word[i] >= 'a' && word[i] <= 'z')
				word[i] -= 32;
	}
	return(word);
}

int	main(int ac, char **av)
{
	(void)ac;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; av[i]; i++)
	{
		megaphone(av[i]);
		std::cout << av[i];
	}
	std::cout << std::endl;
}