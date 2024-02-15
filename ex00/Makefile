# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jungmiho <jungmiho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 16:18:07 by jungmiho          #+#    #+#              #
#    Updated: 2024/02/15 20:20:24 by jungmiho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
OBJS = $(SRC:.cpp=.o)
TARGET = megaphone

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