#pragma once
#include <string>
#include <vector>
struct Import {
  virtual std::vector<std::string> importData(const std::string &params) = 0;
};
