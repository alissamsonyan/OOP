#include "Shapes.hpp"

Shape::Shape(int id, const std::string& name) : name(name), shapeID(id) {}

const std::string& Shape::GetName() const {
    return name;
}

int Shape::GetID() const {
    return shapeID;
}
