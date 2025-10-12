NAME = Weapon

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp


OBJC = ${SRC:.cpp=.o}

RM = rm -rf 
CC = c++
CPPFLAGE = -Wall -Wextra -Werror -std=c++98

all: ${NAME}


%.o: %.cpp ./HumanA.hpp ./HumanA.hpp ./Weapon.hpp
	${CC} ${CPPFLAGE} -c $< -o $@

${NAME}: ${OBJC}
	${CC} ${CPPFLAGE} -o ${NAME} ${OBJC}

clean:
	${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all 