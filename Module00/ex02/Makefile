NAME = Account

SRC =  tests.cpp Account.cpp

OBJC = ${SRC:.cpp=.o}
CC = c++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf 


all: ${NAME}

%.o: %.cpp Account.hpp
	${CC} ${CFLAGS} -c $< -o  $@ 

${NAME}: ${OBJC}
	${CC} ${CFLAGS} ${OBJC} -o ${NAME}

clean:
	${RM} ${OBJC}

fclean: clean
	${RM} ${NAME}

re: fclean all