//
// Created by maxward on 7/21/19.
//

#include "image_library.h"
#include <cassert>

namespace mcgame {
    void ImageLibrary::ForceLoad(ImageName image) {
        int idx = static_cast<int>(image);

        sf::Image image_file;
        image_file.loadFromFile(IMAGE_FOLDER_PATH + IMAGE_FILENAMES[idx]);

        unsigned max_size = sf::Texture::getMaximumSize();
        assert(max_size >= image_file.getSize().x && max_size >= image_file.getSize().x);

        textures[idx].loadFromImage(image_file);
    }

    void ImageLibrary::ForceLoadAll() {
        for (int i = 0; i < NUM_IMAGES; ++i) {
            ForceLoad(static_cast<ImageName>(i));
        }
    }

    sf::Sprite ImageLibrary::NewSprite(ImageName image) {
        int idx = static_cast<int>(image);
        if (!is_loaded[idx]) {
            ForceLoad(image);
        }
        sf::Sprite sprite;
        sprite.setTexture(textures[idx]);

        return sprite;
    }

    const sf::Texture& ImageLibrary::GetTexture(ImageName image) {
        int idx = static_cast<int>(image);
        if (!is_loaded[idx]) {
            ForceLoad(image);
        }
        return textures[idx];
    }

    void ImageLibrary::ClearImage(ImageName image) {
        int idx = static_cast<int>(image);
        textures[idx] = sf::Texture();
    }

    void ImageLibrary::ClearAll() {
        for (int i = 0; i < NUM_IMAGES; ++i) {
            ClearImage(static_cast<ImageName>(i));
        }
    }
}