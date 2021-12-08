#include "Hanoi.hpp"

Hanoi::Hanoi(u_short disks, u_short stacks)
{
    n_stacks = stacks;
    n_disks = disks;
    m_stacks = new Stack*[n_stacks];
    for(int i=0;i<n_stacks;i++)    m_stacks[i] = new Stack(n_disks);
    for(int i=n_disks-1;i>=0;i--)  m_stacks[0]->push(i);
}
Hanoi::~Hanoi()
{
    for(int i=0;i<n_stacks;i++)    delete m_stacks[i];
}
bool Hanoi::move(u_short source, u_short destination)
{
    if(m_stacks[source]->isEmpty())
    {
        std::cout << "You can't move nothing, BAKA." << std::endl;
        return false;
    }
    if(m_stacks[destination]->isFull())
    {
        std::cout << "Stack is already full to push." << std::endl;
        return false;
    }
    if(m_stacks[source]->peek() > m_stacks[destination]->peek() && !m_stacks[destination]->isEmpty())
    {
        std::cout << "Cannot move bigger disk on top of smaller one. Read the rules, lazy piece of sheep." << std::endl;
        return false;
    }
    return m_stacks[destination]->push(m_stacks[source]->pop());
}
bool Hanoi::run()
{
    u_short source, destination;
    while(true)
    {
        displayConsole();
        do
        {
            std::cout << std::endl << "Enter source: ";
            std::cin >> source;
        }while(source < 0 && source >= n_stacks);
        do
        {
            std::cout << std::endl << "Enter destination: ";
            std::cin >> destination;
        }while(destination < 0 && destination >= n_stacks);
        std::cout << "\033[2J\033[1;1H" << std::endl;
        if (move(source, destination)) break;
        else    std::cout << std::endl << "Cannot move from " << source << " to " << destination << std::endl;
    }
    if(m_stacks[n_stacks-1]->size() == n_disks)
    {
        displayConsole();
        std::cout << "Game Competed....Wew amazeng intiligont man...Omedetou" << std::endl;
        return false ;
    }
    return true;
}
void Hanoi::displayConsole()
{
    for(int i=0; i<n_stacks; i++)
    {
        std::cout << "|---|" << std::endl;
        std::cout << "| "<<i<<" |\t[ ";
        Node *temp_node = m_stacks[i]->giveTop();
        while(temp_node)
        {
            std::cout << temp_node->value;
            temp_node = temp_node->below;
            std::cout << " ";
        }
        std::cout << "]" << std::endl << "|---|" << std::endl << std::endl;
    }
}