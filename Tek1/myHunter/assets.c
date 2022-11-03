/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Assets utils for my_hunter.c
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include "include/Event.h"
#include "include/my.h"
#include "include/struct.h"

void set_background(asset_t *asset)
{
    asset->t_background = sfTexture_createFromFile("assets/Background.png", NULL);
    asset->s_background = sfSprite_create();
    sfSprite_setTexture(asset->s_background, asset->t_background, sfTrue);
}

void set_duck(duck_t *duck)
{
    duck->t_duck = sfTexture_createFromFile("assets/Pterodactyle.png", NULL);
    duck->s_duck = sfSprite_create();
    sfSprite_setTexture(duck->s_duck, duck->t_duck, sfTrue);
}
