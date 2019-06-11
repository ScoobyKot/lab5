

#ifndef JMP2_MARTIAN_H
#define JMP2_MARTIAN_H


class Martian {
private:
    static int martianCount;

    static std::string attack();

public:
    Martian();

    ~Martian();

    std::string hide_or_attack();
};


#endif //JMP2_MARTIAN_H
