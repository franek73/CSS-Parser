#include <iostream>
using namespace std;
#include "SectionList.h"

Section::Section() 
{
    first_selector = nullptr;
    first_attribute = nullptr;
}
Section::~Section() 
{
    Selector* current_selector = first_selector;
    while (current_selector != nullptr) {
        Selector* selector_to_delete = current_selector;
        current_selector = current_selector->next;
        delete selector_to_delete;
    }

    Attribute* current_attribute = first_attribute;
    while (current_attribute != nullptr) {
        Attribute* attribute_to_delete = current_attribute;
        current_attribute = current_attribute->next;
        delete attribute_to_delete;
    }
}

Node::Node() {
    next = nullptr;
    previous = nullptr;
    number_of_sections = 1;
    number_of_empty_sections = 0;
}
Node::~Node() {
}

SectionList::~SectionList() 
{
    Node* current_node = first_node;
    while (current_node != nullptr) {
        Node* node_to_delete = current_node;
        current_node = current_node->next;
        delete node_to_delete;
    }
}
SectionList::SectionList()
{
    first_node = nullptr;
}

void SectionList::Add_New_Section()
{
    if (first_node == nullptr)
    {
        Node* new_Node = new Node;
        new_Node->previous = nullptr;
        first_node = new_Node;

    }
    else
    {
        Node* last_node = first_node;
        while (last_node->next != nullptr)
        {
            last_node = last_node->next;
        }
        if (last_node->number_of_sections == last_node->size)
        {
            Node* new_Node = new Node;
            new_Node->previous = last_node;
            last_node->next = new_Node;
            new_Node->next = nullptr;
        }
        else
        {
            last_node->number_of_sections++;
            last_node->number_of_sections;
        }

    }

}

void SectionList::Add_New_Selector(String sel) const
{
    Node* temp = first_node;

    while (temp->next)
    {
        temp = temp->next;
    }
    int index = temp->number_of_sections - 1;

    if (temp->section_array[index].first_selector == nullptr)
    {
        temp->section_array[index].first_selector = new Selector();
        temp->section_array[index].first_selector->name=sel;
        temp->section_array[index].first_selector->next = nullptr;
        temp->section_array[index].number_of_selectors++;

    }

    else
    {
        Selector* last_selector = temp->section_array[index].first_selector;
        while (last_selector->next)
        {
            last_selector = last_selector->next;
        }
        last_selector->Add_Selector(sel);
        temp->section_array[index].number_of_selectors++;

    }
}

void SectionList::Copy_Selectors(Vector<String> sel) const
{
    Node* temp = first_node;

    while (temp->next)
    {
        temp = temp->next;
    }

    for (int i = 0; i < sel.size; i++)
    {

        Add_New_Selector(sel[i]);
    }
}

void SectionList::Add_New_Attribute(Attribute atr) const
{
    Node* temp = first_node;

    while (temp->next)
    {
        temp = temp->next;
    }
    int index = temp->number_of_sections - 1;

    if (temp->section_array[index].first_attribute == nullptr)
    {
        temp->section_array[index].first_attribute = new Attribute();
        temp->section_array[index].first_attribute->name=atr.name;
        temp->section_array[index].first_attribute->value=atr.value;
        temp->section_array[index].first_attribute->next = nullptr;
        temp->section_array[index].number_of_attributes++;

    }

    else
    {
        Attribute* last_attribute = temp->section_array[index].first_attribute;
        Attribute* first_attribute_before = temp->section_array[index].first_attribute;
        temp->section_array[index].first_attribute = temp->section_array[index].first_attribute->Delete_Attribute(first_attribute_before, atr.name);
        Attribute* first_attribute_now = temp->section_array[index].first_attribute;
        if (first_attribute_now == nullptr)
        {
            temp->section_array[index].first_attribute = new Attribute();
            temp->section_array[index].first_attribute->name=atr.name;
            temp->section_array[index].first_attribute->value=atr.value;
            temp->section_array[index].first_attribute->next = nullptr;
            temp->section_array[index].number_of_attributes++;
        }
        else {
        int y = 0;
        while (first_attribute_now)
        {

            y++;
            first_attribute_now = first_attribute_now->next;
        }
        temp->section_array[index].number_of_attributes = y;
      
            while (last_attribute->next)
            {
                last_attribute = last_attribute->next;
            }
            last_attribute->Add_Attribute(atr);
            temp->section_array[index].number_of_attributes++;
        }

    }
}

