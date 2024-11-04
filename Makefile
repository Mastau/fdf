NAME = fdf
CC = cc
OBJS = $(SRCS:.c=.o)
LIBFT = lib/libft/libft.so
MLX = lib/MacroLibX/libmlx.so
FLAGS = -Werror -Wall -Wextra

HEADER = -I lib/libft -I lib/MacroLibX/includes

SRCS = main.c \

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) -lSDL2 $(HEADER) -o $@

$(LIBFT):
	make -C lib/libft/ 
$(MLX):
	make -C lib/MacroLibX/ -j
%.o: %.c
	$(CC) $(FLAGS) $(HEADER) $< -c -o $@
clean:
	@rm -f $(OBJS)


fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean
