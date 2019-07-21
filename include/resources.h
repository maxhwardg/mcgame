//
// Created by maxward on 7/21/19.
//

#ifndef MCGAME_RESOURCES_H
#define MCGAME_RESOURCES_H

#include <string>
#include <array>

namespace mcgame {
    const std::string IMAGE_FOLDER_PATH = "resources/images/";


    /// All the images known to the game. Must have densely packed ids starting at 0.
    enum ImageName {
        GRASS_TILE = 0,
        FLOATING_SPRITE = 1
    };

    const int NUM_IMAGES = 2;

    const std::array<std::string, NUM_IMAGES> IMAGE_FILENAMES = {"grass_tile.png", "floating_sprite.png"};
}

#endif //MCGAME_RESOURCES_H
