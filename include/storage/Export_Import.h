#pragma once
#include "Export.h"
#include "Import.h"

/// Class for using SVG file as external storage for vector shapes.
class Storage : public Import, public Export {
    /// Loading serialized data of vector shapes from SVG file.
    /// @param params parameters for SVG file
    /// @return std::vector of strings with serialized data of vector shapes
    std::vector<std::string> importData(const std::string &params) override { return std::vector<std::string>{}; }

    /// Saving serialized data of vector shapes to SVG file.
    /// @param data std::vector of strings with serialized data of vector shapes
    /// @param params parameters for SVG file
    void exportData(const std::vector<std::string> &data, const std::string &params) override{};
};
