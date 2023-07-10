##
## EPITECH PROJECT, 2023
## bsrpg
## File description:
## Makefile
##

CC	=	gcc

SRC	=	./src/main.c	\
		./src/game.c	\
		./src/save_game.c	\
		./src/init/init_rectangle.c	\
		./src/init/init_text.c	\
		./src/init/init_settigs.c	\
		./src/init/init_ship.c	\
		./src/init/init_kaelan.c	\
		./src/menu/init_menu.c	\
		./src/menu/mouse_position.c	\
		./src/menu/button_redirect.c	\
		./src/menu/display_menu.c	\
		./src/menu/credit/credit.c	\
		./src/menu/credit/open_credit.c	\
		./src/menu/back_ship/back_ship.c	\
		./src/menu/settings/fps_manager.c	\
		./src/menu/settings/menu_settings.c	\
		./src/menu/settings/settings_menu.c	\
		./src/menu/settings/size_win_manager.c	\
		./src/menu/settings/song_manager.c	\
		./src/menu/settings/vsync_manager.c	\
		./src/menu/settings/win_settings.c	\
		./src/menu/settings/volume/box.c	\
		./src/menu/settings/volume/center_bare.c	\
		./src/menu/settings/volume/curseur_bare.c	\
		./src/menu/settings/volume/volume_bare.c	\
		./src/menu/settings/exit_button/exit_button.c	\
		./lib/get_position.c	\
		./lib/make_button.c	\
		./lib/make_text.c	\
		./lib/my_strlen.c	\
		./lib/background_sprite.c	\
		./lib/my_getnbr.c	\
		./lib/word_array.c	\
		./lib/file_to_arr.c	\
		./lib/my_strdup.c	\
		./lib/my_put_nbr.c	\
		./lib/my_strcat.c	\
		./lib/my_strcpy.c	\
		./src/game/game.c	\
		./src/game/pnj_colors.c	\
		./src/game/congraluation.c	\
		./src/game/game_init/init_stormtrops.c	\
		./src/game/load_save/load_game.c	\
		./src/game/load_save/load_inv.c	\
		./src/game/interaction.c	\
		./src/game/collision.c	\
		./src/game/game_init/init_game.c	\
		./src/game/game_init/init_inv.c	\
		./src/game/game_init/init_pstat.c	\
		./src/game/moove_player.c	\
		./src/game/minimap.c	\
		./src/game/display_storm.c	\
		./src/game/made_round_rect.c	\
		./src/game/player_level.c	\
		./src/game/menu/escape.c	\
		./src/game/menu/pause_back.c	\
		./src/game/loading/chargement.c	\
		./src/game/loading/confirmation_travel.c	\
		./src/game/inventory/inventaire.c	\
		./src/game/inventory/back_inv.c	\
		./src/game/inventory/item_box.c	\
		./src/game/inventory/const_inv.c	\
		./src/game/inventory/display_stat.c	\
		./src/game/inventory/item_armor.c	\
		./src/game/inventory/shield_update.c	\
		./src/game/attacks/attacks.c	\
		./src/game/attacks/change_saber_position.c	\
		./src/game/attacks/init_weapon.c		\
		./src/game/attacks/attacks_animation.c		\
		./src/game/attacks/special_attack.c		\
		./src/game/attacks/is_collide.c	\
        ./src/game/ennemies/init_ennemies.c     \
		./src/game/ennemies/display_ennemies.c	\

OBJ	=	$(SRC:.c=.o)

CSFML_FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS  =	-Wall -Wextra

CPPFLAGS	=	-I includes

BIN_NAME	=	my_rpg

all:	$(OBJ)
	$(CC) -o $(BIN_NAME) $(OBJ) $(CSFML_FLAGS) $(CFLAGS) -lm -g3

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(BIN_NAME)

re: fclean all

.PHONY: clean fclean re
