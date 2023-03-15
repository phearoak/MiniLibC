##
## EPITECH PROJECT, 2022
## MINILIBC
## File description:
## Makefile
##

SRC			=	./lib/strlen.asm \
				./lib/strchr.asm \
				./lib/strrchr.asm \
				./lib/strcmp.asm \
				./lib/strncmp.asm \
				./lib/strcasecmp.asm \
				./lib/strpbrk.asm \
				./lib/strcspn.asm \
				./lib/strstr.asm \
				./lib/memset.asm \
				./lib/memcpy.asm \
				./lib/memmove.asm \
				./lib/index.asm \
				./lib/rindex.asm \

OBJ			=	$(SRC:.asm=.o)

OBJS		=	$(wildcard tests/*.c)

LIB			=  libasm.so

NASM		=	nasm

LD			=	ld
GCC			=	gcc
NAME		=	test

ASMFLAGS	=	-f elf64
LDFLAGS		=	-shared
LCFLAGS 	=	--coverage -lcriterion

all:	${LIB}

$(LIB):
	nasm ${ASMFLAGS} lib/strlen.asm
	nasm ${ASMFLAGS} lib/strchr.asm
	nasm ${ASMFLAGS} lib/strrchr.asm
	nasm ${ASMFLAGS} lib/strcmp.asm
	nasm ${ASMFLAGS} lib/strncmp.asm
	nasm ${ASMFLAGS} lib/strcasecmp.asm
	nasm ${ASMFLAGS} lib/strpbrk.asm
	nasm ${ASMFLAGS} lib/strcspn.asm
	nasm ${ASMFLAGS} lib/strstr.asm
	nasm ${ASMFLAGS} lib/memset.asm
	nasm ${ASMFLAGS} lib/memcpy.asm
	nasm ${ASMFLAGS} lib/memmove.asm
	nasm ${ASMFLAGS} lib/index.asm
	nasm ${ASMFLAGS} lib/rindex.asm
	ld ${LDFLAGS} -o ${LIB} ${OBJ}

tests_run:
	$(GCC) ${OBJS} -o $(NAME) $(LCFLAGS) -ldl
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) ${NAME}

fclean:	clean
	$(RM) $(LIB)

re: fclean all
