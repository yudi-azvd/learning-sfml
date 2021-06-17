#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <iostream>


#include <random>
#include <functional>

///////////////////////////////////////////////
// Sim, que vergonha. Variáveis globais
int alpha = 100;
int r = 255;
int g = 255;
int b = 255;
float x = 0, y = 0, radius = 10.0;
float circleOffset = radius;
sf::CircleShape circle(radius);
sf::RectangleShape rec({radius*2, radius*2});

bool isRightMouseButtonClicked = false;
///////////////////////////////////////////////


std::default_random_engine randGenerator;
std::uniform_int_distribution<int> distribuition(0, 255);
auto randomNumber = std::bind(distribuition, randGenerator);

void handleMouseButtonPressed(sf::Event event);
void handleMouseButtonReleased(sf::Event event);
void handleMouseScroll(sf::Event event);
void handleMouseMove(sf::Event event);

int main()
{
  sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

  circle.setFillColor(sf::Color(255, 255, 255, alpha));
  circle.setOrigin(circleOffset, circleOffset);
  rec.setOrigin(circleOffset, circleOffset);
  rec.setOutlineColor(sf::Color(r, g, b, 255/2));
  rec.setOutlineThickness(0.8);

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
          break;
        case sf::Event::TextEntered:
          if (event.text.unicode < 128)
            std::cout << "ASCII char typed: " << static_cast<char>(event.text.unicode) << std::endl;
          break;
        case sf::Event::MouseWheelScrolled:
          handleMouseScroll(event);
          break;
        case sf::Event::MouseButtonPressed:
          handleMouseButtonPressed(event);
          break;
        case sf::Event::MouseButtonReleased:
          handleMouseButtonReleased(event);
          break;
        case sf::Event::MouseMoved:
          handleMouseMove(event);
          break;
        default:
          break;
      }
    }

    rec.setPosition(x+0, y+0);
    rec.setFillColor(sf::Color(255-r, 255-g, 255-b, 255/2));
    circle.setFillColor(sf::Color(r, g, b, alpha));
    window.clear();
    window.draw(circle);
    window.draw(rec);
    window.display();
  }

  return 0;
}


void handleMouseButtonPressed(sf::Event event) {
  if (event.mouseButton.button == sf::Mouse::Right) {
    isRightMouseButtonClicked = true;
  }
}


void handleMouseButtonReleased(sf::Event event) {
  if (event.mouseButton.button == sf::Mouse::Right) {
    isRightMouseButtonClicked = false;
    return;
  }

  if (event.mouseButton.button != sf::Mouse::Left)
    return;

  std::cout << "left click" << std::endl;

  r = randomNumber();
  g = randomNumber();
  b = randomNumber();
  // std::printf("%d %d %d\n", r, g, b);
}


void handleMouseScroll(sf::Event event) {
  float mouseWheelScrollDelta = event.mouseWheelScroll.delta;
  std::cout << "isRightMouseButtonClicked=" << isRightMouseButtonClicked << std::endl;

  if (isRightMouseButtonClicked) {
    radius = circle.getRadius();
    float prevX = circle.getPosition().x;
    float prevY = circle.getPosition().y;

    circle.setRadius(radius + 2*mouseWheelScrollDelta);
    circleOffset = circle.getRadius();
    circle.setOrigin(circleOffset, circleOffset);
    rec.setOrigin(circleOffset, circleOffset);
    rec.setSize({circleOffset*2, circleOffset*2});

    std::cout << " mouse x " << event.mouseWheelScroll.x << std::endl;
    std::cout << " mouse y " << event.mouseWheelScroll.y << std::endl;
    std::cout << "circle x " << prevX << std::endl;
    std::cout << "circle y " << prevY << std::endl;
    std::cout << "circle origin x " << circle.getOrigin().x << std::endl;
    std::cout << "circle origin y " << circle.getOrigin().y << std::endl;
    return;
  }

  if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel)
    std::cout << "wheel type: vertical" << std::endl;
  std::cout << "wheel movement: " << mouseWheelScrollDelta << std::endl;
  alpha += 5*mouseWheelScrollDelta;
}


void handleMouseMove(sf::Event event) {
  if (isRightMouseButtonClicked) {
    auto prevX = x;
    auto prevY = y;
    auto newX = event.mouseMove.x;
    auto newY = event.mouseMove.y;
    auto xDisplacement = prevX - newX;
    auto yDisplacement = prevY - newY;
    auto xScale = circle.getScale().x;
    auto yScale = circle.getScale().y;
    std::cout << "disp " << xDisplacement << std::endl;
    std::cout << "xscale " << xScale << std::endl;
    circle.setScale({xScale*xDisplacement/100+.1, yScale*yDisplacement/100+.1});
    return;
  }

  std::cout << "mouse move" << std::endl;
  std::printf("(%3d, %3d)\n", event.mouseMove.x, event.mouseMove.y);
  x = event.mouseMove.x;
  y = event.mouseMove.y;
  circle.setPosition(x, y);
}