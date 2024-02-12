#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>


class PhoneBook {
private:
	Contact	contacts[8]; // 이 부분은 Contact 클래스에서 초기화하기 때문에 여기서는 초기화 안함.
	int		currentSize;

public:
	PhoneBook() : currentSize(0) {} // 기본 생성자

	void addContact(const Contact& contact) {
		if (currentSize < 8) {
			contacts[currentSize] = contact; // 연락처 추가
			currentSize++;
		} else {
			// 배열이 꽉 찼을 경우, 가장 오래된 연락처를 교체
			for (int i = 1; i < 8; i++) {
				contacts[i-1] = contacts[i];
			}
			contacts[7] = contact;
		}
	}

	// 필요한 경우 연락처 검색 및 기타 기능을 여기에 추가

	
    // 인덱스에 해당하는 연락처를 반환하는 함수
    const Contact& getContact(int index) const {
        return contacts[index];
    }
    
    // 현재 저장된 연락처의 수를 반환하는 함수
    int getCurrentSize() const {
        return currentSize;
    }
	
};


#endif