#pragma once
#include <string>
#include "Define.h"
#include "Shape.h"

BEGIN_FACTORY_PATTERN_NAMESPACE

class Square : public Shape
{
public:
    virtual void Draw();
};

END_FACTORY_PATTERN_NAMESPACE
