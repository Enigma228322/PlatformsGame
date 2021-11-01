#include "SFML/Graphics.hpp"
#include <string>

#define STEP 10

int main(int argc, char** argv)
{
    auto window_type = sf::Style::Default;
    if(argc == 2)
    {
        std::string first_arg(argv[1]);
        if(first_arg == "--fs")
            window_type = sf::Style::Fullscreen;
    }
    
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Platforms", window_type);
    window.setFramerateLimit(75);
    sf::RectangleShape rectangle(sf::Vector2f(120, 30));
    rectangle.setFillColor(sf::Color::Green);

    double i = 0;
    bool left = false, right = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                rectangle.setPosition(i,1);
                i-=1;
                left = true;
                right = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                rectangle.setPosition(i,1);
                right = true;
                left = false;
            }
        }
        if(left)
        {
            i-=STEP;
            left = false;
        }
        if(right)
        {
            i+=STEP;
            right = false;
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}