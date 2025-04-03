#include <iostream>
using namespace std;
#include "Selector.h"

Selector::Selector() : name("\0"), next(nullptr)
{

}
Selector::~Selector() 
{

}

void Selector::Add_Selector(String sel) {
    Selector* new_node = new Selector();
    new_node->name=sel;
    new_node->next = nullptr;
    this->next = new_node;
}

Selector& Selector::operator=(const Selector& right)
{
    name = right.name;
    next = right.next;
    return *this;
}

ostream& operator<<(ostream& os, const Selector& sel) {
    os << sel.name;
    return os;
}

bool Selector::operator==(const Selector& right) const
{
    if (name == right.name) return true;
    return false;
}
