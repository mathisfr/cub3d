NAME = Cub3d
LIBMLX	:= ~/MLX42/
CFLAGS = -Wall -Wextra -Werror -g -Ofast
MLX_FLAGS = $(LIBMLX)/libmlx42.a
CC = gcc
LIBFT = libft/libft_enhanced.a
HEADERS	:= -I ./include -I $(LIBMLX)/include

SOURCES = 	main/main.c \
			main/update.c \
			player/key_actions.c \
			raycast/draw_minimap.c \
			pixels/ft_pixel_put.c \
			pixels/ft_rectangle.c \
			pixels/ft_circle.c \
			pixels/ft_line.c\
			parsing/data.c \
			parsing/map_parser.c \
			parsing/map_parser_utils.c \
			parsing/check_map.c \
			parsing/check_map2.c \
			parsing/error.c \
			parsing/parse_fc_color.c \
			parsing/parse_texture_and_color.c \
			parsing/parse_texture.c \
			vector/vector.c \
			vector/vector2.c \
			player/player.c \
			player/player_collider.c \
			player/player_collider2.c \
			player/player_collider3.c \
			player/ft_movement.c \
			raycast/ft_drawline3d.c \
			raycast/raycast.c \
			raycast/dda.c \
			animate/animate.c \
			animate/init_animate.c \


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
	$(CC) $(MLX_FLAGS) -g $(FLAGS) -fsanitize=address $(OBJECTS) $(LIBFT) -lglfw -L "$(HOME)/.brew/opt/glfw/lib/" -o $(NAME)

$(LIBFT) :
	make -C libft/

$(NAME): $(LIBFT) $(SOURCES) $(OBJECTS)
	$(CC) $(MLX_FLAGS) $(FLAGS) $(OBJECTS) $(LIBFT) -lglfw -L "$(HOME)/.brew/opt/glfw/lib/" -o $(NAME)
