#pragma once
#include <string>
struct Shape {
    virtual std::string readData() const = 0;
    virtual void writeData(const std::string &) = 0;
};