void SectionList::Print_List() const
{
    Node* temp = first_node;

    int i = 0;
    int y = 1;

    Attribute* last_attribute = temp->section_array[i].first_attribute;
    Selector* last_selector = temp->section_array[i].first_selector;

    while (temp)
    {

        while (i < temp->number_of_sections)
        {
            if (temp->section_array[i].first_attribute != nullptr)
            {
                last_attribute = temp->section_array[i].first_attribute;
                last_selector = temp->section_array[i].first_selector;
                cout << "Sekcja nr: " << y << ": " << endl;
                cout << "Selektory: " << endl;
                while (last_selector)
                {
                    cout<<last_selector->name<<endl;

                    last_selector = last_selector->next;

                }
                cout << endl;
                cout << "Atrybuty: " << endl;

                while (last_attribute)
                {
                    cout<<last_attribute->name<<": ";
                    cout<<last_attribute->value<<endl;
                    last_attribute = last_attribute->next;

                }
                cout << endl;

                y++;

            }
            i++;
        }
        temp = temp->next;
        i = 0;
        if (temp != nullptr)
        {
            last_selector = temp->section_array[i].first_selector;
            last_attribute = temp->section_array[i].first_attribute;
        }

    }

}

void SectionList::Number_Of_Sections() const
{
    Node* temp = first_node;

    int i = 0;

    while (temp)
    {
        int y = 0;
        while (y < temp->number_of_sections)
        {
            Attribute* last_attribute = temp->section_array[y].first_attribute;
            if (last_attribute != nullptr) {
                i++;
            }
            y++;

        }

        temp = temp->next;

    }
    cout << "? == " << i;

}

void SectionList::Number_Of_Selectors_By_Index(int index, String command) const
{
    Node* temp = first_node;

    int i = 1;

    while (temp)
    {
        int y = 0;
        while (y < temp->number_of_sections)
        {

            if (temp->section_array[y].first_attribute != nullptr)
            {
                if (i == index)
                {
                    cout << command << " == " << temp->section_array[y].number_of_selectors<<endl;
                    return;
                }
                i++;
            }

            y++;

        }
        temp = temp->next;
    }
   
}

void SectionList::Number_Of_Selectors_By_Name(String command, String name) const
{
    Node* temp = first_node;

    int i=0;

    while (temp)
    {
        int y = 0;
        while (y < temp->number_of_sections)
        {

            Selector* last_selector = temp->section_array[y].first_selector;
            for (int z = 0; z < temp->section_array[y].number_of_selectors; z++) {

                if (last_selector != nullptr)
                {
                    if (last_selector->name == name)
                    {
                        i++;
                        last_selector = last_selector->next;
                        break;
                    }
                    last_selector = last_selector->next;
                }

            }

            y++;

        }
        temp = temp->next;
    }
    cout << command << " == " << i << endl;
}

void SectionList::Number_Of_Attributes_By_Name(String command, String name) const
{
    Node* temp = first_node;

    int i=0;

    while (temp)
    {
        int y = 0;
        while (y < temp->number_of_sections)
        {

            Attribute* last_attribute = temp->section_array[y].first_attribute;
            for (int z = 0; z < temp->section_array[y].number_of_attributes; z++) {
                if (last_attribute != nullptr)
                {
                    if (last_attribute->name == name)
                    {
                        i++;
                    }
                    last_attribute = last_attribute->next;
                }
            }

            y++;

        }
        temp = temp->next;
    }
    cout << command << " == " << i << endl;
}

void SectionList::Name_Of_Selector_By_Indexes(int index_first, int index_last, String command) const
{
    Node* temp = first_node;
    int i=1;

    while (temp)
    {
        int y = 0;
        while (y < temp->number_of_sections)
        {
            Attribute* last_attribute = temp->section_array[y].first_attribute;
            if (last_attribute != nullptr)
            {
                if (i == index_first)
                {
                    Selector* last_selector = temp->section_array[y].first_selector;
                    for (int z = 0; z < temp->section_array[y].number_of_selectors; z++)
                    {
                        if ((z + 1) == index_last)
                        {

                            cout << command << " == " << last_selector->name<<endl;
                            return;
                        }
                        last_selector = last_selector->next;
                    }
                }
                i++;

            }
            y++;

        }
        temp = temp->next;

    }
}

void SectionList::Number_Of_Attributes_By_Index(int index, String command) const
{
    Node* temp = first_node;

    int i = 1;

    while (temp)
    {
        int y = 0;
        while (y < temp->number_of_sections)
        {
            Attribute* last_attribute = temp->section_array[y].first_attribute;
            if (last_attribute != nullptr)
            {
                if (i == index)
                {
                    cout << command << " == " << temp->section_array[y].number_of_attributes<<endl;
                    return;
                }

                i++;
            }
            y++;
        }
        temp = temp->next;
    }
}

void SectionList::Value_Of_Attribute_By_Index(int index, String command, String attribute_name) const
{
    Node* temp = first_node;

    int i = 1;

    while (temp)
    {
        int y = 0;
        while (y < temp->number_of_sections)
        {
            Attribute* last_attribute = temp->section_array[y].first_attribute;
            if (last_attribute != nullptr)
            {
                if (i == index)
                {
                    for (int z = 0; z < temp->section_array[y].number_of_attributes; z++) {
                        if (last_attribute != nullptr)
                        {
                            if (last_attribute->name == attribute_name)
                            {

                                cout << command << " == "<< last_attribute->value<<endl;
                                return;
                            }
                            last_attribute = last_attribute->next;
                        }
                    }

                }
                i++;
            }
            y++;

        }
        temp = temp->next;
    }
}

