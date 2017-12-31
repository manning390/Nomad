#include <memory>
#include <iostream>

#include "State/IntroState.hpp"
#include "State/StateMachine.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

IntroState::IntroState(StateMachine& machine, sf::RenderWindow& window, bool replace) : State{ machine, window, replace } {
    bgTex.loadFromFile("assets/intro.png");
    bg.setColor(sf::Color::White);
    bg.setTexture(bgTex, true);

    // Start opaque
    alpha = sf::Color{0, 0, 0, 255};

    // Fill the fader service with black
    fader.setFillColor(alpha);
    fader.setSize(static_cast<sf::Vector2f>(bgTex.getSize()));

    // Load Font
    if(!font.loadFromFile("assets/fonts/uni0553-webfont.ttf")){
        std::cout << "Error loading font" << std::endl;
    }

    // Stylize and Position text
    unsigned int i = 0;
    const int charSize = 30;
    const int vMargin = 30;
    const int vPad = 5;
    const std::string selections[] = {"Start", "Options"};
    for(std::string str : selections) {
        sf::Text text(str, font);
        sf::FloatRect bounding = text.getLocalBounds();

        // Center text and set height
        text.setOrigin(bounding.left + bounding.width/2.0f, bounding.top + bounding.height/2.0f);
        text.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f + (charSize * i) + (vPad * i) + vMargin));

        text.setCharacterSize(charSize);
        text.setFillColor(sf::Color::White);
        text.setOutlineColor(sf::Color::Black);
        texts.push_back(text);
        i++;
    }

    std::cout << "IntroState Init" << std::endl;
}

void IntroState::pause() {
    // Nope
    std::cout << "IntroState Pause" << std::endl;
}

void IntroState::resume() {
    // Nope
    std::cout << "IntroState Resume" << std::endl;
}

void IntroState::update() {
    sf::Event event;

    while(window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                machine.quit();
                break;
            case sf::Event::KeyPressed:
                switch(event.key.code) {
                    case sf::Keyboard::Escape:
                        machine.quit();
                        break;
                    case sf::Keyboard::Space:
                        std::cout << "Move to next State" << std::endl;
                        break;
                    case sf::Keyboard::Down:
                        std::cout << "Move Cursor Up" << std::endl;
                        break;
                    case sf::Keyboard::Up:
                        std::cout << "Move Cursor Down" << std::endl;
                            break;
                    default:
                    break;
                }
            default:
            break;
        }
    }

    if(alpha.a != 0)
        alpha.a--;
    fader.setFillColor(alpha);
}

void IntroState::draw() {
    window.clear();

    window.draw(bg);

    if(alpha.a != 0)
        window.draw(fader);
    else {
        // Draw options and cursor
        for(sf::Text text : texts) {
            window.draw(text);
        }
    }

    window.display();
}