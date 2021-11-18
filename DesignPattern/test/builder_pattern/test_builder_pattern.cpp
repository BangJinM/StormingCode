
#include "builder_pattern/ChikenHamburg.h"
#include "builder_pattern/CocaCola.h"
#include "builder_pattern/Meal.h"
#include "builder_pattern/PepsiCola.h"
#include "builder_pattern/VegHamburg.h"

USING_BUILDER_PATTERN_NAMESPACE
int main(int argc, char const *argv[])
{
    Meal firstMeal;
    firstMeal.AddItem(new ChikenHamburg());
    firstMeal.AddItem(new PepsiCola());
    firstMeal.ShowPrice();
    firstMeal.ShowItems();

    Meal secondMeal;
    secondMeal.AddItem(new VegHamburg());
    secondMeal.AddItem(new CocaCola());
    secondMeal.ShowPrice();
    secondMeal.ShowItems();
    return 0;
}
