NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

OBJC = ${SRC:.cpp=.o}

CFLAGE = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
CC = c++
RM = rm -rf 

all: ${NAME}

%.o: %.cpp PmergeMe.hpp
	${CC} ${CFLAGE} -c $< -o $@

${NAME}: ${OBJC}
	${CC} ${CFLAGE} ${OBJC} -o ${NAME} 

clean: 
	${RM} ${OBJC}

fclean: clean 
	${RM} ${NAME}

re: fclean all