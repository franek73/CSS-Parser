#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class Attribute {
public:
    String name;
    String value;
    Attribute* next;

    Attribute();
    ~Attribute();

    Attribute& operator=(const Attribute& right);
    
    friend ostream& operator<<(ostream& os, const Attribute& str);
    
    bool operator==(const Attribute& right) const;
    
    void Add_Attribute(Attribute atr);
    
   Attribute* Delete_Attribute(Attribute* first_attribute, String attribute_name);
};