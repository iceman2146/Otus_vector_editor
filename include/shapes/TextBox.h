#pragma once
#include "Base_shape.h"

/// TextBox is a vector shape.
struct TextBox : Shape {
    TextBox() = default;
    TextBox(const std::string &data) { writeData(data); }

    std::string readData() const override;
    void writeData(const std::string &data) override;
};
