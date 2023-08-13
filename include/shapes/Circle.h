#pragma once
#include "Base_shape.h"
#include <string>

struct Circle : Shape {
    Circle() = default;
    Circle(const std::string &data) { writeData(data); }
    std::string readData() const override;
    void writeData(const std::string &) override;
};
