#include <map>
#include <memory>
#include <string>
#include "Helper/Stack.hpp"
#include "State/StateInterface.hpp"

class StateStack {
    public:
        StateStack();
        void update(float elapsedTime);
        void render();
        void push(std::string stateName);
        std::unique_ptr<StateInterface> pop();

    private:
        std::map<std::string, std::unique_ptr<StateInterface>> mStates;
        stack<std::unique_ptr<StateInterface>> mStack;
}