void SectionList::Value_Of_Attribute_By_Selector(String selector, String attribute, String command) const
{
    Node* temp = first_node;

    while (temp->next)
    {
        temp = temp->next;
    }

    while (temp)
    {
        int y = temp->number_of_sections;
        while (y > 0)
        {
            Selector* last_selector = temp->section_array[y-1].first_selector;
            if (last_selector != nullptr) {
                for (int z = 0; z < temp->section_array[y-1].number_of_selectors; z++) {
                    if (last_selector->name == selector)
                    {

                        Attribute* last_attribute = temp->section_array[y-1].first_attribute;
                        if (last_attribute != nullptr)
                        {


                            for (int k = 0; k < temp->section_array[y-1].number_of_attributes; k++) {
                                if (last_attribute->name == attribute)
                                {

                                    cout << command << " == "<<last_attribute->value<<endl;
                                    return;
                                }
                                last_attribute = last_attribute->next;
                            }
                        }
                    }
                    last_selector = last_selector->next;
                }
            }
            y--;

        }
        temp = temp->previous;
    }
}

void SectionList::Delete_Section(String command, int index)
{
    Node* temp = first_node;
    int i=1;

    while (temp)
    {
        int y = 0;
        while (y < temp->number_of_sections)
        {
            Attribute* first_attribute = temp->section_array[y].first_attribute;
            if (first_attribute != nullptr) {
                if (i == index)
                {

                    Attribute* last_attribute = temp->section_array[y].first_attribute;
                   
                    while (last_attribute != nullptr) {
                        Attribute* current = last_attribute;
                        last_attribute = last_attribute->next;
                        delete current;
                    }
                    temp->section_array[y].first_attribute = nullptr;

                    
                    Selector* last_selector = temp->section_array[y].first_selector;
                   
                    while (last_selector != nullptr) {
                        Selector* current = last_selector;
                        last_selector = last_selector->next;
                        delete current;
                    }
                
                    temp->section_array[y].first_selector = nullptr;
                 
                    temp->number_of_empty_sections++;
                    cout << command << " == deleted";
                    cout << endl;
                    if (temp->number_of_empty_sections == temp->number_of_sections)
                    {
                      
                            first_node = Delete_Node(temp);
                    }
                    return;

                }
                i++;
            }
            y++;

        }
        temp = temp->next;

    }
}

void SectionList::Delete_Attributte_By_Section(String command, String attribute, int index)
{
    Node* temp = first_node;
    int i=1;
  
    while (temp)
    {
        int y = 0;
        while (y < temp->number_of_sections)
        {
            Attribute* first_attribute = temp->section_array[y].first_attribute;
            if (temp->section_array[y].first_attribute != nullptr)
            {
                if (i == index)
                {
                    Attribute* curr_node = first_attribute;
                    Attribute* prev_node = nullptr;
                    while (curr_node != nullptr)
                    {
                        if (curr_node->name == attribute)
                        {
                            if (prev_node == nullptr)
                            {
                                if (curr_node->next != nullptr)
                                {
                                    curr_node = curr_node->next;
                                }

                                else
                                {
                                    curr_node->name = "\0";
                                    curr_node->value = "\0";
                                    curr_node->next = nullptr;
                                    curr_node = nullptr;
                                }
                                temp->section_array[y].first_attribute = curr_node;
                                temp->section_array[y].number_of_attributes--;
                                cout << command << " == deleted";
                                cout << endl;
                                break;
                            }
                            else {

                                prev_node->next = curr_node->next;

                                temp->section_array[y].first_attribute = first_attribute;
                                temp->section_array[y].number_of_attributes--;
                                cout << command << " == deleted";
                                cout << endl;
                                break;
                            }
                        }
                        prev_node = curr_node;
                        curr_node = curr_node->next;
                    }
                    if (temp->section_array[y].first_attribute == nullptr)
                    {
                        temp->section_array[y].first_selector = nullptr;
                        temp->number_of_empty_sections++;
                        if (temp->number_of_empty_sections == temp->number_of_sections)
                            first_node = Delete_Node(temp);
                    }

                }
                if (first_attribute != nullptr) {
                    i++;
                }
            }
            y++;

        }
        temp = temp->next;

    }
}

Node* SectionList::Delete_Node(Node* node_to_delete)
{
    if (node_to_delete == nullptr) {
        return first_node;
    }

    if (node_to_delete->previous != nullptr) {
        node_to_delete->previous->next = node_to_delete->next;
    }
    else {
        first_node = node_to_delete->next;
    }
    if (node_to_delete->next != nullptr) {
        node_to_delete->next->previous = node_to_delete->previous;
    }

    delete node_to_delete;

    return first_node;
}