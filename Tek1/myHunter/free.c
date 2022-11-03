/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** free utils for my_hunter.c
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include "include/Event.h"
#include "include/my.h"
#include "include/struct.h"

void destroy(duck_t *duck, asset_t *asset)
{
    sfSprite_destroy(asset->s_background);
    sfTexture_destroy(asset->t_background);
    sfSprite_destroy(duck->s_duck);
    sfText_destroy(asset->score_text);
    sfTexture_destroy(duck->t_duck);
    sfClock_destroy(duck->clock_move);
    sfClock_destroy(duck->clock_sprite);
    sfRenderWindow_destroy(asset->window);
}

void clear_window(duck_t *duck, asset_t *asset)
{
    sfRenderWindow_clear(asset->window, sfBlack);
}

void full_free(duck_t *duck, asset_t *asset)
{
    free(duck);
    free(asset);
}
