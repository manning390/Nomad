#include "State/State.hpp"

State::State(StateMachine& machine, sf::RenderWindow& window, bool replace): machine{ machine}, window{ window }, replacing{ replace } {

}

std::unique_ptr<State> State::next() {
    return std::move(this->nextState);
}

bool State::isReplacing() {
    return this->replacing;
}