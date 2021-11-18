#pragma once
#include <string>
#include "Define.h"
BEGIN_BUILDER_PATTERN_NAMESPACE

class Item
{
protected:
    std::string name;
    float       price;

public:
    virtual ~Item();
    std::string GetName();
    float       GetPrice();
};

END_BUILDER_PATTERN_NAMESPACE