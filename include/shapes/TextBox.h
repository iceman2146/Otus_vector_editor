#pragma once
#include "Base_shape.h"

struct TextBox : Shape {
  TextBox() = default;
  TextBox(const std::string &data) { writeData(data); }

  std::string readData() const override;
  void writeData(const std::string &data) override;
};
