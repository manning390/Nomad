#include <string>
#include "State/StateInterface.hpp"
#include "State/StateStack.hpp"

StateStack::StateStack(){
    mStates = [];
    mStack = [];
}

void StateMachine::update(float elapsedTime){
    StateInterface top = mStack.peek();
    top.update(elapsedTime);
}

void StateMachine::render(){
    StateInterface top = mStack.peek();
    top.render();
}

void StateMachine::push(std::string stateName, int *param){
    StateInterface state = mStates[stateName];
    mStack.push(state);
}

StateInterface StateMachine::add(std::string name, StateInterface *state){
    return mStack.pop();
}