/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** window utils for my_hunter.c
*/

#include <stddef.h>
#include <SFML/Graphics.h>
#include "include/Event.h"
#include "include/my.h"
#include "include/struct.h"

void display_sprite(duck_t *duck, asset_t *asset)
{
    sfRenderWindow_setVerticalSyncEnabled(asset->window, sfTrue);
    sfRenderWindow_setFramerateLimit(asset->window, 60);
    sfRenderWindow_drawSprite(asset->window, asset->s_background, NULL);
    sfSprite_setTextureRect(duck->s_duck, asset->rect);
    sfRenderWindow_drawSprite(asset->window, duck->s_duck, NULL);
    sfRenderWindow_drawText(asset->window, asset->score_text, NULL);
    sfRenderWindow_drawText(asset->window, asset->score_number, NULL);
    sfRenderWindow_display(asset->window);
}

void render_window(duck_t *duck, asset_t *asset, sfVector2f move)
{
    while (sfRenderWindow_isOpen(asset->window)) {
        user_interface(duck, asset);
        display_sprite(duck, asset);
        duck_clock(duck, asset, move);
        clear_window(duck, asset);
        user_interface(duck, asset);
        score_display(duck, asset);
        while (sfRenderWindow_pollEvent(asset->window, &asset->event)) {
            analyse_events(asset, duck);
        }
    }
    destroy(duck, asset);
    full_free(duck, asset);
}

void user_interface(duck_t *duck, asset_t *asset)
{
    sfVector2f pos_text = {770, -50};
    asset->score_text = sfText_create();
    asset->font_text = sfFont_createFromFile("assets/game_over.ttf");
    sfText_setString(asset->score_text, "Score : ");
    sfText_setFont(asset->score_text, asset->font_text);
    sfText_setCharacterSize(asset->score_text, 100);
    sfText_setPosition(asset->score_text, pos_text);

}

void score_display(duck_t *duck, asset_t *asset)
{
    sfVector2f pos_score = {900, -50};
    char *p_score_s = my_itoa(asset->p_score);
    asset->score_number = sfText_create();
    asset->font_number = sfFont_createFromFile("assets/game_over.ttf");
    sfText_setString(asset->score_number, p_score_s);
    sfText_setFont(asset->score_number, asset->font_number);
    sfText_setCharacterSize(asset->score_number, 100);
    sfText_setPosition(asset->score_number, pos_score);

}

void usage_desc(void)
{
    my_putstr("DESCRIPTION\n");
    my_putstr("==================================\n");
    my_putstr("Welcome to my_hunter\nmy_hunter is a Duck Hunt like game\n");
    my_putstr("All you need to do is shoot the ducks on the screen\n");
}
