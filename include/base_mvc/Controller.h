#pragma once
#include "Model.h"
#include "View.h"

#include "Export.h"
#include "Import.h"

#include "Circle.h"
#include "Rectangle.h"
#include "TextBox.h"

#include <string>
/**
 * @file Controller.h 
 * 
 */
namespace Controller {
 /**
 * @brief перечисление возможных фигур векторного редактора
 */ 
enum class Shapes {
  Circle,
  Rectangle,
  TextBox,
};
 /**
 * @brief класс контроллера векторного редактора
 */ 
class DocumentController {
public:
  DocumentController(Model::DocumentModel &model, View::DocumentView &view)
      : model_{model}, view_{view} {}

  Model::DocumentModel::id_type addShape(Shapes shape,
                                         const std::string &param) {
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
    
    return result;
  }

  void clear() { model_.clear(); }

  std::string getShape(unsigned long id) { return model_.getShape(id); }

  void load(Import *importer, const std::string &params) {
    model_.load(importer, params);
  }

  void save(Export *exporter, const std::string &params) {
    model_.save(exporter, params);
  }

private:
  Model::DocumentModel &model_;
  View::DocumentView &view_;
};
}; // namespace Controller