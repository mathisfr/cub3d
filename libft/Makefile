NAME = libft_enhanced.a

SOURCES = ft_printf.c \
	ft_printf_helper.c \
	convert_utils.c \
	convert_c.c \
	convert_di.c \
	convert_p.c \
	convert_s.c \
	convert_u.c \
	convert_percent.c \
	convert_x.c \
	sstring.c \
	flags.c \
	generate_flags.c \
	gnl/get_next_line.c

SOURCES_BONUS = 

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror
LFLAGS		= -L./libft -lft
CC = gcc 

all: $(NAME)

clean:
	@make clean -C libft/
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)
bonus: $(NAME)

.c.o: 		
			@$(CC) $(FLAGS) -I./libft -c $< -o $(<:.c=.o)

re: fclean $(NAME)

libft/libft.a :
	@make -C libft/
	@cp libft/libft.a $(NAME)

$(NAME): libft/libft.a $(SOURCES) $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)
