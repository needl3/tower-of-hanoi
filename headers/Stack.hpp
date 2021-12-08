#pragma once
#include <iostream>

struct Node
{
    int value;
    Node *below;
};

class Stack
{
    private:
        Node* top;
        unsigned int limit;
        unsigned int current_size;
    public:
        Stack(u_short);
        bool push(int);
        int pop();
        int peek();
        bool isFull();
        bool isEmpty();
        int size();
        Node* giveTop();
};
