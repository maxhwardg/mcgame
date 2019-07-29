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
}

