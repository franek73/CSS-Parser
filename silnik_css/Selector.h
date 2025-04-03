#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class Selector {
public:
    String name;
    Selector* next;

    Selector();
    ~Selector();
    
    Selector& operator=(const Selector& right);
    
    friend ostream& operator<<(ostream& os, const Selector& str);
    
    bool operator==(const Selector& right) const;
    
    void Add_Selector(String sel);
   
};



