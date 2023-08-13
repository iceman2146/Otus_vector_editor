#pragma once
#include "Model.h"
#include <memory>
namespace View{
/// DocumentView can be any output representation of information.
class DocumentView {
  public:
    /// Contructor requiring the DocumentModel as data source.
    /// @param model DocumentModel
    DocumentView(const Model::DocumentModel &model) : model_{model} {}

    /// Draw elements in GUI.
    void draw() {
        auto iters = model_.getData();
        for (auto iter = iters.first; iter != iters.second; ++iter) {
            Model::DocumentModel::id_type id;
            std::string data;

            std::tie(id, data) = (*iter);
            // draw vector shape
        }
    }

  private:
    const Model::DocumentModel &model_;
};
};