/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:18:28 by jungmiho          #+#    #+#             */
/*   Updated: 2024/02/15 22:53:49 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int currentSize;

public:
	PhoneBook();
	void 			addContact(const Contact& contact);
	const Contact&	getContact(int index) const;
	int 			getCurrentSize() const;
	std::string 	truncateString(const std::string& str);
	void 			printHeader(const PhoneBook& phoneBook);
	void 			searchContact(const PhoneBook& phoneBook);
	bool 			isNumber(const std::string& str);
	std::string 	trim(const std::string& str);
	void 			getInput(const std::string& fieldName,std::string& fieldValue);
	void 			addNewContact(PhoneBook& phoneBook);
};

#endif
