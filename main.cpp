#include "Controller.h"
#include "Model.h"
#include "View.h"
#include "Export_Import.h"
#include <iostream>
#include <string>

int main() {

    std::cout<<"EDITOR"<<std::endl;
    Model::DocumentModel model;
    View::DocumentView view(model);
    Controller::DocumentController controller(model, view);


    controller.addShape(Controller::Shapes::Circle, "x=100;y=323;radius=3");
    controller.addShape(Controller::Shapes::Rectangle, "x=10;y=30;width=100;height=390");
    controller.clear();

    Storage storage;
    controller.load(&storage, "filename: File.svg");
    auto rect_id = controller.addShape(Controller::Shapes::Rectangle, "x=20;y=5;width=100;height=50");
    std::cout << "Serialized data of Rectangle: " << controller.getShape(rect_id) << '\n';

    auto circle_id = controller.addShape(Controller::Shapes::Circle, "x=4;y=2;radius=6");
    controller.removeShape(rect_id);

    std::cout << "Serialized data of Circle: " << controller.getShape(circle_id) << '\n';

    controller.save(&storage, "filename: File.svg");

    return 0;
}
