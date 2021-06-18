#include <SFML/Graphics.hpp>
#include <iostream>


sf::Sprite loadSprite(std::string filname);


int main()
{
  sf::RenderWindow window(sf::VideoMode(400, 400), "Sprites and Textures");
  sf::CircleShape circle(40.f);
  circle.setFillColor(sf::Color::Cyan);
  circle.setPosition(200, 200);

  sf::Texture texture;
  sf::Sprite sprite;

  if (!texture.loadFromFile("src/wall-rock.jpg")) {
    std::cout << "not possible to open texture" << std::endl;
  }

  // load 32x32 rectangle starting from (10, 10)
  // if (!texture.loadFromFile("src/wall-rock.jpg", sf::IntRect(10, 10, 32, 32))) {
  //   std::cout << "not possible to open texture" << std::endl;
  // }


  // texture.setSmooth(true);
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 65, 64));
  // sprite.setColor(sf::Color(255, 255, 255, 128));
  sprite.setColor(sf::Color::Green);
  sprite.setPosition(sf::Vector2f(50, 50));

  sf::Sprite testSprite = loadSprite("src/wall-rock.jpg");

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(sprite);
    window.draw(testSprite); // bad. textura inválida!!! observe como essa sprite é criada
    window.draw(circle);
    window.display();
  }

  return 0;
}


sf::Sprite loadSprite(std::string filename) {
  sf::Texture texture;
  texture.loadFromFile(filename);
  return sf::Sprite(texture);
} // texture não sobrevive fora desse escopo!!!
