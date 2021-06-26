#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(400, 400), "Text & Font");
  window.setFramerateLimit(2);
  sf::Font font9x9;
  sf::Font font5x5;
  std::string filename = "assets/bit9x9.ttf";
  if (!font9x9.loadFromFile(filename)) {
    throw std::runtime_error("could not load font from " + filename);
  }

  filename = "assets/bit5x5.ttf";
  if (!font5x5.loadFromFile(filename)) {
    throw std::runtime_error("could not load font from " + filename);
  }

  sf::Text text9x9("TEXT 3 x 2", font9x9);
  text9x9.setCharacterSize(32);
  text9x9.setOutlineColor(sf::Color::Blue);
  text9x9.setOrigin(
    text9x9.getLocalBounds().width/2,
    text9x9.getLocalBounds().height/2
  );
  text9x9.setPosition(200, 200);

  sf::Text text5x5("TEXT 3 x 2", font5x5);
  text5x5.setCharacterSize(32);
  text5x5.setOutlineColor(sf::Color::Blue);
  text5x5.setOrigin(
    text5x5.getLocalBounds().width/2,
    text5x5.getLocalBounds().height/2
  );
  text5x5.setPosition(200, 300);
  // text5x5.setScale(1, 1.5);

  const float scaleTerm = 0.001f;
  float verticalScaleAmountForText = scaleTerm;
  sf::RectangleShape rect({text9x9.getLocalBounds().width, text9x9.getLocalBounds().height});
  rect.setOrigin(
    text9x9.getLocalBounds().width/2,
    text9x9.getLocalBounds().height/2
  );

  text9x9.setScale(1, 2);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    auto textTopOffset = text9x9.getLocalBounds().top;
    verticalScaleAmountForText += scaleTerm;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "       vertical scale " << text9x9.getScale().y+ verticalScaleAmountForText << std::endl;
    std::cout << "             text top " << textTopOffset << std::endl;
    std::cout << " text loc bouns width " << text9x9.getLocalBounds().width << std::endl;
    std::cout << "text loc bouns height " << text9x9.getLocalBounds().height << std::endl;
    // text.setScale(1, text.getScale().y + verticalScaleAmountForText);

    rect.setOutlineColor(sf::Color::Red);
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineThickness(2);
    rect.setPosition(text9x9.getPosition().x, text9x9.getPosition().y+textTopOffset);

    window.clear();
    window.draw(rect);
    window.draw(text9x9);
    window.draw(text5x5);
    window.display();
  }

  return 0;
}