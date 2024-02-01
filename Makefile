NAME = push_swap

CC = cc 

CFLAGS = -Wall -Wextra -Werror

SRCS =  command_rev_rotate.c command_stack_init.c command_stack_push.c command_stack_rotate.c \
        command_stack_swap.c ft_split.c tiny_sort.c push_swap_utils1.c push_swap_process.c \
		stack_init_helpers.c main.c error_handler.c ft_strlen.c ft_putstr_fd.c push_swap_utils.c \
		array_sorter.c push_swap_process2.c\

SRCS_BONUS =

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
# ar rcs $@ $^
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $^

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus