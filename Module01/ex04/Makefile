NAME =  replace

SRC = main.cpp

OBJC = $(SRC:.cpp=.o)

RM = rm -rf 
CC = c++
CPPFLAGE = -Wall -Wextra -Werror -std=c++98 

all: ${NAME}

%.o: %.cpp 
	${CC} ${CPPFLAGE} -c $< -o $@ 

${NAME}: ${OBJC}
	${CC} ${CPPFLAGE} -o ${NAME} ${OBJC}

clean:
	${RM} ${OBJC}

fclean: clean 
	${RM} ${NAME}

re: fclean all