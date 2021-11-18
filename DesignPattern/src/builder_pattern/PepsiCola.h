#pragma once
#include "Define.h"

#include "Drink.h"

BEGIN_BUILDER_PATTERN_NAMESPACE

class PepsiCola : public Drink
{
public:
    PepsiCola()
    {
        this->name  = "PepsiCola";
        this->price = 5.0f;
    }
};

END_BUILDER_PATTERN_NAMESPACE