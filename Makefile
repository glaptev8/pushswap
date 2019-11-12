all:
	gcc ./src/*.c ./overall/*.c libft/libft.a libftprintf.a -I ./includes/push_swap.h -o push_swap
