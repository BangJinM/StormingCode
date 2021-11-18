#include "Meal.h"
#include <iostream>

BEGIN_BUILDER_PATTERN_NAMESPACE

Meal::~Meal()
{
    for (auto item : items)
    {
        delete item;
    }
    items.clear();
}

void Meal::ShowPrice()
{
    int price = 0;
    for (auto item : items)
    {
        price += item->GetPrice();
    }
    std::cout << "Meal Price:" << price << std::endl;
}

void Meal::ShowItems()
{
    std::cout << "Meal Items:" << std::endl;
    for (auto item : items)
    {
        std::cout << "Item Name:" << item->GetName() << std::endl;
    }
}

void Meal::AddItem(Item *item)
{
    items.push_back(item);
}

END_BUILDER_PATTERN_NAMESPACE
