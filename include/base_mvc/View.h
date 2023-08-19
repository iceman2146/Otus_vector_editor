#pragma once
#include "Model.h"
#include <memory>
/**
 * @file View.h 
 * 
 */
namespace View {
 /**
 * @brief класс отображения векторного редактора
 */ 
class DocumentView {
public:
  DocumentView(const Model::DocumentModel &model) : model_{model} {}

  void draw() {
    auto iters = model_.getData();
    for (auto iter = iters.first; iter != iters.second; ++iter) {
      Model::DocumentModel::id_type id;
      std::string data;
      std::tie(id, data) = (*iter);
    }
  }

private:
  const Model::DocumentModel &model_;
};
}; // namespace View