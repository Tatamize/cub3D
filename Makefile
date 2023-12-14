NAME		=	cub3D

CFLAGS		=	-Wall -Wextra -Werror

DIR_MINI	=	./MLX42
DIR_LIBFT	=	./libft
DIR_OBJ		=	./obj


DIR_HEADER	=	header
DIR_UTIL	=	c_util
DIR_PARSE	=	c_parse
DIR_MOVE	=	c_move
DIR_DRAW	=	c_drawing

SRC_UTIL	= 	$(DIR_UTIL)/get_next_line.c					\
				$(DIR_UTIL)/get_next_line_utils.c			\
				$(DIR_UTIL)/init_data.c						\
				$(DIR_UTIL)/error.c							\
				$(DIR_UTIL)/free.c							\
				$(DIR_UTIL)/print_data.c

SRC_PARSE	= 	$(DIR_PARSE)/parse.c						\
				$(DIR_PARSE)/check.c						\
				$(DIR_PARSE)/check_map.c					\
				$(DIR_PARSE)/check_wall.c					\
				$(DIR_PARSE)/check_map_utils.c				\
				$(DIR_PARSE)/check_and_set_color.c			\
				$(DIR_PARSE)/create_map_list.c

SRC_MOVE	=	$(DIR_MOVE)/player_position.c				\
				$(DIR_MOVE)/player_direction.c				\
				$(DIR_MOVE)/hook_turn.c						\
				$(DIR_MOVE)/hook_move.c						\
				$(DIR_MOVE)/hook.c

SRC_DRAW	=	$(DIR_DRAW)/minimap.c						\
				$(DIR_DRAW)/canvas.c						\
				$(DIR_DRAW)/texture.c						\
				$(DIR_DRAW)/drawing_util.c					\
				$(DIR_DRAW)/drawing.c						\
				$(DIR_DRAW)/ray_util.c						\
				$(DIR_DRAW)/ray.c
	
SRC_MAIN	=	main.c
		
SRC			= 	$(SRC_UTIL) $(SRC_PARSE) $(SRC_MOVE) $(SRC_DRAW) $(SRC_MAIN)
OBJ	=			$(addprefix $(DIR_OBJ)/, $(patsubst %.c, %.o, $(SRC)))
LIBFT_A		=	$(DIR_LIBFT)/libft.a
MINILIB_A	=	libmlx42.a

HEADER		=	$(DIR_HEADER)/*.h

#-------------------------------------------#
BLUE			=	\033[38;5;30m
GREEN			= 	\033[38;5;43m
RED				=	\033[38;5;124m
PINK			= 	\033[38;5;167m
ORANGE			=	\033[38;5;208m
NO_COLOR		=	\033[0m
#-------------------------------------------#

all:  start $(NAME)

libft: $(LIBFT_A)

minilibx: $(MINILIB_A)


%.o: %.c
		gcc $(CFLAGS) -c $< -o $@

$(DIR_OBJ)/%.o: %.c $(HEADER)
		@mkdir -p $(@D)
		gcc -c $(CFLAGS) -Imlx -o $@ $<

$(NAME):$(DIR_OBJ) $(OBJ) $(HEADER) $(LIBFT_A) $(MINILIB_A)
		gcc $(CFLAGS) $(OBJ) $(LIBFT_A) $(MINILIB_A) -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.9/lib/" -o $@	

$(DIR_OBJ):
		@mkdir -p $(DIR_OBJ)/

$(LIBFT_A):
		@cd $(DIR_LIBFT); make ; cd ../

$(MINILIB_A):
		@cd $(DIR_MINI); make ; mv $(MINILIB_A) ../ ; cd ../

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME) $(MINILIB_A) ; cd ./libft; make fclean ; cd ../$(DIR_MINI) ; make clean; cd ../

re: fclean all

start:
		@echo "\033[38;5;208m\t───▄▀▀▀▄▄▄▄▄▄▄▀▀▀▄───    ────────────────────\033[0m"
		@echo "\033[38;5;209m\t───█▒▒░░░░░░░░░▒▒█───    ──────▄▀▄─────▄▀▄───\033[0m"
		@echo "\033[38;5;203m\t────█░░█░░░░░█░░█────    ─────▄█░░▀▀▀▀▀░░█▄───\033[0m"
		@echo "\033[38;5;204m\t─▄▄──█░░░▀█▀░░░█──▄▄─    ─▄▄──█░░░░░░░░░░░█──▄▄\033[0m"
		@echo "\033[38;5;205m\t█░░█─▀▄░░░░░░░▄▀─█░░█    █▄▄█─█░░▀░░┬░░▀░░█─█▄▄█\033[0m"
		@echo "\033[38;5;100m\t    Ⓢ Ⓤ Ⓩ Ⓤ Ⓚ Ⓘ        &        Ⓢ Ⓐ Ⓣ Ⓞ \033[0m"
		@echo "\033[38;5;42m\t            ╭━━━┳╮ ╭┳━━╮╭━━━┳━━━╮\033[0m"
		@echo "\033[38;5;43m\t            ┃╭━╮┃┃ ┃┃╭╮┃┃╭━╮┣╮╭╮┃\033[0m"
		@echo "\033[38;5;44m\t            ┃┃ ╰┫┃ ┃┃╰╯╰╋╯╭╯┃┃┃┃┃\033[0m"
		@echo "\033[38;5;46m\t            ┃╰━╯┃╰━╯┃╰━╯┃╰━╯┣╯╰╯┃\033[0m"
		@echo "\033[38;5;47m\t            ╰━━━┻━━━┻━━━┻━━━┻━━━╯\033[0m"
		@echo "\033[38;5;25m\t             .....unⅎ ǝʌɐɥ.......\033[0m"


play:
		./cub3D maps/basic_map_no_corners.cub
		./cub3D maps/basic_map.cub
		./cub3D maps/basic_map1.cub
		./cub3D maps/jungle1.cub
		./cub3D maps/jungle2.cub
		./cub3D maps/jungle.cub
		./cub3D maps/small.cub
		./cub3D maps/big_maze.cub
		./cub3D maps/big_rectacle_maze.cub
		./cub3D maps/valid_odd_maps/head_random_order.cub
		./cub3D maps/valid_odd_maps/no_space_between.cub
		./cub3D maps/valid_odd_maps/start_position_insmallspace.cub
		./cub3D maps/valid_odd_maps/white_space_in_map.cub

norm:
		norminette $(SRC)

.PHONY: 	all fclean clean re norm