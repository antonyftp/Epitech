/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** Sprite.h
*/

#ifndef SFML_SPRITE_H
#define SFML_SPRITE_H

#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
#include <SFML/Graphics.h>

CSFML_GRAPHICS_API sfSprite* sfSprite_create(void);

CSFML_GRAPHICS_API sfSprite* sfSprite_copy(const sfSprite* sprite);

CSFML_GRAPHICS_API void sfSprite_destroy(sfSprite* sprite);

CSFML_GRAPHICS_API void sfSprite_setPosition(sfSprite* sprite, sfVector2f position);

CSFML_GRAPHICS_API void sfSprite_setRotation(sfSprite* sprite, float angle);

CSFML_GRAPHICS_API void sfSprite_setScale(sfSprite* sprite, sfVector2f scale);

CSFML_GRAPHICS_API void sfSprite_setOrigin(sfSprite* sprite, sfVector2f origin);

CSFML_GRAPHICS_API sfVector2f sfSprite_getPosition(const sfSprite* sprite);

CSFML_GRAPHICS_API float sfSprite_getRotation(const sfSprite* sprite);

CSFML_GRAPHICS_API sfVector2f sfSprite_getScale(const sfSprite* sprite);

CSFML_GRAPHICS_API sfVector2f sfSprite_getOrigin(const sfSprite* sprite);

CSFML_GRAPHICS_API void sfSprite_move(sfSprite* sprite, sfVector2f offset);

CSFML_GRAPHICS_API void sfSprite_rotate(sfSprite* sprite, float angle);

CSFML_GRAPHICS_API void sfSprite_scale(sfSprite* sprite, sfVector2f factors);

CSFML_GRAPHICS_API sfTransform sfSprite_getTransform(const sfSprite* sprite);

CSFML_GRAPHICS_API sfTransform sfSprite_getInverseTransform(const sfSprite* sprite);

CSFML_GRAPHICS_API void sfSprite_setTexture(sfSprite* sprite, const sfTexture* texture, sfBool resetRect);

CSFML_GRAPHICS_API void sfSprite_setTextureRect(sfSprite* sprite, sfIntRect rectangle);

CSFML_GRAPHICS_API void sfSprite_setColor(sfSprite* sprite, sfColor color);

CSFML_GRAPHICS_API const sfTexture* sfSprite_getTexture(const sfSprite* sprite);

CSFML_GRAPHICS_API sfIntRect sfSprite_getTextureRect(const sfSprite* sprite);

CSFML_GRAPHICS_API sfColor sfSprite_getColor(const sfSprite* sprite);

CSFML_GRAPHICS_API sfFloatRect sfSprite_getLocalBounds(const sfSprite* sprite);

CSFML_GRAPHICS_API sfFloatRect sfSprite_getGlobalBounds(const sfSprite* sprite);


#endif
