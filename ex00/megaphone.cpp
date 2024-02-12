
#include <iostream>
#include <string>
#include <cctype> // C언어의 기능을 C++에서 사용할 수 있게하는 헤더파일

int main(int ac, char **av)
{
	// C++ 에서는 변수를 사용하기 직전 어느 위치에서 든지 변수를 선언할 수 있음
	//변수는 변수 사용 직전에 선언해도 된다.
	
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
