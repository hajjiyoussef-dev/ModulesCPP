NAME = horde_of_Zombies


SRC = main.cpp Zombie.cpp

OBJC = ${SRC:.cpp=.o}

RM = rm -rf 

CC = c++
CFLAGE= -Wall -Wextra -Werror -std=c++98

all: ${NAME}

%.o: %.cpp  ./Zombie.hpp
	${CC} ${CFLAGE} -c $< -o $@

${NAME}: ${OBJC}
	${CC} ${CFLAGE} -o ${NAME} ${OBJC}

clean: 
	${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all 
