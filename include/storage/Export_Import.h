#pragma once
#include "Export.h"
#include "Import.h"

class Storage : public Import, public Export {
    std::vector<std::string> importData(const std::string &params) override { return std::vector<std::string>{}; }
    void exportData(const std::vector<std::string> &data, const std::string &params) override{};
};
