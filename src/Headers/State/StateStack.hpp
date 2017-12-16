#include <string>
#include "State/StateInterface.hpp"

class StateStack {
    public:
        StateStack();
        void update(float elapsedTime);
        void render();
        void push(std::string stateName);
        StateInterface pop();

    private:
        std::map<std::string, StateInterface> mStates;
        stack<StateInterface> mStack;
}