//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "drawing.h"
#include "image_library.h"
#include "tiles.h"

#include <vector>
#include <cassert>
#include <exception>
#include <cmath>
#include <random>
#include <iostream>

int main() {
//    sf::RenderWindow window(sf::VideoMode(1600, 800), "SFML window");
//    window.setFramerateLimit(30);
//    mcgame::RenderArea render_area(static_cast<std::shared_ptr<sf::RenderWindow>>(&window));

//    mcgame::ImageLibrary::Get();
//    mcgame::DrawParams drawParams = {100, 100};
//    render_area.Draw(mcgame::ImageName::FLOATING_SPRITE, drawParams);

//    std::vector<std::string> tile_set_files = {
//           "resources/images/pixel_grass_tile10.png",
//            "resources/images/pixel_grass_tile10.png",
//            "resources/images/pixel_grass_tile10.png",
//            "resources/images/pixel_grass_tile9.png",
//            "resources/images/pixel_grass_tile8.png",
//            "resources/images/pixel_grass_tile7.png",
//            "resources/images/pixel_grass_tile6.png",
//            "resources/images/pixel_grass_tile5.png",
//            "resources/images/pixel_grass_tile4.png",
//            "resources/images/pixel_grass_tile3.png",
//            "resources/images/pixel_grass_tile3.png",
//            "resources/images/pixel_grass_tile3.png",
//            "resources/images/pixel_grass_tile2.png",
//            "resources/images/pixel_grass_tile.png",
//            "resources/images/pixel_grass_tile.png"
//    };
//    std::default_random_engine random_engine;
//    float ox = 0, oy = 0;
//
//    std::vector<std::string> tree_tile_set_files = {
//            "resources/images/blank_tile.png",
//            "resources/images/tree.png",
//    };
//
//
//    sf::Texture tree_tex;
//    tree_tex.loadFromFile("resources/images/tree.png");
//    std::vector<sf::Sprite> trees;
//    for (int i = 0; i < 100; ++i) {
//        sf::Sprite sprite;
//        sprite.setTexture(tree_tex);
//        sprite.setPosition((random_engine()%100)*64, (random_engine()%100)*64);
//        trees.push_back(sprite);
//    }
//
//    std::vector<std::string> gem_tile_set_files = {
//            "resources/images/blank_tile.png",
//            "resources/images/gem_green_tile.png",
//            "resources/images/gem_red_tile.png",
//            "resources/images/gem_blue_tile.png",
//            "resources/images/gem_teal_tile.png"
//    };
//    int sparsity_factor = 50;
//
//    sf::Text text;
//    sf::Font font;
//    font.loadFromFile("resources/fonts/arial.ttf");
//
//    text.setFont(font);
//
//    sf::Texture anim1, anim2, anim3, anim4;
//    anim1.loadFromFile("resources/images/floating_sprite.png");
//    anim2.loadFromFile("resources/images/floating_sprite_rise.png");
//    anim3.loadFromFile("resources/images/floating_sprite_right.png");
//    anim4.loadFromFile("resources/images/floating_sprite_rise_right.png");
//    int frame = 0;
//    int entity_frame = 0;
//    int gem_count = 0;
//
//    sf::Keyboard::Key last_left_right_key = sf::Keyboard::Left;
//    sf::Keyboard::Key current_left_right_key = sf::Keyboard::Left;
//
//    while (window.isOpen()) {
//        // Process events
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            // Close window: exit
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//        }
//        bool button_pressed = false;
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//            button_pressed = true;
//            oy -= 2;
//            ++frame;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//            button_pressed = true;
//            oy += 2;
//            ++frame;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//            button_pressed = true;
//            ox -= 2;
//            ++frame;
//            current_left_right_key = sf::Keyboard::Left;
//        }
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//            button_pressed = true;
//            ox += 2;
//            ++frame;
//            current_left_right_key = sf::Keyboard::Right;
//        }
//
//        if (button_pressed && ((frame % 10) == 0 || last_left_right_key != current_left_right_key)) {
//            int left_right_offset = 0;
//            if (current_left_right_key == sf::Keyboard::Right) {
//                left_right_offset = num_anim_frames;
//            }
//            ++entity_frame;
//        }
//        last_left_right_key = current_left_right_key;
//
//        window.clear();
//        sf::View view = window.getDefaultView();
//        view.move(ox, oy);
//        window.setView(view);
//
//        // Check if need to collect gem.
//        if (ey/gem_tile_set_files)
//
//        // Render trees.
//        for (auto tree : trees) {
//            if (tree.getPosition().y <= oy+ey) {
//                window.draw(tree);
//            }
//        }
//        auto view2 = window.getView();
//
//        text.setString(std::to_string(view2.getCenter().x - view2.getSize().x / 2) + " " +
//                       std::to_string(view2.getCenter().y - view2.getSize().y / 2));
//
//        window.setView(window.getDefaultView());
//        text.setPosition(10, 10);
//        window.draw(text);
//
//        text.setString("Gem count: " + std::to_string(gem_count));
//        window.setView(window.getDefaultView());
//        text.setPosition(10, 60);
//        window.draw(text);
//
//        window.setView(view);
//        for (auto tree : trees) {
//            if (tree.getPosition().y > oy+ey) {
//                window.draw(tree);
//            }
//        }
//
//        window.display();
//    }
    return EXIT_SUCCESS;
}
