
#include "Martian.h"

int Martian::martianCount = 0;

Martian::Martian() {
    Martian::martianCount++;
}

Martian::~Martian() {
    Martian::martianCount--;
}

std::string Martian::attack() {
    srand(time(NULL));
    int tmp = rand() % 10 + 1;
    if (tmp > 5) {
        return "win";
    } else return "lose";
}

std::string Martian::hide_or_attack() {
    if (Martian::martianCount< 5) {
        return "hide";
    } else {
        return attack();
    }
}


