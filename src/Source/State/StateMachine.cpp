#include <map>
#include <memory>
#include <string>
#include "State/StateMachine.hpp"
#include "State/StateInterface.hpp"

StateMachine::StateMachine() {
    mCurrentState = nullptr;
}

void StateMachine::update(float elapsedTime) {
    mCurrentState->update(elapsedTime);
}

void StateMachine::render() {
    mCurrentState->render();
}

void StateMachine::change(std::string stateName, int* param) {
    mCurrentState->onExit();
    mCurrentState = mStates[stateName].get();
    mCurrentState->onEnter(param);
}

void StateMachine::add(std::string name, std::unique_ptr<StateInterface> state) {
    mStates[name] = std::move(state);
}

