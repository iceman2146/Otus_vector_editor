#pragma once
#include "Base_shape.h"
#include <string>

struct Rectangle : Shape {
  Rectangle() = default;
  Rectangle(const std::string &data) { writeData(data); }

  std::string readData() const override;
  void writeData(const std::string &) override;
};
