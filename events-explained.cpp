#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <iostream>

/**
 * https://www.sfml-dev.org/tutorials/2.5/start-linux.php
 * 
 * sudo apt-get install libsfml-dev
 * 
 * g++ -c main.cpp
 * 
 * g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
 * 
 * ./sfml-app
 */
int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          std::cout << "key pressed: " << event.key.code << std::endl;
          break;
        default:
          break;
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}