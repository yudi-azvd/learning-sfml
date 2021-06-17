#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Magenta);

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          window.close();
          break;
        case sf::Event::KeyPressed:
          std::cout << "key pressed: " << event.key.code << std::endl;
          if (event.key.code == sf::Keyboard::Escape) {
            std::cout << "escape key was pressed" << std::endl;
            std::cout << "control:" << event.key.control << std::endl;
            std::cout << "    alt:" << event.key.alt << std::endl;
            std::cout << "  shift:" << event.key.shift << std::endl;
            std::cout << " system:" << event.key.system << std::endl;
          }
          break;
        case sf::Event::Resized:
          std::cout << "new window dimensions: " << event.size.width << "x" << event.size.height << std::endl;
          break;
        case sf::Event::LostFocus:
          std::cout << "lost focus" << std::endl;
          break;
        case sf::Event::GainedFocus:
          std::cout << "gained focus" << std::endl;
        case sf::Event::TextEntered:
          if (event.text.unicode < 128)
            std::cout << "ASCII char typed: " << static_cast<char>(event.text.unicode) << std::endl;
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