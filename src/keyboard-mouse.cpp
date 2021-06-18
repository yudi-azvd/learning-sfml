#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>


void updateBullets(std::vector<sf::CircleShape>& bullets);

void drawBullets(std::vector<sf::CircleShape>& bullets);

float windowWidth = 600;
float windowHeight = 600;

sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Keyboard and mouse");

int main()
{
  sf::CircleShape circle(30.f);
  circle.setFillColor(sf::Color::Cyan);
  circle.setPosition(windowWidth/2, windowHeight/2);

  std::vector<sf::CircleShape> bullets;

  int counter = 0;

  while (window.isOpen())
  { 
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      
      /**
       * Se eu mantiver as teclas de movimento pressionadas,
       * é possível atirar repetidamente segurando o mouse.
       */
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        circle.setPosition(
          circle.getPosition().x+1,
          circle.getPosition().y);
      }

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        circle.setPosition(
          circle.getPosition().x-1,
          circle.getPosition().y);

        std::cout << "circle x " << circle.getPosition().x << std::endl;
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::cout << "left mouse button pressed!" << std::endl;
        sf::CircleShape bullet(4);
        bullet.setPosition(circle.getPosition());
        bullet.setFillColor(sf::Color::Red);
        bullets.push_back(bullet);
      }

      if (sf::Mouse::isButtonPressed(sf::Mouse::Middle)) {
        std::cout << "middle mouse button pressed!" << std::endl;
      }

      if (event.type == sf::Event::MouseMoved) {
        std::printf("global mouse pos (%d, %d)\n", sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
        std::printf("local  mouse pos (%d, %d)\n", sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
      }
    }


    // std::cout << "number of existing bullets " << bullets.size() << std::endl;
    window.clear();
    updateBullets(bullets);
    drawBullets(bullets);
    window.draw(circle);
    window.display();
  }

  return 0;
}


void updateBullets(std::vector<sf::CircleShape>& bullets) {
  int bulletCounter = 0;

  for (auto &bullet : bullets) {
    auto bulletPosition = bullet.getPosition();

    // considerando que as balas se movem apenas para a direita 
    if (bulletPosition.x > windowWidth) {
      bullets.erase(bullets.begin() + bulletCounter);
      continue;
    }

    bullet.setPosition(
      bulletPosition.x+0.5,
      bulletPosition.y
    );

    ++bulletCounter;
  }
}


void drawBullets(std::vector<sf::CircleShape>& bullets) {
  for (auto &bullet : bullets) {
    window.draw(bullet);
  }
}
