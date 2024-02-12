CXX = g++
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
