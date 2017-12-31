#include "Application.hpp"
#include "State/IntroState.hpp"
#include <SFML/Graphics/Image.hpp>

Application::Application() {
    initConfig();
};

void Application::run() {
    // Output so we know we're running
    std::cout << config["ver"] << std::endl;

    // Create window
    window.create(sf::VideoMode{config.getUInt("windowX"), config.getUInt("windowY")}, config["ver"], sf::Style::Titlebar | sf::Style::Close);

    // Set Icon
    sf::Image icon;
    if(!icon.loadFromFile("assets/icon.png"))
        std::cout << "Icon did not load" << std::endl;
    else
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    // Init engine
    machine.run(StateMachine::build<IntroState>(machine, window, true));

    // Main Loop
    while(machine.isRunning()) {
        machine.nextState();
        machine.update();
        machine.draw();
    }

};

void Application::initConfig() {
    std::ifstream f("config");
    f >> config; // load configs
    f.close();
}