# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgandari <lgandari@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/06 11:50:22 by lgandari          #+#    #+#              #
#    Updated: 2024/12/06 13:12:29 by lgandari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

RED		= \033[0;31m
GREEN	= \033[0;32m
NC		= \033[0m

CFLAGS	= -Wall -Werror -Wextra -Iinc
CC		= cc
RM		= rm -f

SRC_DIR		= src/

SRCS	= $(addprefix $(SRC_DIR),	\
	main.c							\
	print_utils.c					\
	save_input.c					\
	setup_simulation.c				\
	clean_simulation.c				\
	solid_utils.c					\
	time_utils.c					\
	set_get.c					\
	run_simulation.c				\
	supervisor.c					\
	)

OBJS	= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compiling philo...$(NC)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)All Objs Deleted.$(NC)"

mem: CFLAGS += -g3 -O2 -fsanitize=address
mem: fclean $(NAME)
	@echo "$(GREEN)Compiling philo with AddressSanitizer...$(NC)"

thread: CFLAGS += -fsanitize=thread -g -O1
thread: fclean $(NAME)
	@echo "$(GREEN)Compiling philo with ThreadSanitizer...$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Everything Deleted.$(NC)"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
