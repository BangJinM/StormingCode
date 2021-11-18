
// #include "factory_pattern/Circle.h"
// #include "factory_pattern/Rectangle.h"
#include "factory_pattern/Shape.h"
#include "factory_pattern/ShapeFactory.h"
// #include "factory_pattern/Square.h"

USING_FACTORY_PATTERN_NAMESPACE
int main(int argc, char const *argv[])
{
    Shape *shape1 = ShapeFactory::GetShape(ShapeType::ShapeTypeCircle);
    Shape *shape2 = ShapeFactory::GetShape(ShapeType::ShapeTypeRectangle);
    Shape *shape3 = ShapeFactory::GetShape(ShapeType::ShapeTypeSquare);
    shape1->Draw();
    shape2->Draw();
    shape3->Draw();
    return 0;
}
