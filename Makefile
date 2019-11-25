NAME_PUSH_SWAP = push
NAME_CHECKER = check
LIBFT_A = libft/libft.a
LIBFTPRINTF_A = ft_printf/libftprintf.a
FLAGS = -Wall -Wextra -Werror
COMP =		gcc -Wall -Wextra -Werror -c -o
PUSH_SWAP_H = -I includes/

OBJ_DIR =	obj/
OBJ_DIR_C = obj_c/
OBJ_DIR_O = obj_o/

SRC_P_DIR =	src/
SRC_O_DIR = overall/
SRC_C_DIR = check/

C_P_FILE =	push_swap.c \
			sort.c \
			ft_oper.c \
			stack_push.c \
			fresh.c \
			ft_oper2.c \
			average2.c \
			average.c \
			average3.c \

C_O_FILE =	clear.c \
			ft_init_stack.c \
			ft_is_num.c \
			ft_print.c \
			getters.c \
			getters2.c \
			lst.c \
			stack_is_sort.c\
			has_dublicat.c \
			stack_a_sort.c

C_C_FILE =	checker.c \
			finish_checker.c \
			ft_operations.c \
			check_str.c \
			ft_check_step.c \
			valid_check.c \
			ft_operations2.c \

C_P_FIND =		$(addprefix $(SRC_P_DIR), $(C_P_FILE))
C_O_FIND = 		$(addprefix $(SRC_O_DIR), $(C_O_FILE))
C_C_FIND = 		$(addprefix $(SRC_C_DIR), $(C_C_FILE))

O_P_FILE =		$(C_P_FILE:%.c=%.o)
O_O_FILE =		$(C_O_FILE:%.c=%.o)
O_C_FILE =		$(C_C_FILE:%.c=%.o)

OBJ_P =		$(addprefix $(OBJ_DIR), $(O_P_FILE))
OBJ_O =		$(addprefix $(OBJ_DIR_O), $(O_O_FILE))
OBJ_C =		$(addprefix $(OBJ_DIR_C), $(O_C_FILE))

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER)

$(NAME_PUSH_SWAP): $(OBJ_DIR) $(OBJ_P) $(OBJ_DIR_O) $(OBJ_O)
	@make -C libft/
	@make -C ft_printf/
	@gcc $(LIBFT_A) $(LIBFTPRINTF_A) $(OBJ_O) $(OBJ_P) -o push_swap
	@echo push_swap create

$(NAME_CHECKER): $(OBJ_DIR_C) $(OBJ_C)
	@gcc $(LIBFT_A) $(LIBFTPRINTF_A) $(OBJ_C) $(OBJ_O) -o checker
	@echo checker create

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(OBJ_DIR_C):
			@mkdir -p $(OBJ_DIR_C)

$(OBJ_DIR_O):
			@mkdir -p $(OBJ_DIR_O)

$(OBJ_DIR)%.o: $(SRC_P_DIR)%.c
			@echo Create: $(@:obj/%=%)
			@gcc $(FLAGS) -c $< -o $@

$(OBJ_DIR_O)%.o: $(SRC_O_DIR)%.c
			@echo Create: $(@:obj/%=%)
			@gcc $(FLAGS) -c $< -o $@

$(OBJ_DIR_C)%.o: $(SRC_C_DIR)%.c
			@echo Create: $(@:obj/%=%)
			@gcc $(FLAGS) -c $< -o $@
clean:
		rm -rf obj obj_c obj_o
		@make -C ft_printf/ clean
		@make -C libft/ clean

fclean: clean
		rm -rf ./checker ./push_swap
		@make -C ft_printf/ fclean
		@make -C libft/ fclean

re: fclean all

.PHONY: all clean flcean re