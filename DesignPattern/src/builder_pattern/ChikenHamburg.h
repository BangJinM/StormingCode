#pragma once
#include "Define.h"

#include "Hamburg.h"

BEGIN_BUILDER_PATTERN_NAMESPACE

class ChikenHamburg : public Hamburg
{
public:
    ChikenHamburg()
    {
        this->name  = "ChikenHamburg";
        this->price = 5.0f;
    }
};

END_BUILDER_PATTERN_NAMESPACE