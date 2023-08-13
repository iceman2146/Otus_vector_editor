#pragma once
#include <string>
#include <vector>

/// Interface for saving a document to a external storage.
struct Export {
    /// Saving the document to the storage with parameters.
    /// @param data std::vector of strings with serialized data
    /// @param params parameters for the storage
    virtual void exportData(const std::vector<std::string> &data, const std::string &params) = 0;
};
