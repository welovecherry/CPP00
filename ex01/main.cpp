
#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <iostream> // 입출력 스트림을 조작하기 위한 함수와 객체를 제공(예: std::setw)
#include <string>
#include <iomanip> // setw()


std::string truncateString(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + '.';
	else
		return str;
}

void searchContact(const PhoneBook& phoneBook) {
    if (phoneBook.getCurrentSize() == 0) {
        std::cout << "No contacts available.\nPlease ADD a contact first.\n";
        return;
    }

	std::cout	<< std::right << std::setw(10) << "INDEX" << " | "
				<< std::setw(10) << "FIRST NAME" << " | "
				<< std::setw(10) << "LAST NAME" << " | "
				<< std::setw(10) << "NICK NAME" << std::endl;

	std::cout	<< std::right << std::setw(10) << "__________" << " | "
				<< std::setw(10) << "__________" << " | "
				<< std::setw(10) << "__________" << " | "
				<< std::setw(10) << "__________" << std::endl;

	for (int i = 0; i < phoneBook.getCurrentSize(); i++) {
		const Contact& contact = phoneBook.getContact(i);
		
		std::cout << std::right << std::setw(10) << i << " | "
				<< std::setw(10) << truncateString(contact.getFirstName()) << " | "
				<< std::setw(10) << truncateString(contact.getLastName()) << " | "
				<< std::setw(10) << truncateString(contact.getNickName()) << std::endl;
	}

	int index;
	while (true) {
		std::cout << "Enter the index of the contact to display: \n";
		std::cin >> index;

		if (std::cin.good() && index >= 0 && index < phoneBook.getCurrentSize()) {
			const Contact& contact = phoneBook.getContact(index);
				std::cout << "\nFirst Name: " << contact.getFirstName() << std::endl
						<< "Last Name: " << contact.getLastName() << std::endl
						<< "Nickname: " << contact.getNickName() << std::endl
						<< "Phone Number: " << contact.getPhoneNumber() << std::endl
						<< "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
						break;
		} else if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a valid number.\n";
			std::cin.clear(); // 스트림의 오류 상태 클리어
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기
		} else {
			std::cout << "Invalid index." << std::endl;
		}
	}

}

bool isNumber(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void getInput(const std::string& fieldName, std::string& fieldValue) {
    while (1) {
        std::cout << fieldName << ": ";
        if (!std::getline(std::cin, fieldValue) || std::cin.eof()) {
            std::cout << "EOF detected. Exiting the program.\n";
            fieldValue.clear(); // 필드 값을 비워서 이후 로직에 영향을 주지 않도록 함
            break;
        }

        if (fieldName == "Phone Number" && !isNumber(fieldValue)) {
            std::cout << "Enter numbers only for " << fieldName << ".\n";
            continue;
        }

        if (!fieldValue.empty())
            break;
        std::cout << fieldName << " field is empty. Enter it again.\n";
    }
}

void addNewContact(PhoneBook& phoneBook) {
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	std::cout << "\nEnter the following information.\n\n";

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
		std::cout << "\nEnter the command from ADD, SEARCH, or EIXT.\n";
		if (!std::getline(std::cin, command)) {
			if (std::cin.eof()) {
				std::cout << "EOF detected. Exiting the program.\n";
				break;
			}
    }

// C++에서는 문자열을 직접 비교할 수 있다.문자열 리터럴 ADD와 비교함
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