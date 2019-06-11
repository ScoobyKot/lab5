

#include "Child.h"
#include <utility>

Child::Child() = default;

Child::Child(std::string name, std::string surname, int age, std::string school) {
    this->name = name;
    this->surname = surname;
    this->age = age;
    this->school = school;
}

Child::~Child() = default;


std::string Child::get_school() {
    return Child::school;
}