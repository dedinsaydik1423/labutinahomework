#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <random>
#include <vector>
sf::Color getRandomColor() 
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<uint8_t> d(0, 255);
    return sf::Color{d(gen), d(gen), d(gen)};
}

int main() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circle Drawer");
    
    std::vector<sf::CircleShape> circles;

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) 
            {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    sf::CircleShape circle(30); 
                    circle.setFillColor(sf::Color::White);
                    circle.setPosition(static_cast<float>(event.mouseButton.x - circle.getRadius()), 
                                       static_cast<float>(event.mouseButton.y - circle.getRadius()));
                    circles.push_back(circle); 
                    
                }
            }

            
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    
                    for (auto& circle : circles) {
                        circle.setFillColor(getRandomColor());
                    }
                }
            }
        }
        window.clear(sf::Color::Black);
        for (const auto& circle : circles) {
            window.draw(circle);
        }
        window.display();
    }
    return 0;
}