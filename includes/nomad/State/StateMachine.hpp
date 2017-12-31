#ifndef STATE_STATEMACHINE
#define STATE_STATEMACHINE

#include <stack>
#include <memory>
#include <string>
#include "State/State.hpp"

class State;

namespace sf {
    class RenderWindow;
}

class StateMachine {
    public:
        StateMachine();

        void run(std::unique_ptr<State> state);

        void nextState();
        void lastState();

        void update();
        void draw();

        bool isRunning() { return running; }
        void quit() { running = false; }

        template<typename T>
        static std::unique_ptr<T> build(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
    private:
        std::stack<std::unique_ptr<State>> states;

        bool resume;
        bool running;
};

template <typename T>
std::unique_ptr<T> StateMachine::build(StateMachine& machine, sf::RenderWindow& window, bool replace) {
    return std::unique_ptr<T>(new T(machine, window, replace));
}

#endif // STATE_STATEMACHINE