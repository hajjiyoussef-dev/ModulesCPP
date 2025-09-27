NAME = zombie

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJS = ${SRC:.cpp=.o}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: ${NAME}

%.o: %.cpp Zombie.hpp
	${CXX} ${CXXFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all











