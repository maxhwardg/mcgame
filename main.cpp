//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("../resources/spacemax.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setScale(0.2, 0.2);
    // Create a graphical text to display
//    sf::Font font;
//    if (!font.loadFromFile("arial.ttf"))
//        return EXIT_FAILURE;
//    sf::Text text("Hello SFML", font, 50);
    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile("Chiptronical.ogg"))
//        return EXIT_FAILURE;
    // Play the music
//    music.play();
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
            }
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Draw the string
//        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
