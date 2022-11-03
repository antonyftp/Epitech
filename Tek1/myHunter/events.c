/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Events utils for my_hunter.c
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include "include/Event.h"
#include "include/my.h"
#include "include/struct.h"

void close_window(asset_t *asset)
{
    if (asset->event.type == sfEvtClosed) {
        sfRenderWindow_close(asset->window);
        sfRenderWindow_destroy(asset->window);
    }
}

void manage_mouse_click(asset_t *asset, duck_t *duck)
{
    int x_mouse = asset->event.mouseButton.x;
    int y_mouse = asset->event.mouseButton.y;
    int r = rand() % 800;
    duck->duck_init = (sfVector2f){-110, r};

    if (x_mouse >= duck->duck_vect.x && x_mouse <= duck->duck_vect.x + 110)
        if (y_mouse >= duck->duck_vect.y && y_mouse <= duck->duck_vect.y + 110) {
            sfSprite_setPosition(duck->s_duck, duck->duck_init);
            asset->p_score++;
            my_putstr("TOUCHE");
            my_putchar('\n');
        }
}

void duck_reset(duck_t *duck)
{
    int r = rand() % 800;
    duck->duck_init = (sfVector2f){-110, r};
    duck->duck_vect = sfSprite_getPosition(duck->s_duck);
    if (duck->duck_vect.x > 2030) {
        sfSprite_setPosition(duck->s_duck, duck->duck_init);
    }
}

void duck_clock(duck_t *duck, asset_t *asset, sfVector2f move)
{
    duck->time_move = sfClock_getElapsedTime(duck->clock_move);
    duck->seconds_move = sfTime_asSeconds(duck->time_move);
    duck->time_sprite = sfClock_getElapsedTime(duck->clock_sprite);
    duck->seconds_sprite = sfTime_asSeconds(duck->time_sprite);
    if (duck->seconds_move > 0.01) {
        duck_reset(duck);
        sfSprite_move(duck->s_duck, move);
    sfClock_restart(duck->clock_move);
    }
    if (duck->seconds_sprite > 0.08) {
        asset->rect.left += 110;
        if (asset->rect.left == 660)
            asset->rect.left = 0;
    sfClock_restart(duck->clock_sprite);
    }
}

void analyse_events(asset_t *asset, duck_t *duck)
{
    close_window(asset);
    if (asset->event.type == sfEvtMouseButtonPressed)
        if (asset->event.key.code == sfMouseLeft)
            manage_mouse_click(asset, duck);
}
