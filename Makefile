# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yachtata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 12:34:09 by yachtata          #+#    #+#              #
#    Updated: 2024/02/08 06:31:29 by yachtata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	\033[0;31m
GREEN	=	\033[0;32m
NC		=	\033[0m

NAME1	= push_swap
NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC1 	= free_functions.c push_swap.c parsing.c apply_instr.c apply_rr.c apply_rrr.c \
begin_sort.c global_sort.c check_sort.c sort_helper.c \
rotation.c a_to_b.c

FILES_O = $(addprefix $(OBJSFD)/, $(SRC1:%.c=%.o))

SRC2 	= free_functions.c checker.c parse_args.c apply_instr.c apply_rr.c apply_rrr.c \
stack_manipulations.c

BONUS_O = $(addprefix $(OBJSFD)/, $(SRC2:%.c=%.o))

OBJSFD 	= objects

HDR 		= -I./
LIBFT_HDR 	= -I./libft/includes
LIB_BINARY	= -L./libft -lft
LIBFT		= libft/libft.a

all: $(LIBFT) $(NAME1)

$(LIBFT):
	@make -C libft re

$(OBJSFD):
	@mkdir $@

$(NAME1): $(FILES_O) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@cc $(CFLAGS) $(FILES_O) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to test$(NC)"

bonus: $(NAME2)

$(NAME2): $(BONUS_O) $(LIBFT)
	@echo "$(GREEN)compiling $@...$(NC)"
	@cc $(CFLAGS) $(BONUS_O) $(LIB_BINARY) -o $@ 
	@echo "$(GREEN)$@ is ready to test$(NC)"

$(OBJSFD)/%.o: %.c | $(OBJSFD) 
	@cc $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

clean:
	@echo "$(RED)deleting object files...$(NC)"
	@rm -f $(FILES_O)
	@rm -rf $(BONUS_O)
	@make -C ./libft clean

fclean: clean
	@echo "$(RED)deleting both executables...$(NC)"
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@make -C ./libft fclean

re: fclean all
.PHONY: all clean fclean re
