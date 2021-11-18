#pragma once
#include "Define.h"

#include "Drink.h"

BEGIN_BUILDER_PATTERN_NAMESPACE

class CocaCola : public Drink
{
public:
    CocaCola()
    {
        this->name  = "CocaCola";
        this->price = 5.0f;
    }
};

END_BUILDER_PATTERN_NAMESPACE