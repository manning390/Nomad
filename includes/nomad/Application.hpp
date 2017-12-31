#ifndef APPLICATION
#define APPLICATION

#include "Config/Config.hpp"
#include "State/StateMachine.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Application {
    public:
        Application();
        void run();

    private:
        void initConfig();
        config::data config;
        sf::RenderWindow window;
        StateMachine machine;
};

#endif // APPLICATION