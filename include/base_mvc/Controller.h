#pragma once
#include "Model.h"
#include "View.h"


#include "Export.h"
#include "Import.h"


#include "Circle.h"
#include "Rectangle.h"
#include "TextBox.h"

#include <string>
namespace Controller{

enum class Shapes {
    Circle,
    Rectangle,
    TextBox,
};


class DocumentController {
  public:
    DocumentController(Model::DocumentModel &model, View::DocumentView &view) : model_{model}, view_{view} {}

    Model::DocumentModel::id_type addShape(Shapes shape, const std::string &param) {
        Model::DocumentModel::id_type id;

        switch (shape) {
        case Shapes::Circle:
            id = model_.addShape(Circle(param).readData());
            break;
        case Shapes::Rectangle:
            id = model_.addShape(Rectangle(param).readData());
            break;
        case Shapes::TextBox:
            id = model_.addShape(TextBox(param).readData());
            break;
        }

        view_.draw();
        return id;
    }

    bool removeShape(unsigned long id) {
        bool result = model_.removeShape(id);
        view_.draw();
        return result;
    }

    /// Delete all vector shapes from the document.
    void clear() { model_.clear(); }

    /// Get serialized data of vector shape by identifier.
    std::string getShape(unsigned long id) { return model_.getShape(id); }

    /// Load a document from external storage.
    void load(Import *importer, const std::string &params) { model_.load(importer, params); }

    /// Save a document to external storage.
    void save(Export *exporter, const std::string &params) { model_.save(exporter, params); }

  private:
    Model::DocumentModel &model_;
    View::DocumentView &view_;
};};