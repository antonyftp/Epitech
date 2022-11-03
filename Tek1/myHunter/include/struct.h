/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Struct.h for my_hunter.c
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct asset {
    sfTexture *t_background;
    sfSprite *s_background;
    sfRenderWindow* window;
    sfEvent event;
    sfIntRect rect;
    sfText *score_text;
    sfFont *font_text;
    sfText *score_number;
    sfFont *font_number;
    int p_score;
} asset_t;

typedef struct duck {
    sfSprite *s_duck;
    sfTexture *t_duck;
    sfClock *clock_move;
    sfTime time_move;
    float seconds_move;
    sfClock *clock_sprite;
    sfTime time_sprite;
    float seconds_sprite;
    sfVector2f duck_init;
    sfVector2f duck_vect;
    int nb_sprite;
} duck_t;

void set_background(asset_t *asset);
void set_duck(duck_t *duck);
void close_window(asset_t *asset);
void manage_mouse_click(asset_t *asset, duck_t *duck);
void duck_reset(duck_t *duck);
void duck_clock(duck_t *duck, asset_t *asset, sfVector2f move);
void analyse_events(asset_t *asset, duck_t *duck);
void display(duck_t *duck, asset_t *asset);
void destroy(duck_t *duck, asset_t *asset);
void full_free(duck_t *duck, asset_t *asset);
void render_window(duck_t *duck, asset_t *asset, sfVector2f move);
void usage_desc(void);
void user_interface(duck_t *duck, asset_t *asset);
void score_display(duck_t *duck, asset_t *asset);
void clear_window(duck_t *duck, asset_t *asset);

#endif
