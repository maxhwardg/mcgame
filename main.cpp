//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "tile_set_manager.h"

#include <vector>
#include <cassert>
#include <exception>
#include <cmath>
#include <random>

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 800), "SFML window");
    window.setFramerateLimit(30);

    mcgame::TileSetManager tile_set_manager(
            {
//                    "resources/pixel_grass_tile10.png",
//                    "resources/pixel_grass_tile10.png",
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
            }, 100, 100, 64);
    std::default_random_engine random_engine;
    for (int i = 0; i < tile_set_manager.Rows(); ++i) {
        for (int j = 0; j < tile_set_manager.Cols(); ++j) {
            tile_set_manager.SetTileId(i, j, random_engine()% tile_set_manager.NumTextures());
        }
    }
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
