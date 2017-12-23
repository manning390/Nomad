#include <fstream>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "State/StateMachine.hpp"
#include "State/MainMenuState.hpp"
#include "Config/Config.hpp"

int main(int argc, char ** argv) {
    // Generate clock for diff in frames
    sf::Clock clock;

    // Create config var
    config::data config;
    std::ifstream f("config");
    f >> config; // load configs
    f.close();

    // Create state machine
    StateMachine gameState;
    // gameState.add("mainmenu", new MainMenuState());

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(config.getInt("windowX"), config.getInt("windowY")), "Nomad " + config["ver"]);


    // Set the Icon
    sf::Image icon;
    if(!icon.loadFromFile("assets/icon.png")) return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Create states

    // Reset clock after init
    clock.restart();
    // Window Loop
    while(window.isOpen()) {
        // Window Events
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) window.close();
        }

        // Clear the screen
        window.clear();


        //Run State Loop
        // gameState.update(clock.restart());
        // gameState.render();

        // Update window
        window.display();
    }
    return 0;
}
