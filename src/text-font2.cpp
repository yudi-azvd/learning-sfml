#include <SFML/Graphics.hpp>

int main(int argc, char ** argv)
{
    sf::RenderWindow app(sf::VideoMode(800u, 600u), "font");
    sf::Font font;
    font.loadFromFile("assets/DejaVuSans.ttf");
    sf::Text txt("", font);

    while(app.isOpen())
    {
        sf::Event eve;
        while(app.pollEvent(eve))
        {
            switch(eve.type)
            {
            case sf::Event::Closed:
                app.close();
                break;
            case sf::Event::TextEntered:
                txt.setString(txt.getString() + eve.text.unicode);
                break;
            }//switch
        }//while

        app.clear();

        sf::FloatRect r = txt.getLocalBounds();
        sf::RectangleShape sha;
        sha.setFillColor(sf::Color(0x7f7f7fff));
        sha.setPosition(sf::Vector2f(r.left, r.top));
        sha.setSize(sf::Vector2f(r.width, r.height));
        app.draw(sha);
        app.draw(txt);
        app.display();
    }//while

    return 0;
}