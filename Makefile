NAME = so_long

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
RESET = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
PRINTF_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

SRC = so_long.c src/maps.c get_next_line/get_next_line.c src/utils.c
SRC_OBJS = $(SRC:.c=.o)

all: load $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(SRC_OBJS)
	@echo "$(YELLOW)🚀 Compilando tu proyecto...$(RESET)"
	@$(CC) $(CFLAGS) $(SRC_OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $(NAME)
	@echo "$(GREEN)✅ Compilación exitosa!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

load:
	@echo "$(YELLOW)Preparando compilación...$(RESET)"
	@i=0; while [ $$i -lt 10 ]; do \
		printf "\r🛠️ Compilando... [%-10s]" $$(printf "%0.s#" $$(seq 1 $$i)); \
		sleep 0.1; \
		i=$$((i+1)); \
	done; echo ""
	@echo "$(GREEN)✨ ¡Listo para compilar!$(RESET)"

load_error:
	@echo "$(RED)💀 Eliminando objetos...$(RESET)"
	@i=0; while [ $$i -lt 10 ]; do \
		printf "\r🧹🗑️ Borrando... [%-10s]" $$(printf "%0.s#" $$(seq 1 $$i)); \
		sleep 0.1; \
		i=$$((i+1)); \
	done; echo ""
	@echo "$(GREEN)✨ ¡Se han eliminado los archivo :D!$(RESET)"

clean: load_error
	@echo "$(RED)🗑️ Borrando archivos objeto...$(RESET)"
	@rm -f $(SRC_OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@echo "$(GREEN)✔ Limpieza completada!$(RESET)"

fclean: load_error clean
	@echo "$(RED)💀 Eliminando ejecutable...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@echo "$(GREEN)✔ Eliminación completada!$(RESET)"

re: fclean all

.PHONY: all clean fclean re load
