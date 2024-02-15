/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:17:46 by jungmiho          #+#    #+#             */
/*   Updated: 2024/02/15 22:51:43 by jungmiho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

std::string Contact::getFirstName() const { 
	return firstName; 
}

std::string Contact::getLastName() const { 
	return lastName; 
}

std::string Contact::getNickName() const { 
	return nickName; 
}

std::string Contact::getPhoneNumber() const { 
	return phoneNumber; 
}
std::string Contact::getDarkestSecret() const { 
	return darkestSecret; 
}



void Contact::setFirstName(std::string str) {
	firstName = str;
}

void Contact::setLastName(std::string str) {
	lastName = str;
}

void Contact::setNickName(std::string str) {
	nickName = str;
}

void Contact::setPhoneNumber(std::string str) {
	phoneNumber = str;
}

void Contact::setDarkestSecrect(std::string str) {
	darkestSecret = str;
}