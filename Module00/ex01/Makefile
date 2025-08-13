NAME = PhoneBook

SRC = 
OBJC = ${SRC:.cpp=.o}
RM = rm -rf 
CC = c++
CFLAGE = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

%.o: %.cpp
	${CC} ${CFLAGE} -c  $< -o $@
${NAME}: ${OBJC}
	${CC} ${CFLAGE} ${OBJC} -o ${NAME}

clean:
	${RM} ${OBJC}
fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: clean re all 