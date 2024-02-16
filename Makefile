##
## EPITECH PROJECT, 2022
## B-PSU-200-LYN-2-1-minishell1-tharek.akaichi
## File description:
## Makefile
##

CC	= gcc

RM	= rm -rf

NAME	= mysh

SRCS	= $(wildcard ./src/*.c) $(wildcard ./primary_function/*.c)

OBJS	= $(SRCS:.c=.o)

CFLAGS	+=  -Wextra -Wall -ansi -pedantic -g3 -Iinclude/

all:	$(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
