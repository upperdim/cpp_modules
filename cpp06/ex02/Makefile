NAME		= identify
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++17

SRCS		= main.cpp Base.cpp A.cpp B.cpp C.cpp
OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
