#pragma once
#include "hp.h"
#include "StatBlock.h"

class Warrior : public hp, public StatBlock
{

public:
    static const hptype HPGROWTH = (hptype)19u;
    static const stattype BASESTR = (stattype)4u;
    static const stattype BASEINT = (stattype)1u;
    Warrior() : hp(HPGROWTH, HPGROWTH), StatBlock(BASESTR, BASEINT) {}

private:
};