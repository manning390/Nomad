#include <iostream>
#include "State/StateMachine.hpp"

StateMachine::StateMachine(): resume{ false }, running{ false } {
    std::cout << "StateMachine Init" << std::endl;
}

void StateMachine::run(std::unique_ptr<State> state) {
    running = true;
    states.push(std::move(state));
}

void StateMachine::nextState() {
    if(resume) {
        // Clean current state
        if(!states.empty()) {
            states.pop();
        }

        // Resume previous
        if(!states.empty()) {
            states.top()->resume();
        }

        resume = false;
    }

    if(!states.empty()) {
        std::unique_ptr<State> temp = states.top()->next();

        // Only change states if there's a next one existing
        if(temp != nullptr) {
            if(temp->isReplacing())
                states.pop(); // Replace running
            else
                states.top()->pause(); // Pause running
            states.push(std::move(temp));
        }
    }
}

void StateMachine::lastState() {
    resume = true;
}

void StateMachine::update() {
    states.top()->update();
}

void StateMachine::draw(){
    states.top()->draw();
}
