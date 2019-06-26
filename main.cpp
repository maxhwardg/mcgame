//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>
#include <cassert>
#include <exception>
#include <cmath>

class FailedToLoadTextureException : std::exception {
    std::string image_path;
public:
    FailedToLoadTextureException(std::string image_path_) : image_path(std::move(image_path_)) {}
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
                   int default_texture_id = 0)
            : rows(rows_), cols(cols_) {
        assert(!texture_paths.empty());

        textures.resize(texture_paths.size());
        for (size_t ti = 0; ti < textures.size(); ++ti) {
            if (!textures[ti].loadFromFile(texture_paths[ti])) {
                throw FailedToLoadTextureException(texture_paths[ti]);
            }
            if (ti == 0) {
                tile_size = textures[0].getSize().x;
            }
            assert(static_cast<int>(textures[ti].getSize().x) == tile_size);
            assert(static_cast<int>(textures[ti].getSize().y) == tile_size);
        }
        tile_ids.resize(rows, std::vector<int>(cols, default_texture_id));
    }

    int Rows() const {
        return rows;
    }

    int Cols() const {
        return cols;
    }

    int TileSize() const {
        return tile_size;
    }

    void SetTileId(int row, int col, int texture_idx) {
        assert(row >= 0 && row < rows);
        assert(col >= 0 && col < cols);
        assert(texture_idx >= 0 && texture_idx < static_cast<int>(textures.size()));

        tile_ids[row][col] = texture_idx;
    }

    int TileId(int row, int col) const {
        assert(row >= 0 && row < rows);
        assert(col >= 0 && col < cols);

        return tile_ids[row][col];
    }

    void DrawToWindow(sf::RenderWindow &window) const {
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
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(30);

    TileSetManager tile_set_manager({"resources/grass_tile.png"}, 20, 20);
    float ox = 0, oy = 0;

    sf::Text text;
    sf::Font font;
    font.loadFromFile("resources/arial.ttf");

    text.setFont(font);

    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            oy -= 1.0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            oy += 1.0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            ox -= 1.0;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            ox += 1.0;
        }
        window.clear();
        sf::View view = window.getDefaultView();
        view.move(ox, oy);
        window.setView(view);
        tile_set_manager.DrawToWindow(window);

        auto view2 = window.getView();

        text.setString(std::to_string(view2.getCenter().x - view2.getSize().x / 2) + " " +
                       std::to_string(view2.getCenter().y - view2.getSize().y / 2));

        window.setView(window.getDefaultView());
        text.setPosition(10, 10);
        window.draw(text);
        window.display();
    }
    return EXIT_SUCCESS;
}
