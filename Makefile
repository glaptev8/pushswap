# NAME_CHECKER = checker
NAME_PUSH_SWAP = push
NAME_CHECKER = check
LIBFT_A = libft/libft.a
LIBFTPRINTF_A = libftprintf.a
COMP =		gcc -c -o
PUSH_SWAP_H = -I includes/

OBJ_DIR =	obj/
OBJ_DIR_C = obj_c/

SRC_P_DIR =	src/
SRC_O_DIR = overall/
SRC_C_DIR = check/

C_P_FILE =	push_swap.c \
			sort.c \
			ft_oper.c \
			stack_push.c \
			fresh.c \
			ft_oper2.c

C_O_FILE =	clear.c \
			ft_init_stack.c \
			ft_is_num.c \
			ft_print.c \
			getters.c \
			lst.c \
			stack_is_sort.c\
			has_dublicat.c

C_C_FILE =	checker.c \
			finish_checker.c \
			ft_operations.c \
			check_str.c \
			ft_check_step.c \
			valid_check.c \
			ft_operations2.c

C_P_FIND =		$(C_P_FILE:%=$(SRC_P_DIR)%)
C_O_FIND = 		$(C_O_FILE:%=$(SRC_O_DIR)%)
C_C_FIND = 		$(C_C_FILE:%=$(SRC_C_DIR)%)

O_P_FILE =		$(C_P_FILE:%.c=%.o)
O_O_FILE =		$(C_O_FILE:%.c=%.o)
O_C_FILE =		$(C_C_FILE:%.c=%.o)

OBJ_P =		$(addprefix $(OBJ_DIR), $(O_P_FILE))
OBJ_O =		$(addprefix $(OBJ_DIR), $(O_O_FILE))
OBJ_C =		$(addprefix $(OBJ_DIR_C), $(O_C_FILE))

all: $(NAME_PUSH_SWAP) $(NAME_CHECKER)

$(NAME_PUSH_SWAP): $(OBJ_DIR) $(OBJ_P) $(OBJ_O)
	@make -C libft/
	gcc $(LIBFT_A) $(LIBFTPRINTF_A) $(OBJ_O) $(OBJ_P) -o push_swap

$(NAME_CHECKER): $(OBJ_DIR_C) $(OBJ_C)
	gcc $(LIBFT_A) $(LIBFTPRINTF_A) $(OBJ_C) $(OBJ_O) -o checker

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)

$(OBJ_DIR_C):
			@mkdir -p $(OBJ_DIR_C)

$(OBJ_P): $(C_P_FIND)
		@$(MAKE) $(O_P_FILE)

$(OBJ_O): $(C_O_FIND)
		@$(MAKE) $(O_O_FILE)

$(OBJ_C): $(C_C_FIND)
		@$(MAKE) $(O_C_FILE)

$(O_P_FILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_P_DIR)$(@:%.o=%.c)

$(O_O_FILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_O_DIR)$(@:%.o=%.c)

$(O_C_FILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR_C)$@ $(SRC_C_DIR)$(@:%.o=%.c)

clean:
		rm -rf obj obj_c
		@make -C libft/ clean

fclean: clean
		rm -rf ./checker ./push_swap
		@make -C libft/ fclean

re: fclean all

.PHONY: all clean flcean re