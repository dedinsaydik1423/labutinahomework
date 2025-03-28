#include <SFML/Graphics.hpp>

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hover Rectangle");
    sf::RectangleShape rectangle(sf::Vector2f(200, 100));
    rectangle.setPosition(300, 250); 
    rectangle.setFillColor(sf::Color::Green); 

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            
                
            if (event.type == sf::Event::MouseMoved) 
            {
                sf::Vector2f mousePos((float)event.mouseMove.x, (float)event.mouseMove.y);
                
                
                if (rectangle.getGlobalBounds().contains(mousePos)) 
                {
                    rectangle.setFillColor(sf::Color::Red); 
                    
                } else 
                {
                    rectangle.setFillColor(sf::Color::Green); 
                    
                }
            }
        }

        
        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}