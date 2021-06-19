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
  sf::Texture textureTest;
  sf::Sprite sprite;
  sf::Sprite spriteTest;
  spriteTest.setPosition(0, 0);

  if (!texture.loadFromFile("src/wall-rock.jpg")) {
    std::cout << "not possible to open texture" << std::endl;
  }

  // load 32x32 rectangle starting from (10, 10)
  // if (!texture.loadFromFile("src/wall-rock.jpg", sf::IntRect(10, 10, 32, 32))) {
  //   std::cout << "not possible to open texture" << std::endl;
  // }

  textureTest.create(500, 500);

  // texture.setSmooth(true);
  sprite.setTexture(texture);
  sprite.setTextureRect(sf::IntRect(0, 0, 65, 64));
  // sprite.setColor(sf::Color(255, 255, 255, 128));
  sprite.setColor(sf::Color::Green);
  sprite.setPosition(sf::Vector2f(300, 300));

  sf::Sprite badSprite = loadSprite("src/wall-rock.jpg");

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color(200, 200, 200, 255));
    window.draw(circle);
    window.draw(sprite);
    textureTest.update(window);
    spriteTest.setTexture(textureTest);
    spriteTest.setColor(sf::Color(255, 200, 255, 128));
    spriteTest.setScale(.5, .5);
    window.draw(spriteTest);
    // window.draw(badSprite); // bad. textura inválida!!! observe como essa sprite é criada
    window.display();
  }

  return 0;
}


sf::Sprite loadSprite(std::string filename) {
  sf::Texture texture;
  texture.loadFromFile(filename);
  return sf::Sprite(texture);
} // texture não sobrevive fora desse escopo!!!
