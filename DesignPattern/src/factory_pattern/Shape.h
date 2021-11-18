#pragma once

#include "Define.h"

BEGIN_FACTORY_PATTERN_NAMESPACE

class Shape
{
public:
    virtual void Draw() = 0;
};

END_FACTORY_PATTERN_NAMESPACE