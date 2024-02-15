# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 16:18:14 by jungmiho          #+#    #+#              #
#    Updated: 2024/02/15 20:20:28 by jungmiho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRC:.cpp=.o)
TARGET = phonebook

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all re fclean clean
