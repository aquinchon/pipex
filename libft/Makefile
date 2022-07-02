NAME = libft.a

SRCS_PATH = ./
SRCS_FUNCTIONS = ft_split ft_strjoin ft_calloc ft_strlen ft_strncmp \
ft_strchr ft_split_utils ft_strdup
#SRCS_FUNCTIONS = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint \
ft_strlen ft_memset ft_bzero ft_memcpy	ft_memmove ft_strlcpy ft_strlcat \
ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim \
ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd \
ft_putendl_fd ft_putnbr_fd

BONUS_PATH = ./
BONUS_FUNCTIONS = ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast \
ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

PRINTF_PATH = ./ft_printf/
PRINTF_FUNCTIONS = ft_printf ft_process_conv ft_printutils ft_printxnbr \
ft_printchar ft_printnbr ft_printptr ft_printunbr

GNL_PATH = ./get_next_line/
GNL_FUNCTIONS = get_next_line

SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .c, $(SRCS_FUNCTIONS)))
BONUS_SRCS = $(addprefix $(BONUS_PATH), $(addsuffix .c, $(BONUS_FUNCTIONS)))
PRINTF_SRCS = $(addprefix $(PRINTF_PATH), $(addsuffix .c, $(PRINTF_FUNCTIONS)))
GNL_SRCS = $(addprefix $(GNL_PATH), $(addsuffix .c, $(GNL_FUNCTIONS)))

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)

HEAD_PATH = ./includes/

RM = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar cr

.c.o:
	$(CC) $(CFLAGS) -c -I $(HEAD_PATH) $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[33;32m=== compilation libft \t\t\t\tDONE\e[0m"

bonus: $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)
	@echo "\033[33;32m=== compilation libft lists \t\t\t\tDONE\e[0m"

printf: $(PRINTF_OBJS)
	$(AR) $(NAME) $(PRINTF_OBJS)
	ranlib $(NAME)
	@echo "\033[33;32m=== compilation libft printf \t\t\t\tDONE\e[0m"

gnl: $(GNL_OBJS)
	$(AR) $(NAME) $(GNL_OBJS)
	ranlib $(NAME)
#	@echo "\033[33;32m=== compilation libft get_next_line \t\t\tDONE\e[0m"

all: $(NAME) gnl
#all:	$(NAME) bonus printf gnl

clean:
	$(RM) $(OBJS) $(GNL_OBJS)
#	$(RM) $(BONUS_OBJS)
#	$(RM) $(PRINTF_OBJS)
#	$(RM) $(GNL_OBJS)
	@echo "\033[33;32m=== delete compil files libft \t\t\tDONE\e[0m"

fclean:	clean
	$(RM) $(NAME)
	@echo "\033[33;32m=== delete name files libft \t\t\tDONE\e[0m"

re: fclean all

.PHONY: clean fclean re all bomus