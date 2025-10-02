# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seralves <seralves@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/23 19:05:37 by seralves          #+#    #+#              #
#    Updated: 2025/09/26 19:57:03 by seralves         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
BONUS   = checker

SOURCES = push_swap.c \
	ft_split.c \
	op_push.c \
	op_rev_rotate.c \
	op_rotate.c \
	op_swap.c \
	process_args.c \
	process_args2.c \
	process_args3.c \
	stack_utils.c \
	stack_utils2.c \
	turk_sort.c \
	turk_indexing.c \
	turk_init_nodes.c \
	turk_init_nodes2.c \
	turk_rotate.c \
	utils.c \
	utils2.c

BSOURCES = checker.c \
	b_ft_split.c \
	b_op_push.c \
	b_op_rotate.c \
	b_op_rev_rotate.c \
	b_op_swap.c \
	b_process_args.c \
	b_process_args2.c \
	b_process_args3.c \
	b_stack_utils.c \
	b_stack_utils2.c \
	b_utils.c \
	b_utils2.c \
	get_next_line.c \
	get_next_line_utils.c

OBJS_DIR   = objects
B_OBJS_DIR = b_objects

OBJECTS  = $(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))
BOBJECTS = $(addprefix $(B_OBJS_DIR)/, $(BSOURCES:.c=.o))

HEADERS = push_swap.h b_push_swap.h get_next_line.h

CFLAGS = -Wall -Wextra -Werror
CC     = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "Push_swap compiled."

bonus: .bonus

.bonus: $(BOBJECTS)
	$(CC) $(CFLAGS) $(BOBJECTS) -o $(BONUS)
	@touch .bonus
	@echo "Push_swap bonus compiled."

$(OBJS_DIR) $(B_OBJS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: %.c $(HEADERS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(B_OBJS_DIR)/%.o: %.c $(HEADERS) | $(B_OBJS_DIR)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -rf $(OBJS_DIR) $(B_OBJS_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
