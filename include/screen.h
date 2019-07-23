//
// Created by maxward on 7/23/19.
//

#ifndef MCGAME_SCREEN_H
#define MCGAME_SCREEN_H

#include <cstdint>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "resources.h"
#include "image_library.h"

namespace mcgame {

    /// A Sprite that can be drawn to a Screen.
    struct ScreenSprite {
        ImageName image;
        int64_t x, y;
    };

    /// An abtract representation of the screen. Manages all rendering.
    class Screen {
    private:
        /// Screen keeps its own top left coorindate since GPU coordinates are floats, which may not be sufficient for
        /// intermediate representations.
        int64_t top_left_x, top_left_y;
        sf::RenderWindow render_window;
        sf::Sprite sprite;
        ImageLibrary library;
    public:
        Screen();
        void Draw(const ScreenSprite &screen_sprite);
    };
}

#endif //MCGAME_SCREEN_H
