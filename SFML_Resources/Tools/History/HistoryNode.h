//
// Created by Sherman Yan on 3/20/23.
//

#ifndef TEXTINPUT_HISTORYNODE_H
#define TEXTINPUT_HISTORYNODE_H
#include "Snapshot.h"
#include "AppComponent.h"

struct HistoryNode
{
    Snapshot snapshot;
    AppComponent* component;
};

#endif //TEXTINPUT_HISTORYNODE_H
