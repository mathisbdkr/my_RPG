/*
** EPITECH PROJECT, 2023
** B-MUL-200-PAR-2-1-myrpg-edward.lalande
** File description:
** game_struct
*/

#ifndef GAME_STRUCT_H_
    #define GAME_STRUCT_H_

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>

    #define NB_MAP 5
    #define NB_TXT_PAUSE 4
    #define NB_QUEST 2
    #define NB_ENNEMIES 2
    #define NB_INV 28
    #define NB_STATS 4
    #define NB_STAR 300
    #define QUEST game->quest[game->index_quest]
    #define FRAME_WIDTH  96 / 3
    #define FRAME_HEIGHT 128 / 4
    #define KAELAN "src/assets/sprite/jedi_kaelan.png"

// STRUCT //

typedef struct s_quest quest_t;
typedef struct s_chatbox chatbox_t;

enum{VIDE, BLASTER1, BLASTER2, SABRE, SABRE1, SABRE2,
    SABRE3, FEET_ST, LEG_ST, CHEST_ST, HEAD_ST};

enum{GUN, ARMOR, SWORD, RIEN};

static char *const stat_txt[NB_STATS] = {
    "life : ",
    "xp : ",
    "attack damage : ",
    "shield : ",
};

static char *const item_sprite[11] = {
    "src/assets/item/vide.png",
    "src/assets/item/blaster.png",
    "src/assets/item/blaster_2.png",
    "src/assets/item/young_slayer_2000.png",
    "src/assets/item/sabre_bleu.png",
    "src/assets/item/sabre_vert.png",
    "src/assets/item/sabre_sith.png",
    "src/assets/item/feet_st.png",
    "src/assets/item/leg_st.png",
    "src/assets/item/chest_st.png",
    "src/assets/item/head_st.png",
};

static char *const back_map_path[NB_MAP] = {
    "map/start_back.png",
    "map/tatooine_back.png",
    "map/hoth_back.png",
    "map/death_back.png",
};

static char *const load_back[NB_MAP] = {
    "src/assets/load/yavin.jpg",
    "src/assets/load/tatooine.jpg",
    "src/assets/load/hoth.png",
    "src/assets/load/death.jpg",
};

static char *const map_path[NB_MAP] = {
    "map/start.png",
    "map/tatooine.png",
    "map/hoth.png",
    "map/death.jpg",
};

static char *const map_music[NB_MAP] = {
    "src/song/yavin.ogg",
    "src/song/tatooine.ogg",
    "src/song/hoth.ogg",
    "src/song/hoth.ogg",
};

static char *const txt_travel[NB_MAP] = {
    "to go on yavin 4\npresse the key E",
    "to go on tatooine\npresse the key E",
    "to go on hoth\npresse the key E",
    "to go on death star\npresse the key E",
};

static const sfVector2f start_coord[NB_MAP] = {
    {-600, -750},
    {-1250, -800},
    {-1250, -800},
    {-1250, -800},
};

static char *const pause_txt[NB_TXT_PAUSE] = {
    "back to game",
    "settings",
    "back to menu",
    "back to desktop",
};

static char *const quest_file[NB_QUEST] = {
    "./quest/tutorial.txt",
    "./quest/kill_darth_robin.txt",
};

static char *const ennemy_file[NB_ENNEMIES] = {
    "./src/assets/sprite/dark_robin_head.png",
};

static char *const ennemy_name[NB_ENNEMIES] = {
    "dark robin",
};


struct s_chatbox {
    sfRectangleShape *rect;
    sfText *text;
    sfVector2f pos;
};

struct s_quest {
    int index_dialogue;
    char **file;
    struct s_chatbox *chat;
};

struct inv_t {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfSprite *item;
    int item_pick;
    int damage;
    int type;
};

struct attacks_t {
    sfSprite *weapon_sprite;
    sfTexture *weapon_texture;
    sfVector2f weapon_pos;
    sfVector2f weapon_scl;
    sfClock *clock;
    int mode;
    int anim;
    int direction;
    float rotate;
    int round_count;
};

struct minimap_t {
    sfSprite *minimap;
    int active;
};

struct player_stat_t {
    int xp;
    int life;
    int atk_dammage;
    int total_atk;
    int shield;
    int level;
};

struct s_stormtrooper {
    sfRectangleShape *shot;
    sfMusic* shot_noise;
    sfVector2f pos_shoot;
};

struct s_ennemies {
    sfSprite *ennemies;
    sfRectangleShape *filled_life;
    sfTexture *ennemies_texture;
    sfRectangleShape *square;
    sfVector2f pos;
    sfRectangleShape *name_case;
    sfText *name;
    int life;
    int atk_dmg;
};

struct game_t {
    sfRenderWindow *window;
    sfVector2f mouse_pos;
    sfSprite *player_sprite;
    sfVector2f pos_player;
    sfClock *clock;
    int map_index;
    int end;
    sfEvent event;
    sfMusic *music;
    sfSprite *map;
    sfTexture *texture_back_map;
    int pause;
    int speed;
    int new_map;
    int index_quest;
    quest_t **quest;
    struct inv_t **inv;
    int item_pick;
    int item_pos;
    int frame;
    int direction;
    int item_select;
    sfSprite *storm;
    sfTexture *storm_texture;
    sfVector2f pos_storm;
    struct attacks_t attacks;
    struct minimap_t *minimap;
    struct player_stat_t *pstat;
    struct s_ennemies *ennemies;
};


#endif /* !GAME_STRUCT_H_ */
