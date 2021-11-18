#include "Rectangle.h"
#include <iostream>

BEGIN_FACTORY_PATTERN_NAMESPACE

void Rectangle::Draw()
{
    std::cout << "Rectangle" << std::endl;
}

END_FACTORY_PATTERN_NAMESPACE