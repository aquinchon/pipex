# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquincho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 09:46:38 by aquincho          #+#    #+#              #
#    Updated: 2022/05/13 09:46:41 by aquincho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
NAME_B	= pipex_bonus

INCLUDE	= includes/
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
RM		= rm -f
AR		= ar rcs

LIBFT_PATH = libft/
LIBINC_PATH = libft/includes/

SRCS_PATH		= srcs/
SRCS_FUNCTIONS	= pipex ft_errors ft_exec ft_files
SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .c, $(SRCS_FUNCTIONS)))
SRCS_B_PATH			= srcs/
SRCS_B_FUNCTIONS	= pipex_bonus ft_errors ft_exec ft_files
SRCS_B = $(addprefix $(SRCS_B_PATH), $(addsuffix .c, $(SRCS_B_FUNCTIONS)))

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -I $(LIBINC_PATH) -c $< -o $@

$(NAME): $(OBJS)
	make all -C $(LIBFT_PATH)
	$(CC) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft
	@echo "\033[33;32m=== Compilation pipex \t\t\t\tDONE\e[0m"

$(NAME_B): $(OBJS_B)
	@make all -C $(LIBFT_PATH)
	$(CC) -o $(NAME) $(OBJS_B) -L $(LIBFT_PATH) -lft
	@echo "\033[33;32m=== Compilation pipex bonus \t\t\tDONE\e[0m"

all: $(NAME)

bonus: $(NAME_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT_PATH)
	@echo "\033[33;32m=== Pipex compil files deleted \t\t\t\tDONE\e[0m"

fclean:	clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)
	@echo "\033[33;32m=== Delete pipex exec file \t\t\tDONE\e[0m"

re: fclean all

.PHONY: clean fclean re all bonus
