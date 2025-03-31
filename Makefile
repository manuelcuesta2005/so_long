# Nombre del ejecutable
NAME = so_long

# Colores para salida en consola
GREEN  = \033[0;32m
RED    = \033[0;31m
YELLOW = \033[0;33m
RESET  = \033[0m

# Compilador y flags
CC     = cc
CFLAGS = -Wall -Wextra -Werror

# Directorios de librerías
LIBFT_DIR  = libft
PRINTF_DIR = ft_printf
MLX_DIR    = mlx

# Librerías
LIBFT  = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
MLX    = $(MLX_DIR)/libmlx.a
LIB    = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -no-pie

# Archivos fuente
SRC = get_next_line/get_next_line.c \
      src/map_playable.c \
      src/maps.c \
      src/memory.c \
      src/game.c \
      src/player.c \
      src/utils.c \
	  src/window.c \
      src/so_long.c

OBJ = $(SRC:.c=.o)

# Regla principal
all: load $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(MLX) $(OBJ)
	@echo "$(YELLOW)🚀 Compilando tu proyecto...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(LIB) -o $(NAME)
	@echo "$(GREEN)✅ Compilación exitosa!$(RESET)"

# Compilación de archivos objeto
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

# Compilación de librerías externas
$(LIBFT):
	@make -C $(LIBFT_DIR) > /dev/null

$(PRINTF):
	@make -C $(PRINTF_DIR) > /dev/null

$(MLX):
	@make -C $(MLX_DIR) > /dev/null

# Animación de carga
load:
	@echo "$(YELLOW)Preparando compilación...$(RESET)"
	@i=0; while [ $$i -lt 11 ]; do \
		printf "\r🛠️ Compilando... [%-10s]" $$(printf "%0.s#" $$(seq 1 $$i)); \
		sleep 0.2; \
		i=$$((i+1)); \
	done; echo ""
	@sleep 2
	@echo "$(GREEN)✨ ¡Listo para compilar!$(RESET)"

# Limpieza de archivos objeto
clean:
	@echo "$(RED)🗑️ Borrando archivos objeto...$(RESET)"
	@rm -f $(OBJ)
	@make -C $(MLX_DIR) clean > /dev/null
	@make -C $(LIBFT_DIR) clean > /dev/null
	@make -C $(PRINTF_DIR) clean > /dev/null
	@sleep 2
	@echo "$(GREEN)✔ Limpieza completada!$(RESET)"

# Limpieza total
fclean: clean
	@echo "$(RED)💀 Eliminando ejecutable y librerías...$(RESET)"
	@rm -f $(NAME)
	@make -C $(MLX_DIR) clean > /dev/null
	@make -C $(LIBFT_DIR) fclean > /dev/null
	@make -C $(PRINTF_DIR) fclean > /dev/null
	@sleep 2
	@echo "$(GREEN)✔ Eliminación completada!$(RESET)"

# Reconstrucción total
re: fclean all

.PHONY: all clean fclean re load
