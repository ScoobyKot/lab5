#include <iostream>
#include "Parent.h"
#include "Parent.cpp"
#include "Child.cpp"
#include "Child.h"


int main() {
//    Child *test_child_1 = new Child("test_child_name", "test_child_surname", 12, "test_school_1");
//    Parent *test_parent_1 = new Parent("test_parent_name", "test_parent_surname", 40, test_child_1);
    Child test_child_1 ("test_child_name", "test_child_surname", 12, "test_school_1");
    Parent test_parent_1 ("test_parent_name", "test_parent_surname", 40, &test_child_1);
    std::cout << test_child_1.get_school() << std::endl;
    test_parent_1.assignToOtherSchool("test_school_2");
    std::cout << test_child_1.get_school() << std::endl;
    return 0;
}