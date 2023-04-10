#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML GAME");
    window.setFramerateLimit(60);

    sf::RectangleShape rect;

    sf::Font Roboto;
    Roboto.loadFromFile("fonts\\Roboto.ttf");

    sf::Text myText;
    myText.setFont(Roboto);
    myText.setFillColor(sf::Color::Blue);
    myText.setString("Press Esc to exit program");
    myText.setPosition(300, 400);
    myText.setCharacterSize(60);

    sf::Vector2f rectanglePos(600, 350);

    rect.setPosition(rectanglePos);

    rect.setSize(sf::Vector2f(100, 100));

    float xVelocity = 3;
    float yVelocity = 3;

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }
        //physics
        
        if(rectanglePos.x < 0 || rectanglePos.x > 1180) {
            xVelocity *= -1;
        }

        if(rectanglePos.y < 0 || rectanglePos.y > 620) {
            yVelocity *= -1;
        }

        rectanglePos.x += xVelocity;
        rectanglePos.y += yVelocity;
        rect.setPosition(rectanglePos);

        // render 

        window.clear();
        window.draw(myText);
        window.draw(rect);
        window.display();
    }

    
}