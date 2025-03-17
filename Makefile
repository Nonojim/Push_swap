#sources files
SRC = utils.c radix.c push_swap.c instructions.c instructions_unused.c instructions_unused_2.c
#append .o to each .c files in the SRC
#OBJS := $(SRC:%.c=%.o)
OBJS = ${SRC:.c=.o}
#build target name
NAME = push_swap
#compiler
CC = gcc
#compiler flags
CCFLAGS = -Wall -Wextra -Werror
#include directory == dossier includes
INC_DIR = .
#preprocessor flag
CPPFLAGS = -I $(INC_DIR)
#rm
RM = rm -f

#first rull is always "all" she is calling $(NAME)
all: $(NAME)
#NAME
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
# "%.o" rule compie .c file into corresponding .o file
# "%" is a wildcard for "name of the files without extension"
# $@ = target, here target = .o "$<" = first dependencies here = .c
%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<
#clean delete all .o files
clean:
	$(RM) $(OBJS)
#after executing clean delete the lib
fclean: clean
	$(RM) $(NAME)
#delete everything then re create it
re: fclean all
#phony targets
.PHONY: all clean fclean re
