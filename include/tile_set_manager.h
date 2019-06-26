//
// Created by maxward on 6/26/19.
//

#ifndef MCGAME_TILESETMANAGER_H
#define MCGAME_TILESETMANAGER_H

#include <exception>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace mcgame {

    class FailedToLoadTextureException : std::exception {
        std::string image_path;
    public:
        explicit FailedToLoadTextureException(std::string image_path_) : image_path(std::move(image_path_)) {}
    };

    class TileSetManager {
    private:
        int rows;
        int cols;
        int tile_size;
        std::vector<sf::Texture> textures;
        std::vector<std::vector<int>> tile_ids;
        const static int rendering_padding = 5;
    public:
        TileSetManager(const std::vector<std::string> &texture_paths, int rows_, int cols_,
                       int tile_size_ = -1, int default_texture_id = 0);

        int Rows() const;

        int Cols() const;

        int TileSize() const;

        void SetTileId(int row, int col, int texture_idx);

        int TileId(int row, int col) const;

        int NumTextures() const;

        void DrawToWindow(sf::RenderWindow &window) const;
    };
}

#endif //MCGAME_TILESETMANAGER_H
