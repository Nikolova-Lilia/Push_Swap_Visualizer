NAME = push_swap
SOURCES = fts_split.c fts_split2.c fts_free.c \
fts_swap.c fts_rotate.c fts_rev_rotate.c fts_push.c \
fts_for_nodes.c fts_calculate_rotations.c \
fts_stack_sorting.c fts_about_numbers.c fts_find_nbr.c \
fts_rot_stack.c fts_main_and_push.c fts_cases.c

SRC_OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

DEPS = push_swap.h
RM = rm -f

all: $(NAME)
.PHONY: all clean fclean re

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRC_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(SRC_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all