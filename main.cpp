#include "Controller.h"
#include "Model.h"
#include "View.h"
#include "Export_Import.h"
#include <iostream>
#include <string>

int main() {
    // ***************************
    // *  Setup MVC components   *
    // ***************************
    std::cout<<"EDITOR"<<std::endl;
    Model::DocumentModel model;
    View::DocumentView view(model);
    Controller::DocumentController controller(model, view);

    // ****************************
    // * Work with empty document *
    // ****************************
    controller.addShape(Controller::Shapes::Circle, "x=100;y=323;radius=3");
    controller.addShape(Controller::Shapes::Rectangle, "x=10;y=30;width=100;height=390");
    controller.clear();

    // *****************************************
    // * Load from storage and modify document *
    // *****************************************
    Storage storage;
    controller.load(&storage, "filename: funny.svg");
    auto rect_id = controller.addShape(Controller::Shapes::Rectangle, "x=100;y=10;width=140;height=30");
    auto circle_id = controller.addShape(Controller::Shapes::Circle, "x=10;y=5;radius=12");
    controller.removeShape(rect_id);

    std::cout << "Serialized data of Circle: " << controller.getShape(circle_id) << '\n';

    // save to storage with new filename
    controller.save(&storage, "filename: File.svg");

    return 0;
}
