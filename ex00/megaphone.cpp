/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:17:41 by jungmiho          #+#    #+#             */
/*   Updated: 2024/02/15 20:23:25 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include <cctype>

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
			input[j] = std::toupper(input[j]); // FIXME
		}
		std::cout << input << " ";
	}
	std::cout << std::endl;

	return (0);
}
