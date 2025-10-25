NAME = BSP

SRC = main.cpp Fixed.cpp Point.cpp

OBJS = ${SRC:.cpp=.o}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: ${NAME}

%.o: %.cpp Fixed.hpp Point.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all