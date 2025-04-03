#pragma once
#include "String.h"
#include "Vector.h"
#include "Selector.h"
#include "Attribute.h"

#define T 8

class Section {
public:
    Attribute* first_attribute;
    Selector* first_selector;
    int number_of_attributes = 0;
    int number_of_selectors = 0;
    
    Section();
    ~Section();
};

class Node {
public:
    Section section_array[T];
    Node* next;
    Node* previous;
    int size = T;
    int number_of_sections;
    int number_of_empty_sections;
   
    Node();
    ~Node();
};

class SectionList {
public:
    Node* first_node;
   
    void Add_New_Selector(String sel) const;
   
    void Add_New_Attribute(Attribute atr) const;
    
    void Copy_Selectors(Vector<String> sel) const;
   
    void Number_Of_Sections() const;
    
    void Print_List() const;
    
    void Name_Of_Selector_By_Indexes(int index_first, int index_last, String command) const;
   
    void Number_Of_Selectors_By_Index(int index, String command) const;
    
    void Number_Of_Attributes_By_Index(int index, String command) const;
    
    void Value_Of_Attribute_By_Index(int index, String command, String attribute_name) const;
    
    void Add_New_Section();
    
    void Number_Of_Selectors_By_Name(String command, String name) const;
    
    void Number_Of_Attributes_By_Name(String command, String name) const;
    
    void Value_Of_Attribute_By_Selector(String selector, String attribute, String command) const;
    
    void Delete_Section(String command, int index);
    
    void Delete_Attributte_By_Section(String command, String attribute, int index);
    
    Node* Delete_Node(Node* node_to_delete);
    
    SectionList();
    ~SectionList();
};