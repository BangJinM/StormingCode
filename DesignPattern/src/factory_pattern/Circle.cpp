#include "Circle.h"
#include <iostream>

BEGIN_FACTORY_PATTERN_NAMESPACE

void Circle::Draw()
{
    std::cout << "Circle" << std::endl;
}

END_FACTORY_PATTERN_NAMESPACE