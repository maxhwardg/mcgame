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

        /// Sets the value of a particular dense tile. Dense tiles are rendered first and have a default value.
        void SetTileImage(int row, int col, ImageName image);

        /// The tile texture id of a tile in the dense layer.
        ImageName TileImage(int row, int col) const;

        void Draw(RenderArea &render_area) const;
    };
}

#endif //MCGAME_TILES_H
