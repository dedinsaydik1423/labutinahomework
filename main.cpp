#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800,800), "Rotation", sf::Style::Default);
    window.setFramerateLimit(60);
    sf::CircleShape square(80, 4);
    square.setFillColor(sf::Color::Green);
    square.setPosition({300, 200});
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        square.rotate(0.1f);

        window.clear(sf::Color::Black);
        window.draw(square);

        window.display();
    }

    
}