NAME = libft.a

SOURCES = ft_atoi.c \
	ft_atol.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_split.c \
	ft_join.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_itoa.c \
	ft_uitoa.c \
	ft_ltoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_lstmap.c \
	ft_strjoinfree.c \


OBJECTS = $(SOURCES:.c=.o)

FLAGS = -Wall -Wextra -Werror -g3
CC = gcc $(FLAGS)

all: $(NAME)

clean:
	@rm -f $(OBJECTS) $(OBJECTS_BONUS)

.c.o: 		
			@$(CC) $(FLAGS) -I./libft -c $< -o $(<:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

$(NAME): $(SOURCES) $(OBJECTS)
	@ar rc libft.a $(OBJECTS)
