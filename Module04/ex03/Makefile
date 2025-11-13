NAME = recap

SRC = main.cpp AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  MateriaSource.cpp \

OBJC = ${SRC:.cpp=.o}
CFLAGE = -Wall -Wextra -Werror -std=c++98  -fsanitize=address -g3
CC = c++
RM = rm -rf 

all: ${NAME}

%.o: %.cpp AMateria.hpp  Character.hpp  Cure.hpp  Ice.hpp  ICharacter.hpp  IMateriaSource.hpp  MateriaSource.hpp
	${CC} ${CFLAGE} -c $< -o $@

${NAME}: ${OBJC}
	${CC} ${CFLAGE} ${OBJC} -o ${NAME} 

clean: 
	${RM} ${OBJC}

fclean: clean 
	${RM} ${NAME}

re: fclean all