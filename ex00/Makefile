NAME = bsq

SRC = main.c print_functions.c read_input.c read_map.c search.c st_functions.c support_functions.c validate_map.c fit.c

OBJECTS = main.o print_functions.o read_input.o read_map.o search.o st_functions.o support_functions.o validate_map.o fit.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.SILENT:
