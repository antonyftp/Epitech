/*
** EPITECH PROJECT, 2018
** oui
** File description:
** de ouf
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include "include/Event.h"
#include "include/my.h"
#include "include/struct.h"

int main(int ac, char **av)
{
    sfVideoMode video = {1920, 1080, 32};
    asset_t *asset = malloc(sizeof(asset_t));
    duck_t *duck = malloc(sizeof(asset_t));
    set_duck(duck);
    set_background(asset);
    duck->clock_move = sfClock_create();
    duck->clock_sprite = sfClock_create();
    asset->p_score = 0;
    asset->rect = (sfIntRect){0, 0, 110, 110};
    sfVector2f move = {15, 0};
    asset->window = sfRenderWindow_create(video, "My Hunter",
                                   sfDefaultStyle, NULL);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'&& av[1][2] == '\0') {
        usage_desc();
    }   else
        render_window(duck, asset, move);
    return (0);
}
