
#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <iostream> // 입출력 스트림을 조작하기 위한 함수와 객체를 제공(예: std::setw)
#include <string>
#include <iomanip>

/*
`firstName`, `lastName`, `nickName`, `phoneNumber`, `darkestSecret` 지역변수의 값을 사용하여 `newContact`라는 새 `Contact` 객체를 생성하고 있어. 

이렇게 생성된 객체는 함수가 종료되어 지역변수들이 사라지더라도 `PhoneBook`에 저장되는데, 객체의 복사본이 아니라 객체 자체가 `PhoneBook`에 저장되기 때문에, 입력받은 정보는 프로그램 내에서 계속 유효하게 유지돼.
*/

/* 
getline을 사용하는 이유는 사용자 입력에서 공백을 포함하는 문자열을 전체적으로 읽을 수 있기 때문이야. std::cin >>를 사용하면 공백, 탭, 새 줄 문자를 입력 종료로 간주하여 공백 이전의 문자열만 읽게 돼. 연락처 정보 같이 공백을 포함할 수 있는 입력을 처리할 때는 std::getline이 더 적합해. 
*/

//void addNewContact(PhoneBook& phoneBook) {
//	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
//	// 사용자 입력 받기
//	std::cout << "First Name: ";
//	std::getline(std::cin, firstName);
//	std::cout << "Last Name: ";
//	std::getline(std::cin, lastName);
//	std::cout << "Nickname: ";
//	std::getline(std::cin, nickName);
//	std::cout << "Phone Number: ";
//	std::getline(std::cin, phoneNumber);
//	std::cout << "Darkest Secret: ";
//	std::getline(std::cin, darkestSecret);

//	// Contact 객체 생성
//	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	
//	// PhoneBook에 연락처 추가
//	phoneBook.addContact(newContact);

//	std::cout << "New contact added successfully.\n" << std::endl;
//}

// SEARCH

// 문자열이 10자를 초과할 경우 마지막 문자를 '.'으로 대체하는 함수
std::string truncateString(const std::string& str) {
    return str.length() > 10 ? str.substr(0, 9) + "." : str;
}

void searchContact(const PhoneBook& phoneBook) {
    // 연락처 목록을 출력
    for (int i = 0; i < phoneBook.getCurrentSize(); ++i) {
        const Contact& contact = phoneBook.getContact(i);
        std::cout << std::setw(10) << i << " | "
                  << std::setw(10) << truncateString(contact.getFirstName()) << " | "
                  << std::setw(10) << truncateString(contact.getLastName()) << " | "
                  << std::setw(10) << truncateString(contact.getNickName()) << std::endl;
    }

    // 사용자로부터 인덱스 입력 받기
    std::cout << "Enter the index of the contact to display: ";
    int index;
    std::cin >> index;

    // 인덱스 유효성 검사 및 연락처 상세 정보 출력
    if (index >= 0 && index < phoneBook.getCurrentSize()) {
        const Contact& contact = phoneBook.getContact(index);
        std::cout << "First Name: " << contact.getFirstName() << std::endl
                  << "Last Name: " << contact.getLastName() << std::endl
                  << "Nickname: " << contact.getNickName() << std::endl
                  << "Phone Number: " << contact.getPhoneNumber() << std::endl
                  << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid index." << std::endl;
    }
}








// ADD
void getInput(const std::string& fieldName, std::string& fieldValue) {
	while (1) {
		std::cout << fieldName << ": ";
		std::getline(std::cin, fieldValue);
		if (!fieldValue.empty())
			break;
		std::cout << fieldName << " field is empty. Enter it again.\n";
	}
}

void addNewContact(PhoneBook& phoneBook) {
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	getInput("First Name", firstName);
	getInput("Last Name", lastName);
	getInput("Nickname", nickName);
	getInput("Phone Number", phoneNumber);
	getInput("Darkest Secret", darkestSecret);

 	// Contact 객체 생성
	Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);

	// PhoneBook에 연락처 추가
	phoneBook.addContact(newContact); 
	std::cout << "New contact added successfully.\n\n";
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	command;

	while (1)
	{
		std::cout << "\nEnter the command from ADD, SEARCH, or EIXT. \n";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			addNewContact(phoneBook);
		}
		else if (command == "SEARCH")
		{
			searchContact(phoneBook);
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