//
// Created by maxward on 6/26/19.
//

#include "tiles.h"

#include <cassert>
#include <cmath>

#include <iostream>

namespace mcgame {
    TileGridDrawer::TileGridDrawer(int rows_, int cols_, ImageName default_tile)
            : rows(rows_), cols(cols_) {
        // Save the tile_size and check that all the time images have the same size.
        auto default_tile_size = ImageLibrary::Get().GetTexture(default_tile).getSize();
        tile_size = default_tile_size.x;
        assert(tile_size == static_cast<int>(default_tile_size.y));

        // Fill tile_ids with default tile image
        tile_images.assign(rows, std::vector<ImageName>(cols, default_tile));
    }

    int TileGridDrawer::Rows() const {
        return rows;
    }

    int TileGridDrawer::Cols() const {
        return cols;
    }

    int TileGridDrawer::TileSize() const {
        return tile_size;
    }

    void TileGridDrawer::SetTileImage(int row, int col, ImageName image) {
        assert(row >= 0 && row < rows);
        assert(col >= 0 && col < cols);
        assert(static_cast<int>(ImageLibrary::Get().GetTexture(image).getSize().x) == tile_size);
        assert(static_cast<int>(ImageLibrary::Get().GetTexture(image).getSize().y) == tile_size);

        tile_images[row][col] = image;
    }


    ImageName TileGridDrawer::TileImage(int row, int col) const {
        assert(row >= 0 && row < rows);
        assert(col >= 0 && col < cols);

        return tile_images[row][col];
    }

    void TileGridDrawer::Draw(RenderArea &render_area) const {
        for (int row = std::max(0, render_area.TopLeftY() / tile_size);
             row < rows && row <= (render_area.TopLeftY() + render_area.Height()) / tile_size; ++row) {
            for (int col = std::max(0, render_area.TopLeftX() / tile_size);
                 col < cols && col <= (render_area.TopLeftX() + render_area.Width()) / tile_size; ++col) {
                render_area.Draw(tile_images[row][col], {col * tile_size, row * tile_size});
            }
        }
    }

    TileManager::TileManager(int layers, int rows, int cols, const mcgame::Tile &init_tile) : rows(rows), cols(cols) {
        layer_tiles.assign(layers, std::vector<std::vector<Tile>>(rows, std::vector<Tile>(cols, init_tile)));
        tile_walkable.assign(rows, std::vector<int>(rows, 0));
        layer_drawers.assign(layers, TileGridDrawer(rows, cols, init_tile.image));
    }

    Tile TileManager::getTile(int layer, int row, int col) const {
        assert(row >= 0 && row < rows);
        assert(col >= 0 && col < cols);
        assert(row >= 0 && row < rows);
        assert(layer >= 0 && layer < layers);
        return layer_tiles[layer][row][col];
    }

    void TileManager::setTile(int layer, int row, int col, const Tile& tile) {
        assert(row >= 0 && row < rows);
        assert(col >= 0 && col < cols);
        assert(row >= 0 && row < rows);
        assert(layer >= 0 && layer < layers);
        layer_tiles[layer][row][col] = tile;
        layer_drawers[layer].SetTileImage(row, col, tile.image);

        if (tile_walkable[row][col] != tile.walkable) {
            bool is_walkable = false;
            for (int l = 0; l < layers; ++l) {
                if (layer_tiles[l][row][col].walkable) {
                    is_walkable = true;
                    break;
                }
            }
            tile_walkable[row][col] = is_walkable;
        }
    }

    bool TileManager::isWalkable(int row, int col) const {
        assert(row >= 0 && row < rows);
        assert(col >= 0 && col < cols);
        return tile_walkable[row][col];
    }

    void TileManager::Draw(mcgame::RenderArea &render_area) const {
        for (int l = 0; l < layers; ++l) {
            layer_drawers[l].Draw(render_area);
        }
    }
}

