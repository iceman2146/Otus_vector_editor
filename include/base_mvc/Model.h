#pragma once
#include "Base_shape.h"
#include "Export.h"
#include "Import.h"

#include <iostream>
#include <map>
#include <string>
#include <vector>
namespace Model {

class DocumentModel {
public:
  using id_type = unsigned long;
  id_type addShape(const std::string &serialized_data) {
    shapes_[++current_id_] = serialized_data;

    return current_id_;
  }
  bool removeShape(id_type id) {
    std::cout << "remove shape " << id << std::endl;
    return (shapes_.erase(id) > 0);
  }
  void clear() {

    shapes_.clear();
    current_id_ = 0;
  }
  std::string getShape(id_type id) const { return shapes_.at(id); }
  auto getData() const {
    using pair_element = decltype(shapes_)::const_iterator;
    return std::make_pair<pair_element, pair_element>(shapes_.cbegin(),
                                                      shapes_.cend());
  }
  void load(Import *importer, const std::string &params) {
    clear();
    for (const auto &data : importer->importData(params)) {
      shapes_[++current_id_] = data;
    }
  }
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
}; // namespace Model