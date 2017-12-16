#include <string>
#include <memory>
#include <string>
#include "State/StateInterface.hpp"

class StateMachine {
    public:
        StateMachine();
        void update(float dTime);
        void render();
        void change(std::string stateName, int *param);
        void add(std::string name, std::unique_ptr<StateInterface> state);

    private:
        std::map<std::string, std::unique_prt<StateInterface>> mStates;
        StateInterface* mCurrentState;
};