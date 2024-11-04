NAME = fdf
CC = cc
OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra

HEADER = 


SRCS = fdf.c \

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)


%.o: %.c
	$(CC) $(FLAGS) -I $(HEADER) $< -c -o $@
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
