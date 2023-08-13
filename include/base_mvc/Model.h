#pragma once
#include "Base_shape.h"
#include "Export.h"
#include "Import.h"

#include <map>
#include <string>
#include <vector>
#include <iostream>
namespace Model{
/// DocumentModel directly manages the data, logic and rules of the application.
class DocumentModel {
  public:
    using id_type = unsigned long;

    /// Add a vector shape as serialized data.

    id_type addShape(const std::string &serialized_data) {
        shapes_[++current_id_] = serialized_data;
        //std::cout<<"shape wit id "<<current_id_<<" in document"<<std::endl;
        return current_id_;
    }

    /// Remove a vector shape from document.

    bool removeShape(id_type id) { return (shapes_.erase(id) > 0); }

    /// Delete all vector shapes from the document.
    void clear() {
        shapes_.clear();
        current_id_ = 0;
    }

    /// Get serialized data of vector shape by identifier.

    std::string getShape(id_type id) const { return shapes_.at(id); }

    /// Get a pair of iterators for all vector shapes in document.

    auto getData() const {
        using pair_element = decltype(shapes_)::const_iterator;
        return std::make_pair<pair_element, pair_element>(shapes_.cbegin(), shapes_.cend());
    }

    /// Load a document from external storage.

    void load(Import *importer, const std::string &params) {
        clear();
        for (const auto &data : importer->importData(params)) {
            shapes_[++current_id_] = data;
        }
    }

    /// Save a document to external storage.

    void save(Export *exporter, const std::string &params) const {
        std::vector<std::string> data;
        data.reserve(shapes_.size());

        for (const auto &shape : shapes_) {
            data.push_back(shape.second);
        }

        exporter->exportData(data, params);
    }

  private:
    std::map<id_type, std::string> shapes_;
    id_type current_id_ = 0;
};
};