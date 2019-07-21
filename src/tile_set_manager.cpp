//
// Created by maxward on 6/26/19.
//

#include "tile_set_manager.h"

#include <cassert>
#include <cmath>

namespace mcgame {
    TileSetManager::TileSetManager(const std::vector<std::string> &texture_paths, int rows_, int cols_,
                                   int tile_size_, int default_texture_id)
            : rows(rows_), cols(cols_), tile_size(tile_size_) {
        assert(!texture_paths.empty());

        textures.resize(texture_paths.size());
        for (size_t ti = 0; ti < textures.size(); ++ti) {
            if (!textures[ti].loadFromFile(texture_paths[ti])) {
                throw FailedToLoadTextureException(texture_paths[ti]);
            }
            if (tile_size == -1) {
                tile_size = textures[0].getSize().x;
            }
            assert(static_cast<int>(textures[ti].getSize().x) == tile_size);
            assert(static_cast<int>(textures[ti].getSize().y) == tile_size);
        }
        tile_ids.resize(rows, std::vector<int>(cols, default_texture_id));
    }

    int TileSetManager::Rows() const {
        return rows;
    }

    int TileSetManager::Cols() const {
        return cols;
    }

    int TileSetManager::TileSize() const {
        return tile_size;
    }

    void TileSetManager::SetTileId(int row, int col, int texture_idx) {
        assert(row >= 0 && row < rows);
        assert(col >= 0 && col < cols);
        assert(texture_idx >= 0 && texture_idx < static_cast<int>(textures.size()));

        tile_ids[row][col] = texture_idx;
    }

    int TileSetManager::TileId(int row, int col) const {
        assert(row >= 0 && row < rows);
        assert(col >= 0 && col < cols);

        return tile_ids[row][col];
    }

    int TileSetManager::NumTextures() const {
        return textures.size();
    }

    void TileSetManager::DrawToWindow(sf::RenderWindow &window) const {
        sf::Sprite sprite;

        auto view = window.getView();
        int window_x = static_cast<int>(std::floor(view.getCenter().x - view.getSize().x / 2));
        int window_y = static_cast<int>(std::floor(view.getCenter().y - view.getSize().y / 2));
        int size_pixels_x = static_cast<int>(std::ceil(view.getSize().x));
        int size_pixels_y = static_cast<int>(std::ceil(view.getSize().y));
        for (int row = std::max(0, window_x / tile_size);
             row < rows && row <= (window_x + size_pixels_x) / tile_size; ++row) {
            for (int col = std::max(0, window_y / tile_size);
                 col < cols && col <= (window_y + size_pixels_y) / tile_size; ++col) {
                sprite.setTexture(textures[tile_ids[row][col]]);
                sprite.setPosition(row * tile_size, col * tile_size);
                window.draw(sprite);
            }
        }
    }
}
