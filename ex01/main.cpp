/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:18:00 by jungmiho          #+#    #+#             */
/*   Updated: 2024/02/15 22:38:35 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (1) {
		std::cout << "\nEnter the command from ADD, SEARCH, or EXIT.\n";
		if (!std::getline(std::cin, command)) {
			if (std::cin.eof()) { // FIXME
				std::cout << "EOF detected. Exiting the program.\n";
				break;
			}
		}
		if (command == "ADD") {
			phoneBook.addNewContact(phoneBook);
		} else if (command == "SEARCH") {
			phoneBook.searchContact(phoneBook);
		} else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command. Enter again!" << std::endl;
		}
	}
	return 0;
}
