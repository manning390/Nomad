#include <map>
#include <memory>
#include <string>
#include "Utility/Stack.hpp"
#include "State/StateInterface.hpp"
#include "State/StateStack.hpp"

StateStack::StateStack(){}

void StateMachine::update(float elapsedTime){
    StateInterface *top = std::move(mStack.peek());
    top->update(elapsedTime);
}

void StateMachine::render(){
    StateInterface *top = std::move(mStack.peek());
    top->render();
}

void StateMachine::push(std::string stateName, int *param){
    std::unique_ptr<StateInterface> state = std::move(mStates[stateName]);
    mStack.push(state);
}

std::unique_ptr<StateInterface> StateMachine::pop(){
    return std::move(mStack.pop());
}