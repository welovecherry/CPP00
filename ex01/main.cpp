#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook phoneBook;
	std::string command;

	while (1)
	{
		std::cout << "Enter the command from ADD, SEARCH, or EIXT.";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
	
		}
		else if (command == "SEARCH")
		{

		}
		else if (command == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Invalid command. Enter again!" << std::endl;
		}
	}



	return (0);
}