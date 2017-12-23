#ifndef STATE_MAINMENUSTATE
#define STATE_MAINMENUSTATE

#include "State/StateInterface.hpp"

class MainMenuState : public StateInterface {
    public:
        MainMenuState();
        void update(float dTime) override;
        void render() override;
        void onEnter(int* param) override;
        void onExit() override;
};

#endif // STATE_MAINMENUSTATE