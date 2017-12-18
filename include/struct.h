/*
** EPITECH PROJECT, 2017
** struc_game
** File description:
** struc_game
*/

struct duck_ent
{
        sfTexture *texture_dk;
        sfSprite *sprite_dk;
        sfVector2f dk_position;
        sfVector2f dk_rev;
};
typedef struct duck_ent duck_ent;

struct bg_ent
{
        sfTexture	*texture_bg;
	sfSprite	*sprite_bg;
};
typedef struct bg_ent bg_ent;

struct scope_ent
{
        sfTexture	*texture_scope;
	sfSprite	*sprite_scope;
        sfVector2f      scope_position;
};
typedef struct scope_ent scope_ent;

struct window_ent
{
        sfRenderWindow	*window;
        sfVideoMode	video_mode;
        sfBool          bool;
};
typedef struct window_ent window_ent;

struct event_ent
{
        sfEvent		event;
        sfVector2i	vector_mouse;
        sfIntRect	rect;
        sfClock		*clock;
        sfTime		time;
        sfMusic         *music_awp;
        sfMusic         *music_mj;
        sfMusic         *music_hitmarker;
        sfMusic         *music_pause;
        sfMusic         *music_go;
        sfKeyCode       retry;
        sfKeyCode       resume;
};
typedef struct event_ent event_ent;

struct go_ent
{
        sfTexture	*texture_go;
        sfSprite	*sprite_go;
        sfVector2f      go_position;
};
typedef struct go_ent go_ent;

struct gp_ent
{
        sfTexture	*texture_gp;
        sfSprite	*sprite_gp;
        sfVector2f      gp_position;
};
typedef struct gp_ent gp_ent;

typedef struct gp_ent gp_ent;

struct opa_ent
{
        sfTexture	*texture_opa;
	sfSprite	*sprite_opa;
        sfColor         color_opa;
};
typedef struct opa_ent opa_ent;

struct gr_ent
{
        sfTexture       *texture_gr;
        sfSprite        *sprite_gr;
        sfVector2f      gr_position;
};
typedef struct gr_ent gr_ent;
struct gm_ent
{
        sfTexture       *texture_gm;
        sfSprite        *sprite_gm;
        sfVector2f      gm_position;
        sfTexture       *texture_play;
        sfSprite        *sprite_play;
        sfVector2f      play_position;
        sfTexture       *texture_quit;
        sfSprite        *sprite_quit;
        sfVector2f      quit_position;
        sfTexture       *texture_home;
        sfSprite        *sprite_home;
        sfVector2f      home_position;
};
typedef struct gm_ent gm_ent;
