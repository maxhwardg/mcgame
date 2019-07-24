//
// Created by maxward on 6/26/19.
//

#ifndef MCGAME_TILESETMANAGER_H
#define MCGAME_TILESETMANAGER_H

#include <exception>
#include <string>
#include <vector>
#include <map>
#include <optional>
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
        std::vector<std::vector<int>> dense_tile_ids;
        /// sparse_layers[layer][row][col]
        std::map<int, std::map<int, std::map<int, int>>> sparse_layers;
    public:
        TileSetManager(const std::vector<std::string> &texture_paths, int rows_, int cols_,
                       int tile_size_ = -1, int default_texture_id = 0);

        int Rows() const;

        int Cols() const;

        int TileSize() const;

        /// Sets the value of a particular sparse tile. Sparse tiles are rendered after the dense layer.
        /// The row and column must be within limits. The layer id can be any valid int.
        /// Higher layers are rendered later.
        void SetSparseTileId(int layer, int row, int col, int texture_idx);

        /// Sets the value of a particular dense tile. Dense tiles are rendered first and have a default value.
        void SetDenseTileId(int row, int col, int texture_idx);

        /// The tile texture id of a tile in the dense layer.
        int DenseTileId(int row, int col) const;

        /// The tile texture id of a tile in the sparse layer.
        std::optional<int> SparseTileId(int layer, int row, int col);

        int NumTextures() const;

        void DrawToWindow(sf::RenderWindow &window) const;
    };
}

#endif //MCGAME_TILESETMANAGER_H
