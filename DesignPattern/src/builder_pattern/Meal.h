#pragma once
#include <vector>
#include "Define.h"
#include "Item.h"

BEGIN_BUILDER_PATTERN_NAMESPACE

class Meal
{
private:
    std::vector<Item *> items;

public:
    ~Meal();

    void AddItem(Item *item);

    void  ShowPrice();
    void ShowItems();
};

END_BUILDER_PATTERN_NAMESPACE