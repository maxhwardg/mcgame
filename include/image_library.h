//
// Created by maxward on 7/21/19.
//

#ifndef MCGAME_IMAGE_LIBRARY_H
#define MCGAME_IMAGE_LIBRARY_H

#include <string>
#include <SFML/Graphics.hpp>
#include "resources.h"

namespace mcgame {

    /// Manages the loading and retrieval of images. Ensures no image is loaded twice.
    class ImageLibrary {
    private:
        std::array<sf::Texture, NUM_IMAGES> textures;
        std::array<bool, NUM_IMAGES> is_loaded;
    public:
        ImageLibrary() = default;

        /// Forces an image to be loaded into the GPU from disk.
        void ForceLoad(ImageName image);

        /// Equivalent to ForceLoad called on all possible images.
        void ForceLoadAll();

        /// Makes a sprite corresponding to a particular image.
        sf::Sprite NewSprite(ImageName image);

        const sf::Texture& GetTexture(ImageName image);

        /// Unloads a particular image if it is loaded. This means it won't be stored on the graphics card anymore.
        void ClearImage(ImageName image);

        /// Unloads all the images. Equivalent to using ClearImage on all the images.
        void ClearAll();
    };
}

#endif //MCGAME_IMAGE_LIBRARY_H
