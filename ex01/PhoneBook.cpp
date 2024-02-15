/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:18:22 by jungmiho          #+#    #+#             */
/*   Updated: 2024/02/15 22:58:48 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	currentSize = 0;
}

void PhoneBook::addContact(const Contact& contact) {
	if (currentSize < 8) {
		contacts[currentSize++] = contact;
	} else {
		for (int i = 1; i < 8; i++) {
			contacts[i-1] = contacts[i];
		}
		contacts[7] = contact;
	}
}

const Contact& PhoneBook::getContact(int index) const {
	return contacts[index];
}

int PhoneBook::getCurrentSize() const {
	return currentSize;
}


// FIXME: 이 함수 전체 98인지 살펴보기??
std::string PhoneBook::truncateString(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + '.';
	else
		return str;
}
// FIXME: 이 함수 전체 98인지 살펴보기??
void PhoneBook::printHeader(const PhoneBook& phoneBook) {

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

}

void PhoneBook::searchContact(const PhoneBook& phoneBook) {
	if (phoneBook.getCurrentSize() == 0) {
		std::cout << "No contacts available.\nPlease ADD a contact first.\n";
		return;
	}

	printHeader(phoneBook);

	int index;
	while (1) {
		std::cout << "Enter the index of the contact to display: \n";
		std::cin >> index;
		// FIXME: good(): 98??
		if (std::cin.good() && index >= 0 && index < phoneBook.getCurrentSize()) {
			const Contact& contact = phoneBook.getContact(index);
				std::cout	<< "\nFirst Name: " << contact.getFirstName() << std::endl
							<< "Last Name: " << contact.getLastName() << std::endl
							<< "Nickname: " << contact.getNickName() << std::endl
							<< "Phone Number: " << contact.getPhoneNumber() << std::endl
							<< "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
							break;
		} else if (std::cin.fail()) {
			std::cout << "Invalid input. Please enter a valid number.\n";
			std::cin.clear(); // 스트림의 오류 상태 클리어
			// FIXME: 아랫줄 공부하기
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 버퍼 비우기
		} else {
			std::cout << "Invalid index." << std::endl;
		}
	}
}

bool PhoneBook::isNumber(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) { // FIXME: cpp98?
			return false;
		}
	}
	return true;
}

std::string PhoneBook::trim(const std::string& str) {
	std::string::size_type first = str.find_first_not_of(' '); // FIXME
	std::string::size_type last = str.find_last_not_of(' ');
	
	if (first == std::string::npos || last == std::string::npos) // FIXME
		return ""; // FIXME : empty??
	
	return str.substr(first, last - first + 1); // FIXME: cpp98?
}


void PhoneBook::getInput(const std::string& fieldName, std::string& fieldValue) {
	while (1) {
		std::cout << fieldName << ": ";
		if (!std::getline(std::cin, fieldValue) || std::cin.eof()) {
			std::cout << "EOF detected. Exiting the program.\n";
			fieldValue.clear();
			break;
		}
		fieldValue = trim(fieldValue);
		if (fieldName == "Phone Number" && !isNumber(fieldValue)) {
			std::cout << "Enter numbers only for " << fieldName << ".\n";
			continue;
		}
		if (!fieldValue.empty())
			break;
		std::cout << fieldName << " field is empty. Enter it again.\n";
	}
}

void PhoneBook::addNewContact(PhoneBook& phoneBook) {
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
	
	std::cout << "\nEnter the following information.\n\n";

	getInput("First Name", firstName);
	getInput("Last Name", lastName);
	getInput("Nickname", nickName);
	getInput("Phone Number", phoneNumber);
	getInput("Darkest Secret", darkestSecret);

	Contact newContact;

	newContact.setFirstName(firstName);
	newContact.setLastName(lastName);
	newContact.setNickName(nickName);
	newContact.setPhoneNumber(phoneNumber);
	newContact.setDarkestSecrect(darkestSecret);
	
	phoneBook.addContact(newContact);

	std::cout << "New contact added successfully.\n\n";
}