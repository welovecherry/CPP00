#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

/*
`firstName`, `lastName`, `nickName`, `phoneNumber`, `darkestSecret` 지역변수의 값을 사용하여 `newContact`라는 새 `Contact` 객체를 생성하고 있어. 

이렇게 생성된 객체는 함수가 종료되어 지역변수들이 사라지더라도 `PhoneBook`에 저장되는데, 객체의 복사본이 아니라 객체 자체가 `PhoneBook`에 저장되기 때문에, 입력받은 정보는 프로그램 내에서 계속 유효하게 유지돼.
*/

/* 
getline을 사용하는 이유는 사용자 입력에서 공백을 포함하는 문자열을 전체적으로 읽을 수 있기 때문이야. std::cin >>를 사용하면 공백, 탭, 새 줄 문자를 입력 종료로 간주하여 공백 이전의 문자열만 읽게 돼. 연락처 정보 같이 공백을 포함할 수 있는 입력을 처리할 때는 std::getline이 더 적합해. 
*/

// TODO: A saved contact can’t have empty fields.
void addNewContact(PhoneBook& phoneBook) {
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	// 사용자 입력 받기
	std::cout << "First Name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last Name: ";
	std::getline(std::cin, lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickName);
	std::cout << "Phone Number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, darkestSecret);

	// Contact 객체 생성
	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	
	// PhoneBook에 연락처 추가
	phoneBook.addContact(newContact);

	std::cout << "New contact added successfully.\n" << std::endl;
}


int	main()
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "Enter the command from ADD, SEARCH, or EIXT. \n";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			addNewContact(phoneBook);
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