NAME = libftprintf.a
Header = ft_printf.h
SRCS = ft_atoi.c ft_putstr_fd.c ft_strlen.c ft_itoa.c cat_formates_in_str.c \
        check_valid_str.c convert_hex.c handle_printf.c is_format.c print_hex.c \
		is_format_bonus.c is_flag.c is_space.c ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus : $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c $(Header)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
re: fclean all