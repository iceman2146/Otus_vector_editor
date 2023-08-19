#pragma once
#include <string>
#include <vector>
/**
 * 
 * \interface
 * @file Export.h 
 * 
 */
struct Export {

  virtual void exportData(const std::vector<std::string> &data,
                          const std::string &params) = 0;
};
