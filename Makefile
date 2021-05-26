SRCS	=	main.c					\
			stack.c					\
			stack_utils.c			\
			valid.c					\
			instr.c					\
			order.c					\
			get_instr.c				\
			get_instr_utils.c		\
			out_instr.c				\
			get_args.c				\

OBJS	=	$(SRCS:.c=.o)

BSRCS	=	checker.c				\
			get_next_line.c			\
			get_next_line_utils.c	\
			stack.c					\
			stack_utils.c			\
			valid.c					\
			instr.c					\
			order.c					\
			get_args.c				\

BOBJS	=	$(BSRCS:.c=.o)

CMNSRC	=	stack.c					\
			stack_utils.c			\
			valid.c					\
			instr.c					\
			order.c					\
			out_instr.c				\
			get_args.c				\

CMNOBJ	=	$(CMNSRC:.c=.o)

INC		=	include

SRC		=	source

HEADS	=	$(INC)/push_swap.h		\
			$(INC)/stack.h			\
			$(INC)/get_next_line.h	\
			libft/libft.h			\

NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g

RM		=	rm -f




all:		make_libft $(NAME)

$(NAME):	$(OBJS) $(CMNOBJ) libft/libft.a
			$(CC) $(CFLAGS) -I libft/ -I $(INC)/ -o $@ $^

%.o:		$(SRC)/%.c $(HEADS)
			$(CC) $(CFLAGS) -I libft/ -I $(INC)/ -c $< -o $@

make_libft:
			@$(MAKE) -C libft/

bonus:		make_libft checker

checker:	$(BOBJS) $(CMNOBJ) libft/libft.a
			$(CC) $(CFLAGS) -I libft/ -I $(INC)/ -o $@ $^

clean:
			$(RM) $(OBJS) $(BOBJS)

			@$(MAKE) -C libft/ clean

fclean:		clean
			$(RM) $(NAME) checker
			@$(MAKE) -C libft/ fclean

re:			fclean all

.PHONY:		all make_libft bonus clean fclean re
