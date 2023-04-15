//
// Created by Sherman Yan on 12/6/22.
//

#ifndef STATES_H
#define STATES_H
#include <map>
#include "Enums/StatesEnum.h"

class States {
private:
    std::map<StatesEnum,bool> map;
    void load();
public:
    States();
    bool checkStates(StatesEnum state) const;
    void enableState(StatesEnum state);
    void disableState(StatesEnum state);
    void setState(StatesEnum state, bool value);
    void toggleState(StatesEnum state);

};

#endif //STATES_H
