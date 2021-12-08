#pragma once
#include "Stack.hpp"

class Hanoi
{
    private:
        Stack* *m_stacks;
        u_short n_stacks, n_disks;
    public:
        Hanoi(u_short, u_short);
        ~Hanoi();
        bool move(u_short, u_short);
        void displayConsole();
        bool run();
};