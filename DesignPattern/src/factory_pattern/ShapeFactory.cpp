#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
BEGIN_FACTORY_PATTERN_NAMESPACE

Shape *ShapeFactory::GetShape(ShapeType type)
{
    Shape *shape;
    switch (type)
    {
        case ShapeType::ShapeTypeCircle: shape = new Circle(); break;
        case ShapeType::ShapeTypeRectangle: shape = new Rectangle(); break;
        case ShapeType::ShapeTypeSquare: shape = new Square(); break;
        default: break;
    }
    return shape;
}

END_FACTORY_PATTERN_NAMESPACE
