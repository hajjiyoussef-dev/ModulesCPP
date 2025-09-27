NAME = he_this_brain 

SRC = main.cpp

OBJC =  ${SRC:.cpp=.o}

CC = c++
RM = rm -rf
CFLAGES = -Wall -Wextra -Werror -std=c++98

all : ${NAME}

%.o: %.cpp 
	${CC} ${CFLAGES} -c $< -o $@

${NAME}: ${OBJC}
	${CC} ${CFLAGES} -o ${NAME} ${OBJC}

clean:
	${RM} ${OBJC}

fclean: clean 
	${RM} ${NAME}

re: fclean all
