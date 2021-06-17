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
  sf::RenderWindow window(sf::VideoMode(200, 200), "Events explained");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Cyan);

  int counter = 0;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}