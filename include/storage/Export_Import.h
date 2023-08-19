#pragma once
#include "Export.h"
#include "Import.h"
#include <iostream>
/**
 * @file Export_Import.h 
 * 
 */
class Storage : public Import, public Export {
  std::vector<std::string> importData(const std::string &params) override {
    std::cout<<"importData: "<<params<<std::endl;
    return std::vector<std::string>{};
  }
  void exportData(const std::vector<std::string> &data,
                  const std::string &params) override{
                    std::cout<<"ExportData: "<<params<<std::endl;
                  };
};
