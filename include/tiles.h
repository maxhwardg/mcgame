//
// Created by maxward on 6/26/19.
//

#ifndef MCGAME_TILES_H
#define MCGAME_TILES_H

#include <exception>
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "drawing.h"

namespace mcgame {
    class TileGridDrawer {
    private:
        int rows;
        int cols;
        int tile_size;
        std::vector<std::vector<ImageName>> tile_images;
    public:
        /// Automatically deduces the tile_size from the default_tile image.
        TileGridDrawer(int rows_, int cols_, ImageName default_tile);

        int Rows() const;

        int Cols() const;

        int TileSize() const;

        /// Sets the value of a particular tile.
        void SetTileImage(int row, int col, ImageName image);

        /// The tile texture id of a tile in the dense layer.
        ImageName TileImage(int row, int col) const;

        void Draw(RenderArea &render_area) const;
    };

    struct Tile {
        ImageName image;
        bool walkable;
    };

    class TileManager {
    private:
        int layers;
        int rows;
        int cols;
        std::vector<std::vector<std::vector<Tile>>> layer_tiles;
        // Uses int instead of vector<bool> since vector<bool> is trash.
        std::vector<std::vector<int>> tile_walkable;
        std::vector<TileGridDrawer> layer_drawers;
    public:
        TileManager(int layers, int rows, int cols, const Tile& init_tile);
        bool isWalkable(int row, int col) const;
        void setTile(int layer, int row, int col, const Tile& tile);
        Tile getTile(int layer, int row, int col) const;
        void Draw(RenderArea &render_area) const;
    };
}

#endif //MCGAME_TILES_H
