//
// Created by Sherman Yan on 3/20/23.
//

#ifndef TEXTINPUT_HISTORY_H
#define TEXTINPUT_HISTORY_H
#include "HistoryNode.h"
#include <stack>

class History {
private:
    static std::stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();

};


#endif //TEXTINPUT_HISTORY_H
