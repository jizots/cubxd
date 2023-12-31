NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I./inc
CFLAGS += -I./minilibx
# CFLAGS += -g
# CFLAGS += -fsanitize=address
COPTIONS = -L/usr/local/lib -framework OpenGL -framework AppKit -L/usr/lib -lz

SRCS = main.c\
	parse.c\
	mlx_cub_hub.c\
	parse_element.c\
	parse_map_verify.c\
	draw_map.c\
	raycast.c\
	draw_view.c\
	draw_view_utils.c\
	draw_human.c\
	parse_utils.c\
	mlx_win.c\
	mlx_img.c\
	mlx_draw1.c\
	mlx_draw2.c\
	mlx_draw_bresenham.c\
	raycast_utils.c\
	mlx_cub_hooks.c\
	mlx_cub_init_loop.c\
	mlx_key_status.c\
	free.c\
	error_msg.c\

SRCS_DIR = src/
OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS:%.c=%.o}}

LIBSFT_DIR = ./libsft
LIBSFT_MAKEFILE = $(LIBSFT_DIR)/Makefile
LIBSFT_STATIC = $(LIBSFT_DIR)/libsft.a

MLX_DIR = ./minilibx
MLX_MAKEFILE = $(MLX_DIR)/Makefile
MLX_STATIC = $(MLX_DIR)/libmlx.a

.PHONY: all clean fclean re

all: ${OBJS_DIR} ${NAME}

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) $(LIBSFT_STATIC) $(MLX_STATIC)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBSFT_DIR) -lsft -L$(MLX_DIR) -lmlx $(COPTIONS)

$(LIBSFT_STATIC):
	$(MAKE) -C $(LIBSFT_DIR) ex

$(MLX_STATIC):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBSFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)
	rmdir ${OBJS_DIR} 2>/dev/null || true

fclean: clean
	$(MAKE) -C $(LIBSFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
