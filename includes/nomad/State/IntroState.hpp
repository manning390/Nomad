#ifndef STATE_INTROSTATE
#define STATE_INTROSTATE

#include <vector>
#include "State/State.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class StateMachine;

namespace sf {
    class RenderWindow;
}

class IntroState : public State {
    public:
        IntroState(StateMachine& game, sf::RenderWindow& window, bool replace = true);

        void pause();
        void resume();

        void update();
        void draw();

    private:
        sf::Texture bgTex;
        sf::Sprite bg;
        sf::RectangleShape fader;
        sf::Color alpha;
        sf::Font font;
        std::vector<sf::Text> texts;
        unsigned int cursorPos = 0;
};

#endif // STATE_INTROSTATE