#include <utility>
#include "Parent.h"

Parent::Parent() = default;

Parent::Parent(std::string name, std::string surname, int age, Child *child) {
    this->name = std::move(name);
    this->surname = std::move(surname);
    this->age = age;
    this->child = child;
}

Parent::~Parent() = default;

void Parent::assignToOtherSchool(std::string school_name) {
    this->child->school = std::move(school_name);
}


