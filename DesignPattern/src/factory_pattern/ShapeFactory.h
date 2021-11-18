#pragma once

#include "Define.h"
#include "Shape.h"

BEGIN_FACTORY_PATTERN_NAMESPACE

enum ShapeType
{
    ShapeTypeCircle,
    ShapeTypeRectangle,
    ShapeTypeSquare
};

class ShapeFactory
{
public:
    static Shape *GetShape(ShapeType type);
};

END_FACTORY_PATTERN_NAMESPACE