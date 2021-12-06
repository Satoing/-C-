#ifndef BACKGROUND_H
#define BACKGROUND_H
#pragma once
#include <acllib.h>
#include "macro.h"

class background{
private:
    int _space;
    ACL_Color _bgcolor,_linecolor;
public:
    background(int space,ACL_Color bgcolor,ACL_Color linecolor);
    void paintbg();
};
#endif