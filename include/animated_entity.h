//
// Created by maxward on 6/26/19.
//

#ifndef MCGAME_ANIMATED_ENTITY_H
#define MCGAME_ANIMATED_ENTITY_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <cassert>

namespace mcgame {
    class AnimatedEntity {
        std::vector<sf::Texture> textures;
        sf::Sprite sprite;
        int x;
        int y;
        int current_frame;
    public:
        explicit AnimatedEntity(std::vector<sf::Texture> frames) : textures(std::move(frames)), x(0), y(0),
                                                             current_frame(0) {
            assert(!textures.empty());
            sprite.setPosition(x, y);
            sprite.setTexture(textures[current_frame]);
        }

        void SetPosition(int x_, int y_) {
            x = x_;
            y = y_;
            sprite.setPosition(x, y);
        }

        void SetFrame(int frame_id) {
            assert(frame_id >= 0 && frame_id < static_cast<int>(textures.size()));
            current_frame = frame_id;
            sprite.setTexture(textures[current_frame]);
        }

        int NumFrames() const {
            return textures.size();
        }

        void DrawToWindow(sf::RenderWindow &window) const {
            window.draw(sprite);
        }

        sf::Vector2u GetSize() const {
            return sprite.getTexture()->getSize();
        }
    };
}

#endif //MCGAME_ANIMATED_ENTITY_H
