#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Not sure how to use CAGE/lib.hpp in cmake yet
#include <CAGE/lib.hpp>
#include "Shooter/app.hpp"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::RectangleShape sprite(sf::Vector2f(120.0f, 120.0f));

    cage::hello();
    // This should be defined in app.hpp, but for some reason it's not including it?
    std::cout << "Version: " << APP_VERSION << std::endl;

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
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(sprite);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}