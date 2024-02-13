#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

/* 프라이빗과 퍼블릭 중 어디 const를 넣으면 좋나
프라이빗 변수에 `const`를 사용하고, 퍼블릭의 게터 함수에서 `const`를 빼는 것은 권장되지 않아. ㄱ
`const` 멤버 변수는 객체가 생성될 때 초기화되어야 하며, 이후에는 변경할 수 없어. 

반면, 게터 함수에서 `const` 키워드는 해당 함수가 객체의 상태를 변경하지 않음을 나타내며, 객체가 `const`로 선언되었을 때도 이 함수를 호출할 수 있게 해. 

멤버 변수를 변경할 수 없게 만들기보다는, 게터 함수를 사용해 객체의 상태를 안전하게 읽을 수 있도록 하는 것이 좋아. 게터 함수에 `const`를 붙이는 것을 추천해.
*/


class Contact {
private:
// 클래스 내버 멤버함수
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:
	// 기본 생성자: Contact의 객체를 기본값인 빈 문자열로 안전하게 초기화하는 목적. 사용자가 빈문자열 쳐도 객체는 정의된 기본 상태가 됨. On program start-up, the phonebook is empty and the user is prompted to enter one of three commands. 
	Contact() : firstName(""), lastName(""), nickName(""), 
	phoneNumber(""), darkestSecret("") {}

	// 생성자(초기화). 위에 있는 멤버 변수명과 구분하기 위해 살짝 다르게 지음
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