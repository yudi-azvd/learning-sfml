#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), 
    "Events explained", sf::Style::Close);

  float x = 0, y = 0;
  float step = .015;
  bool isMovingUp = false;
  bool isMovingDown = false;
  bool isMovingLeft = false;
  bool isMovingRight = false;

  sf::CircleShape circle(4.f);
  circle.setFillColor(sf::Color::Red);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      
      isMovingLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::A)
        ? true : false;
      isMovingUp = sf::Keyboard::isKeyPressed(sf::Keyboard::W)
        ? true : false;
      isMovingDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S)
        ? true : false;
      isMovingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D)
        ? true : false;

      std::cout << "(" << x << ", "<< y << ")" << std::endl;
    }

    if (isMovingLeft) {
      x -= step;
    }
    if (isMovingUp) {
      y -= step;
    }
    if (isMovingDown) {
      y += step;
    }
    if (isMovingRight) {
      x += step;
    }

    window.clear();
    circle.setPosition(x, y);
    window.draw(circle);
    window.display();
  }

  return 0;
}