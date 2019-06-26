//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "tile_set_manager.h"
#include "animated_entity.h"

#include <vector>
#include <cassert>
#include <exception>
#include <cmath>
#include <random>

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 800), "SFML window");
    window.setFramerateLimit(30);

    std::vector<std::string> tile_set_files = {
//           "resources/pixel_grass_tile10.png",
//           "resources/pixel_grass_tile10.png",
            "resources/pixel_grass_tile9.png",
            "resources/pixel_grass_tile8.png",
            "resources/pixel_grass_tile7.png",
            "resources/pixel_grass_tile6.png",
            "resources/pixel_grass_tile5.png",
            "resources/pixel_grass_tile4.png",
            "resources/pixel_grass_tile3.png",
            "resources/pixel_grass_tile3.png",
            "resources/pixel_grass_tile3.png",
            "resources/pixel_grass_tile2.png",
            "resources/pixel_grass_tile.png",
            "resources/pixel_grass_tile.png"
    };
    mcgame::TileSetManager tile_set_manager(tile_set_files, 100, 100, 64);
    std::default_random_engine random_engine;
    for (int i = 0; i < tile_set_manager.Rows(); ++i) {
        for (int j = 0; j < tile_set_manager.Cols(); ++j) {
            tile_set_manager.SetTileId(i, j, random_engine() % tile_set_manager.NumTextures());
        }
    }
    float ox = 0, oy = 0;
    int ex = 0, ey = 0;

    sf::Text text;
    sf::Font font;
    font.loadFromFile("resources/arial.ttf");

    text.setFont(font);

    sf::Texture anim1, anim2;
    anim1.loadFromFile("resources/floating_sprite.png");
    anim2.loadFromFile("resources/floating_sprite_rise.png");
    mcgame::AnimatedEntity entity({anim1, anim2});
    int frame = 0;

    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            ey -= tile_set_manager.TileSize();
            ++frame;
            entity.SetFrame(frame % entity.NumFrames());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            ey += tile_set_manager.TileSize();
            ++frame;
            entity.SetFrame(frame % entity.NumFrames());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            ex -= tile_set_manager.TileSize();
            ++frame;
            entity.SetFrame(frame % entity.NumFrames());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            ex += tile_set_manager.TileSize();
            ++frame;
            entity.SetFrame(frame % entity.NumFrames());
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

        entity.DrawToWindow(window);
        entity.SetPosition(ex, ey);
        window.display();
    }
    return EXIT_SUCCESS;
}
