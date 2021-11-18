#pragma once
#include "Define.h"

#include "Hamburg.h"

BEGIN_BUILDER_PATTERN_NAMESPACE

class VegHamburg : public Hamburg
{
public:
    VegHamburg()
    {
        this->name  = "VegHamburg";
        this->price = 5.0f;
    }
};

END_BUILDER_PATTERN_NAMESPACE