#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
private:
// 클래스 내버 멤버함수
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	Contact() : firstName(""), lastName(""), nickName(""), 
	phoneNumber(""), darkestSecret("") {}

	Contact(const std::string& fName, const std::string& lName, const std::string& nick, const std::string& phone, const std::string& secret) 
	: firstName(fName), lastName(lName), nickName(nick), phoneNumber(phone), darkestSecret(secret) {}

	// 클래스 멤버 함수(게터 함수)이자 (인라인 함수: 클래스 선언 내에 함수의 전체 정의를 포함시킴)
	std::string	getFirstName() const { return firstName; }
	std::string	getLastName() const { return lastName; }
	std::string	getNickName() const { return nickName; }
	std::string getPhoneNumber() const { return phoneNumber; }
	std::string getDarkestSecret() const {return darkestSecret; }
};

#endif