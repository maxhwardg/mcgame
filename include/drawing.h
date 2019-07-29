//
// Created by maxward on 7/23/19.
//

#ifndef MCGAME_DRAWING_H
#define MCGAME_DRAWING_H

#include <cstdint>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "image_library.h"

namespace mcgame {

    /// Data type to represent pixel coordinates.
    typedef int pixel_coord_t;

    /// Transformations to apply to an image before rendering.
    struct DrawParams {
        pixel_coord_t x, y;
    };

    /// An area in the world to be rendered. This is the primary abstraction for rendering a game world.
    class RenderArea {
    private:
        /// Screen keeps its own
        /// coordinates since GPU float coordinates are floats, which may not be sufficient for
        /// intermediate representations.
        pixel_coord_t top_left_x, top_left_y, width, height;
        std::shared_ptr<sf::RenderWindow> render_window;
        sf::Sprite sprite;
    public:
        /// By default, the top left coords, width, and height are taken from the area in the RenderWindow.
        RenderArea(std::shared_ptr<sf::RenderWindow> render_window_);
        void Draw(ImageName image, const DrawParams &transformations);
        pixel_coord_t TopLeftX() const;
        pixel_coord_t TopLeftY() const;
        pixel_coord_t Width() const;
        pixel_coord_t Height() const;
    };
}

#endif //MCGAME_DRAWING_H
