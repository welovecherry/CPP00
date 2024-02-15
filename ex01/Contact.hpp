/* ************************************************************************** */
/*		  */
/*		::: ::::::::   */
/*   Contact.hpp										:+:   :+:   :+:   */
/*		+:+ +:+ +:+   */
/*   By: jungmiho <jungmiho@student.42.fr>  +#+  +:+	 +#+  */
/*	  +#+#+#+#+#+   +#+  */
/*   Created: 2024/02/15 16:17:53 by jungmiho	 #+#  #+#  */
/*   Updated: 2024/02/15 22:54:02 by jungmiho	 ###   ########.fr   */
/*		  */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickName;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void setFirstName(std::string str);
	void setLastName(std::string str);
	void setNickName(std::string str);
	void setPhoneNumber(std::string str);
	void setDarkestSecrect(std::string str);
};

#endif
