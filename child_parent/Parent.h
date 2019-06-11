

#ifndef JMP2_PARENT_H
#define JMP2_PARENT_H

#include "Child.h"

class Parent {

private:
    std::string name;
    std::string surname;
    int age{};
    Child *child{};

public:
    Parent();

    Parent(std::string name, std::string surname, int age, Child *child);

    ~Parent();

    void assignToOtherSchool(std::string name);

};

#endif //JMP2_PARENT_H
