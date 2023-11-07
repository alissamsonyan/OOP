#include "Shape.hpp"

Shape::Shape(int id, const std::string& name) : id(id), name(name) {}

int Shape::GetID() const {
    return id;
}

const std::string& Shape::GetName() const {
    return name;
}
