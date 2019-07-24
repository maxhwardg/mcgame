//
// Created by maxward on 7/23/19.
//

#include "screen.h"

namespace mcgame {

    Screen::Screen() : top_left_x(0), top_left_y(0), render_window(sf::VideoMode(1600, 900), "SFML window") {}

    void Screen::Draw(ImageName image, const ImageTransformations &transformations) {
        sprite.setTexture(library.GetTexture(image));
        sprite.setPosition(transformations.x - top_left_x, transformations.y - top_left_y);
        render_window.draw(sprite);
    }

}