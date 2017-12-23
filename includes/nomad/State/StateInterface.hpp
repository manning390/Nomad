#ifndef STATE_STATEINTERFACE
#define STATE_STATEINTERFACE

class StateInterface {
    public:
        virtual void update(float dTime) = 0;
        virtual void render() = 0;
        virtual void onEnter(int* param) = 0;
        virtual void onExit() = 0;
        virtual ~StateInterface() = 0;
};

#endif // STATE_STATEINTERFACE
