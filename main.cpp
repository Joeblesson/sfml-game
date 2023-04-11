#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML GAME", sf::Style::Fullscreen);
    window.setFramerateLimit(60);

    window.setMouseCursorVisible(false);

    sf::RectangleShape rect;
    int cc;

    sf::Vector2f rectanglePos(600, 350);

    rect.setPosition(rectanglePos);

    rect.setSize(sf::Vector2f(150, 150));
    rect.setFillColor(sf::Color::Red);

    float xVelocity = 4;
    float yVelocity = 4;

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
        
        if(rectanglePos.x < 0 || rectanglePos.x > 1770) {
            xVelocity *= -1;
            cc += 1;
            if(cc == 3) {
                cc = 0;
            }
            switch(cc) {
                case 0:
                    rect.setFillColor(sf::Color::Red);
                    break;
                case 1:
                    rect.setFillColor(sf::Color::Green);
                    break;
                case 2: 
                    rect.setFillColor(sf::Color::Blue);
                    break;
                default:
                    rect.setFillColor(sf::Color::Red);
                    break;
            }
            
        }

        if(rectanglePos.y < 0 || rectanglePos.y > 930) {
            yVelocity *= -1;
            cc++;
            if(cc == 3) {
                cc = 0;
            }
            switch(cc) {
                case 0:
                    rect.setFillColor(sf::Color::Red);
                    break;
                case 1:
                    rect.setFillColor(sf::Color::Green);
                    break;
                case 2: 
                    rect.setFillColor(sf::Color::Blue);
                    break;
                default:
                    rect.setFillColor(sf::Color::Red);
                    break;
            }
        }

        rectanglePos.x += xVelocity;
        rectanglePos.y += yVelocity;
        rect.setPosition(rectanglePos);

        // render 

        window.clear();
        window.draw(rect);
        window.display();
    }
}