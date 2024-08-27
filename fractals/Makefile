##
## EPITECH PROJECT, 2023
## epitech
## File description:
## desc
##

LIBNAME	=	fractals

SRC	=	src/utils/all_linked_list/doubly_linked_list/creat_new_node.c\
src/utils/all_linked_list/doubly_linked_list/delete_at_the_beginning.c\
src/utils/all_linked_list/doubly_linked_list/delete_at_the_end.c\
src/utils/all_linked_list/doubly_linked_list/delete_element.c\
src/utils/all_linked_list/doubly_linked_list/free_list.c\
src/utils/all_linked_list/doubly_linked_list/insert_at_the_beginning.c\
src/utils/all_linked_list/doubly_linked_list/insert_at_the_end.c\
src/utils/all_linked_list/doubly_linked_list/print_list.c\
src/utils/all_linked_list/doubly_linked_list/print_reverse_list.c\
src/utils/binary_tree_functions/assembly_tree.c\
src/utils/binary_tree_functions/tree.c\
src/utils/binary_tree_functions/breadth_first_search.c\
src/utils/binary_tree_functions/clean_tree.c\
src/utils/binary_tree_functions/count_tree_nodes.c\
src/utils/binary_tree_functions/depth_first_search.c\
src/utils/binary_tree_functions/free_dooubly_linked_list.c\
src/utils/binary_tree_functions/join_tree.c\
src/utils/binary_tree_functions/print_tree.c\
src/utils/clean_str.c\
src/utils/count_word.c\
src/utils/disp_tab.c\
src/utils/err_mini_printf.c\
src/utils/err_putchar.c\
src/utils/err_putstr.c\
src/utils/free_f.c\
src/utils/free_2d_array.c\
src/utils/free_3d_array.c\
src/utils/is_anum.c\
src/utils/is_char.c\
src/utils/is_digit.c\
src/utils/is_empty_line.c\
src/utils/is_integer.c\
src/utils/is_sign.c\
src/utils/mini_printf.c\
src/utils/my_checker.c\
src/utils/my_getnbr.c\
src/utils/my_putchar.c\
src/utils/my_putnbr.c\
src/utils/my_putstr.c\
src/utils/my_strcat.c\
src/utils/my_strcmp.c\
src/utils/my_strcpy.c\
src/utils/my_strdup.c\
src/utils/my_strlen.c\
src/utils/my_strncmp.c\
src/utils/open_file.c\
src/utils/read_file.c\
src/utils/split.c\
src/utils/tab_len.c\

PROJECT_SRC	=	src/fractals/handling_errors.c\
src/fractals/handling_iterations.c\
src/fractals/big_alloc.c\
src/fractals/handling_fractals.c\

OBJ	=	$(SRC:.c=.o)

autre 	= 	*~	\
		*.log	\
		a.out	\
		*.gcov	\
		*.gcno	\
		*.gcda	\
		*.cor

all	: 	$(LIBNAME)

$(LIBNAME):	$(SRC)
		gcc -o $(LIBNAME) $(SRC) $(PROJECT_SRC) src/main.c -g3 -g -lm -pg

clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(LIBNAME) $(autre) 	unit_tests

re:		fclean all

unit_tests :	fclean $(LIBNAME)
	     	gcc $(SRC) $(PROJECT_SRC) tests/test/utils/*.c \
		tests/test/project_test/*.c -o unit_tests \
		-coverage -lcriterion -lgcov

tests_run :	unit_tests
		./unit_tests
		gcovr
		gcovr --exclude tests/test/
		gcovr --exclude tests/test/ --branches
