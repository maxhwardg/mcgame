//
// Created by maxward on 7/21/19.
//

#ifndef MCGAME_IMAGE_LIBRARY_H
#define MCGAME_IMAGE_LIBRARY_H

#include <string>
#include <SFML/Graphics.hpp>
#include <array>
#include <memory>

namespace mcgame {

    /// All the images known to the game. Must have densely packed ids starting at 0.
    enum class ImageName {
        GRASS_TILE = 0,
        FLOATING_SPRITE = 1,
        NEXT_IMAGE_ID = 2
    };

    /// Must be equal to the number of ImageName entries.
    const int NUM_IMAGES = static_cast<int>(ImageName::NEXT_IMAGE_ID);

    /// Manages the loading and retrieval of images. Ensures no image is loaded twice.
    class ImageLibrary {
    private:
        const std::string image_folder_path = "resources/images/";

        /// Indexes correspond to ImageName enum values.
        std::array<std::string, NUM_IMAGES> image_filenames;

        static std::unique_ptr<ImageLibrary> singleton;

        std::array<sf::Texture, NUM_IMAGES> textures;

        std::array<bool, NUM_IMAGES> is_loaded{};

        /// The mappings to image filenames happens in this constructor.
        ImageLibrary();

    public:

        ImageLibrary(ImageLibrary const &) = delete;

        void operator=(ImageLibrary const &) = delete;

        /// Gets the singleton ImageLibrary object.
        static ImageLibrary& Get();

        /// Forces an image to be loaded into the GPU from disk.
        void ForceLoad(ImageName image);

        /// Equivalent to ForceLoad called on all possible images.
        void ForceLoadAll();

        /// Makes a sprite corresponding to a particular image.
        sf::Sprite NewSprite(ImageName image);

        const sf::Texture &GetTexture(ImageName image);

        /// Unloads a particular image if it is loaded. This means it won't be stored on the graphics card anymore.
        void ClearImage(ImageName image);

        /// Unloads all the images. Equivalent to using ClearImage on all the images.
        void ClearAll();
    };
}

#endif //MCGAME_IMAGE_LIBRARY_H
