CC = cc
SRC = ft_printf.c ft_printf_utils.c
OBJ = ft_printf.o ft_printf_utils.o 
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@$(CC) -c $(SRC)

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(Name)

re: fclean all

run:
	$(CC) ft_printf.c -L. -lftprintf