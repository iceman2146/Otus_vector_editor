#pragma once
#include "Model.h"
#include <memory>
namespace View{

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
};