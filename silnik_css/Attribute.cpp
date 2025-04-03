#include <iostream>
using namespace std;
#include "Attribute.h"

Attribute::Attribute() : name("\0"), value("\0"), next(nullptr)
{

}
Attribute::~Attribute() 
{
  
}

void Attribute::Add_Attribute(Attribute atr) 
{
	Attribute* new_node = new Attribute();
	new_node->name=atr.name;
	new_node->value=atr.value;
	new_node->next = nullptr;
	this->next = new_node;
}

Attribute* Attribute::Delete_Attribute(Attribute* first_attribute, String attribute_name)
{
	Attribute* curr_node = first_attribute;
	Attribute* prev_node = nullptr;
	while (curr_node != nullptr)
	{
		if (curr_node->name == attribute_name)
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
				return curr_node;
			}
			else {

				prev_node->next = curr_node->next;

				return first_attribute;
			}
		}
		prev_node = curr_node;
		curr_node = curr_node->next;
	}
	return first_attribute;
}

Attribute& Attribute::operator=(const Attribute& right)
{
	name = right.name;
	value = right.value;
	next = right.next;
	return *this;
}

ostream& operator<<(ostream& os, const Attribute& atr) 
{
	os << atr.value;
	return os;
}

bool Attribute::operator==(const Attribute& right) const
{
	if (name == right.name) return true;
	return false;
}