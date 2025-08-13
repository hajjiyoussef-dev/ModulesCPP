NAME = megaphone

SRC = megaphone.cpp
OBJC = ${SRC:.cpp=.o}
CFLAGE = -Wall -Wextra -Werror -std=c++98 
CC = c++
RM = rm -rf 

all: ${NAME}
%.o: %.cpp
	${CC} ${CFLAGE} -c $< -o $@
${NAME}: ${OBJC}
	${CC} ${CFLAGE} ${OBJC} -o ${NAME} 

clean: 
	${RM} ${OBJC}
fclean: clean 
	${RM} ${NAME}
re: fclean all

.PHONY: all re clean
