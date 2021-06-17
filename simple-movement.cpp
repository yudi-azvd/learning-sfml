#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "Events explained");

  float x = 0, y = 0;

  sf::CircleShape circle(4.f);
  circle.setFillColor(sf::Color::Red);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      
      if (event.type == sf::Event::TextEntered) {
        
        std::cout << event.text.unicode << std::endl;
        if (event.text.unicode >= 128)
          continue;
        
        char c = static_cast<char>(event.text.unicode);
        std::cout << "going to change coords" << std::endl;
        if (c == 'a') {
          x -= 0.25;
        }
        if (c == 'w') {
          y -= 0.25;
        }
        if (c == 's') {
          y += 0.25;
        }
        if (c == 'd') {
          x += 0.25;
        }

        std::cout << "(" << x << ", "<< y << ")" << std::endl;
      }
    }


    window.clear();
    circle.setPosition(x, y);
    window.draw(circle);
    window.display();
  }

  return 0;
}