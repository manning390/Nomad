#ifndef STATE_STATE
#define STATE_STATE

#include <memory>

class StateMachine;

namespace sf {
    class RenderWindow;
}

class State {
    public:
        State(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
        virtual ~State() = default;

        State(const State&) = delete;
        State& operator= (const State&) = delete;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void update() = 0;
        virtual void draw() = 0;

        std::unique_ptr<State> next();

        bool isReplacing();

    protected:
        StateMachine& machine;
        sf::RenderWindow& window;

        bool replacing;

        std::unique_ptr<State> nextState;

};

#endif // STATE_STATE
