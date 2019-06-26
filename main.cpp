//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "tile_set_manager.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    window.setFramerateLimit(30);

    mcgame::TileSetManager tile_set_manager({"resources/grass_tile.png"}, 20, 20);
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
