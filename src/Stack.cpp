#include "Stack.hpp"

Stack::Stack(u_short l)
{
    limit = l;
    top = nullptr;
    current_size = 0;
}
bool Stack::push(int val)
{
    if (isFull())
    {
        std::cout << "Cannot push. Stack is full." << std::endl;
        return false;
    }

    Node *temp = new Node;
    temp->value = val;
    temp->below = top;
    top = temp;
    current_size++;

    return true;
}
int Stack::pop()
{
    if (isEmpty())
    {
        std::cout << "No items to poop." << std::endl;
        return -1;
    }

    int val = top->value;
    Node *temp = top->below;
    delete top;
    top = temp;
    current_size--;

    return val;
}
bool Stack::isEmpty()
{
    return !top;
}
bool Stack::isFull(){
    return (limit == current_size);
}
int Stack::peek()
{
    if (top)    return top->value;
    return -1;
}
int Stack::size()
{
    return current_size;
}
Node* Stack::giveTop()
{
    return top;
}