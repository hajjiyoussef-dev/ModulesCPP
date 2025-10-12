NAME =  replace

SRC = main.cpp

OBJC = $(SRC:.c=.o)

RM = rm -rf 
CC = c++;
CPPFLAGE = -Wall -Wextra -Werror -std=c++98 

all: ${NAME}

%.o: %.cpp 
	${CC} ${CPPFLAGE} -c $< -o $@ 

${NAME}: ${OBJC}
	${CC} ${CFLAGE} -o ${NAME} ${OBJC}

clean:
	${RM} ${OBJC}

fclean:
	${RM} ${NAME}

re: fclean all