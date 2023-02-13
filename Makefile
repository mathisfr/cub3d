NAME = Cub3d
LIBMLX	:= ~/MLX42/
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = $(LIBMLX)/libmlx42.a
CC = gcc
LIBFT = libft/libft_enhanced.a
HEADERS	:= -I ./include -I $(LIBMLX)/include

SOURCES = 	main.c \
			data.c \
			player.c \
			map_parser.c \
			map_parser_utils.c \
			check_map.c \
			error.c \
			

SOURCES_BONUS = 

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)


all: libmlx $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

clean:
	make clean -C libft/
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

bonus: $(NAME)

.c.o: 		
			@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

re: fclean $(NAME)

sanitize: $(LIBFT) $(SOURCES) $(OBJECTS)
	$(CC) $(FLAGS) -fsanitize=address $(OBJECTS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

debug: $(LIBFT) $(SOURCES) $(OBJECTS)
	$(CC) $(MLX_FLAGS) -g $(FLAGS) -fsanitize=address $(OBJECTS) $(LIBFT) -lglfw -L "/Users/lloison/.brew/opt/glfw/lib/" -o $(NAME)

$(LIBFT) :
	make -C libft/

$(NAME): $(LIBFT) $(SOURCES) $(OBJECTS)
	$(CC) $(MLX_FLAGS) $(FLAGS) $(OBJECTS) $(LIBFT) -lglfw -L "/Users/lloison/.brew/opt/glfw/lib/" -o $(NAME)
