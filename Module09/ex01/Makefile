NAME = RPN

SRC = main.cpp RPN.cpp

OBJC = ${SRC:.cpp=.o}

CFLAGE = -Wall -Wextra -Werror -std=c++98
CC = c++
RM = rm -rf 

all: ${NAME}

%.o: %.cpp RPN.hpp
	${CC} ${CFLAGE} -c $< -o $@

${NAME}: ${OBJC}
	${CC} ${CFLAGE} ${OBJC} -o ${NAME} 

clean: 
	${RM} ${OBJC}

fclean: clean 
	${RM} ${NAME}

re: fclean all