#pragma once
#include "Base_shape.h"
#include <string>

/// Rectangle is a vector shape.
struct Rectangle : Shape {
    Rectangle() = default;
    Rectangle(const std::string &data) { writeData(data); }

    std::string readData() const override;
    void writeData(const std::string &) override;
};

