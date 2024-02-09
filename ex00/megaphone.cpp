
#include <iostream>
#include <string>
#include <cctype> // C언어의 기능을 C++에서 사용할 수 있게하는 헤더파일

//int main()
//{
//	std::string	input;
//	std::getline(std::cin, input);

//	for (size_t i = 0; i < input.length(); i++)
//	{
//		input[i] = std::toupper(input[i]);
//	}
//	std::cout << input << std::endl;

//	return 0;
//}



int main(int ac, char **av)
{
	int			i;
	size_t		j;
	std::string	input;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}

	for (i = 1; i < ac; i++)
	{
		input = av[i];
		for (j = 0; j < input.length(); j++)
		{
			input[j] = std::toupper(input[j]);
		}
		std::cout << input << " ";
	}
	std::cout << std::endl;

	return (0);
}
