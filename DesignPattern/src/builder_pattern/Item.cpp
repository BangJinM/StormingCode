#include "Item.h"
BEGIN_BUILDER_PATTERN_NAMESPACE

Item::~Item() {}

std::string Item::GetName()
{
    return name;
}

float Item::GetPrice()
{
    return price;
}

END_BUILDER_PATTERN_NAMESPACE
