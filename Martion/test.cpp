#include <iostream>
#include <unistd.h>
#include <vector>
#include "Martian.h"
#include "Martian.cpp"

int main() {
    std::vector<Martian *> all_martians;
    while (true) {
        all_martians.push_back(new Martian());
        for (int i = 0; i < all_martians.size(); i++) {
            sleep(1);
            std::string tmp = all_martians[i]->hide_or_attack();
            std::cout << tmp << std::endl;
            if (tmp == "lose") {
                delete all_martians[i];
                all_martians.erase(all_martians.begin() + i);
            }
        }
        std::cout << all_martians.size() << std::endl;
        sleep(1);
    }
    return 0;
}