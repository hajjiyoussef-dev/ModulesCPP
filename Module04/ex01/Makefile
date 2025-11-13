NAME = Animal

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp  WrongAnimal.cpp WrongCat.cpp \
		Brain.cpp

OBJC = ${SRC:.cpp=.o}
CFLAGE = -Wall -Wextra -Werror -std=c++98  -fsanitize=address -g3
CC = c++
RM = rm -rf 

all: ${NAME}

%.o: %.cpp Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
	${CC} ${CFLAGE} -c $< -o $@

${NAME}: ${OBJC}
	${CC} ${CFLAGE} ${OBJC} -o ${NAME} 

clean: 
	${RM} ${OBJC}

fclean: clean 
	${RM} ${NAME}

re: fclean all