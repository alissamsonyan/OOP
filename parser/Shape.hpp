#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>

class Shape {
public:
    Shape(int id, const std::string& name);

    int GetID() const;
    const std::string& GetName() const;

private:
    int id;
    std::string name;
};

#endif
