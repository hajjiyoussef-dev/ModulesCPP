NAME = PhoneBook

SRC = Contact.cpp PhoneBook.cpp main.cpp
OBJC = ${SRC:.cpp=.o}
RM = rm -rf 
CC = c++
CFLAGE = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address 

all: ${NAME}

%.o: %.cpp Contact.h PhoneBook.h
	${CC} ${CFLAGE} -c  $< -o $@

${NAME}: ${OBJC}
	${CC} ${CFLAGE} ${OBJC} -o ${NAME}

clean:
	${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: clean re all 