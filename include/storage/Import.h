#pragma once
#include <string>
#include <vector>
/**
 * \interface
 * @file Import.h 
 * 
 */
struct Import {
  virtual std::vector<std::string> importData(const std::string &params) = 0;
};
