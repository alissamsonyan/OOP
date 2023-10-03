#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <string>

class Shape {
public:
    Shape(int id, const std::string& name);
    const std::string& GetName() const;
    int GetID() const;

private:
    std::string name;
    int shapeID;
};

#endif // SHAPES_HPP
