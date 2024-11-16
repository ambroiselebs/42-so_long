NAME        = so_long
CC          = cc
CFLAGS      = -O3
INCLUDES    = -Iincludes/mlx -Iincludes/mlx_linux -Iincludes/Libft -Iincludes/ft_printf/include
LIBS        = -Lincludes/mlx -lmlx -lX11 -lXext -lXrandr -lm \
              -Lincludes/Libft -lft \
              -Lincludes/ft_printf -lftprintf
SRC         = main.c \
              src/exit_game/exit.c \
              src/init/window_init.c src/init/program_init.c \
              src/map/map_init.c src/map/map_update.c \
              src/player/player_init.c src/player/player_gesture.c \
              includes/gnl/get_next_line.c
OBJ         = $(SRC:.c=.o)
LIBFT       = includes/Libft/libft.a
FT_PRINTF   = includes/ft_printf/libftprintf.a
MLX         = includes/mlx/libmlx.a

all: $(LIBFT) $(FT_PRINTF) $(MLX) $(NAME)

$(LIBFT):
	@make -C includes/Libft

$(FT_PRINTF):
	@make -C includes/ft_printf

$(MLX):
	@make -C includes/mlx

$(NAME): $(OBJ)
	@echo "Linking $(NAME)"
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make -C includes/Libft clean
	@make -C includes/ft_printf clean
	@make -C includes/mlx clean

fclean: clean
	rm -f $(NAME)
	@make -C includes/Libft fclean
	@make -C includes/ft_printf fclean
	@make -C includes/mlx clean

re: fclean all

run: $(LIBFT) $(FT_PRINTF) $(MLX) $(NAME)
	./$(NAME) maps/test2.ber
	make fclean

.PHONY: all clean fclean re