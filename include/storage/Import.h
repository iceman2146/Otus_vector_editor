#pragma once
#include <string>
#include <vector>

/// Interface for loading a document to a external storage.
struct Import {
    /// Loading the document to the storage with parameters.
    /// @param params parameters for the storage
    /// @return std::vector of strings with serialized data
    virtual std::vector<std::string> importData(const std::string &params) = 0;
};
