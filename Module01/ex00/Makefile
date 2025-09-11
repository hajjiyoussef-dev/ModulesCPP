
NAME = zombie

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp

OBJC = ${SRC:.cpp=.o}

CC = c++
CFLAGE = -Wall -Wextra -Werror -std=c++98
RM = rm -rf


all: ${NAME}

%.o: %.cpp zombie.hpp
	${CC} ${CFLAGE} -c $< -o $@ 

${NAME}: ${OBJC}
	${CC} ${CFLAGE} -o ${NAME} ${OBJC}

clean:
	${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all 







