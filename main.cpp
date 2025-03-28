#include <SFML/Graphics.hpp>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circle Color Change");
    
    sf::CircleShape circle(100); 
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(350, 250); 

    bool isSpacePressed = false;

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) 
            {
                if (event.key.code == sf::Keyboard::Space) 
                {
                    isSpacePressed = true;
                }
            }
            if (event.type == sf::Event::KeyReleased) 
            {
                if (event.key.code == sf::Keyboard::Space) 
                {
                    isSpacePressed = false;
                }
            }
        }
        if (isSpacePressed) 
        {
            circle.setFillColor(sf::Color::Red);
        } else {
            circle.setFillColor(sf::Color::Green);
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}