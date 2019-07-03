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
            "resources/pixel_grass_tile10.png",
            "resources/pixel_grass_tile10.png",
            "resources/pixel_grass_tile10.png",
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

    sf::Text text;
    sf::Font font;
    font.loadFromFile("resources/arial.ttf");

    text.setFont(font);

    sf::Texture anim1, anim2, anim3, anim4;
    anim1.loadFromFile("resources/floating_sprite.png");
    anim2.loadFromFile("resources/floating_sprite_rise.png");
    anim3.loadFromFile("resources/floating_sprite_right.png");
    anim4.loadFromFile("resources/floating_sprite_rise_right.png");
    mcgame::AnimatedEntity entity({anim1, anim2, anim3, anim4});
    int frame = 0;
    int entity_frame = 0;
    int num_anim_frames = entity.NumFrames()/2;
    int ex = window.getSize().x/2 - entity.GetSize().x/2, ey = window.getSize().y/2 - entity.GetSize().y/2;

    sf::Keyboard::Key last_left_right_key = sf::Keyboard::Left;
    sf::Keyboard::Key current_left_right_key = sf::Keyboard::Left;

    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

        }
        bool button_pressed = false;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            button_pressed = true;
            oy -= 1;
            ++frame;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            button_pressed = true;
            oy += 1;
            ++frame;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            button_pressed = true;
            ox -= 1;
            ++frame;
            current_left_right_key = sf::Keyboard::Left;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            button_pressed = true;
            ox += 1;
            ++frame;
            current_left_right_key = sf::Keyboard::Right;
        }

        if (button_pressed && ((frame % 10) == 0 || last_left_right_key != current_left_right_key)) {
            int left_right_offset = 0;
            if (current_left_right_key == sf::Keyboard::Right) {
                left_right_offset = num_anim_frames;
            }
            entity.SetFrame(left_right_offset + (entity_frame % num_anim_frames));
            ++entity_frame;
        }
        last_left_right_key = current_left_right_key;

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
