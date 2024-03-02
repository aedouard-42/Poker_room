NAME = Pokeroom

SRCS = srcs/main.cpp\
		srcs/card/Card.cpp\
		srcs/deck/Deck.cpp\
		srcs/board/Board.cpp\
		srcs/hand/Hand.cpp\
		srcs/stack/Stack.cpp\
		srcs/player/Player.cpp\
		srcs/hand/handrecognition.cpp\
		srcs/game/Game.cpp\

INCLUDES = -Isrcs -Isrcs/card -Isrcs/deck -Isrcs/board -Isrcs/hand -Isrcs/stack -Isrcs/player -Isrcs/game -Isrcs/action

CC = clang++

OBJS = ${SRCS:.cpp=.o}

CFLAGS = -Wall -Wextra -Werror -std=c++11 -g

all : $(NAME)

.cpp.o :
		${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.cpp=.o} 

$(NAME): ${OBJS}
		${CC} -o ${NAME} ${OBJS}
clean :
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re:		fclean all

.PHONY: all clean fclean re
