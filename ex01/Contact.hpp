#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	// 기본 생성자: Contact의 객체를 기본값인 빈 문자열로 안전하게 초기화하는 목적. 사용자가 빈문자열 쳐도 객체는 정의된 기본 상태가 됨.
	Contact() : firstName(""), lastName(""), nickName(""), 
	phoneNumber(""), darkestSecret("") {}

	// 생성자(초기화). 위에 있는 멤버 변수명과 구분하기 위해 살짝 다르게 지음
	Contact(const std::string& fName, const std::string& lName, const std::string& nick, const std::string& phone, const std::string& secret) 
	: firstName(fName), lastName(lName), nickName(nick), phoneNumber(phone), darkestSecret(secret) {}

	std::string	getFirstName() const { return firstName; }
	std::string	getLastName() const { return lastName; }
	std::string	getNickName() const { return nickName; }
	std::string getPhoneNumber() const { return phoneNumber; }
	std::string getDarkestSecret() const {return darkestSecret; }

};

#endif