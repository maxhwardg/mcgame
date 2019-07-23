//
// Created by maxward on 7/23/19.
//

#include "screen.h"

namespace mcgame {

    Screen::Screen() : render_window(sf::VideoMode(1600, 900), "SFML window") {}

    void Screen::Draw(const ScreenSprite &screen_sprite) {
        sprite.setTexture(library.GetTexture(screen_sprite.image));
        sprite.setPosition(screen_sprite.x - top_left_x, screen_sprite.y - top_left_y);
        render_window.draw(sprite);
    }

}