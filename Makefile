##
## Enzo Morel, 2024
## MODULAR C
## File description:
## Makefile
##

NAME	=	examples

RM	=	rm -f

IDIR	=	include/

CC	=	gcc

CFLAGS	+=	-I $(IDIR)
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-Wpedantic -Wno-long-long

SRCS_DIR	=	src/
SRCS_FILES	=	array.c		\
			examples.c	\
			new.c		\
			vertex.c

SRCS	=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
