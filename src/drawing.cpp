//
// Created by maxward on 7/23/19.
//

#include "drawing.h"
#include <cmath>

namespace mcgame {

    RenderArea::RenderArea(std::shared_ptr<sf::RenderWindow> render_window_) : render_window(
            std::move(render_window_)) {
        auto view_rect = render_window->getView().getViewport();
        top_left_x = static_cast<pixel_coord_t>(std::round(view_rect.left));
        top_left_y = static_cast<pixel_coord_t>(std::round(view_rect.top));
        width = static_cast<pixel_coord_t>(std::round(view_rect.width));
        height = static_cast<pixel_coord_t>(std::round(view_rect.height));
    }

    void RenderArea::Draw(ImageName image, const DrawParams &transformations) {
        sprite.setTexture(ImageLibrary::Get().GetTexture(image));
        sprite.setPosition(transformations.x - top_left_x, transformations.y - top_left_y);
        render_window->draw(sprite);
    }

    pixel_coord_t RenderArea::TopLeftX() const {
        return top_left_x;
    }

    pixel_coord_t RenderArea::TopLeftY() const {
        return top_left_y;
    }

    pixel_coord_t RenderArea::Width() const {
        return width;
    }

    pixel_coord_t RenderArea::Height() const {
        return height;
    }

}