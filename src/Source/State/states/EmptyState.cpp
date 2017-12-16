#include "State/StateInterface.hpp"

class EmptyState : public StateInterface {}

void EmptyState::update(float dTime){
    // Nope.
}

void EmptyState::render(){
    // Nope.
}

void EmptyState::onEnter(){
    // Nope.
}

void EmptyState::onExit(){
    // Nope.
}
