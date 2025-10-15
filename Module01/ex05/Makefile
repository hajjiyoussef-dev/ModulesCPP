NAME = Harl


SRC = main.cpp Harl.cpp

OBJC = ${SRC:.cpp=.o}

RM = rm -rf
CPPFALGE = -Wall -Wextra -Werror -std=c++98
CPPC = c++

all: ${NAME}

%.o: %.cpp ./Harl.hpp
	${CPPC} ${CPPFALGE} -c $< -o $@

${NAME}: ${OBJC}
	${CPPC} ${CPPFALGE} -o ${NAME} ${OBJC}

clean:
	${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean re all
