#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing mushroom");

    sf::Texture mushroomTexture;
    if (!mushroomTexture.loadFromFile("./Mushroom.png")) {
        std::cout << "Error loading the file" << std::endl;
    }
    sf::Sprite mushroom(mushroomTexture);
    mushroom.setPosition(100.0f, 100.0f);
    
    sf::Vector2u size = mushroomTexture.getSize();
    mushroom.setOrigin(size.x / 2, size.y / 2);
    sf::Vector2f increment(0.1f, 0.1f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // Collisions
        if (
            (
                mushroom.getPosition().x + (size.x / 2) > window.getSize().x &&
                increment.x > 0
            ) ||
            (
                mushroom.getPosition().x - (size.x / 2) < 0 &&
                increment.x < 0
            )
        ) {
            // Reverse the direction on the X axis.
            increment.x = -increment.x;
        }
        if (
            (
                mushroom.getPosition().y + (size.y / 2) > window.getSize().y &&
                increment.y > 0
            ) ||
            (
                mushroom.getPosition().y - (size.y / 2) < 0 &&
                increment.y < 0
            )
        ) {
            // Reverse the direction on the Y axis.
            increment.y = -increment.y;
        }

        mushroom.setPosition(mushroom.getPosition() + increment);

        window.clear(sf::Color(16,16,16,255));
        window.draw(mushroom);
        window.display();
    }

    return 0;
}