#pragma once
#include <iostream>
using namespace std;
#include "Attribute.h"

template <class T>
class Vector {
public:
	T* elements;
	int size;
	int number_of_elements;

	Vector() {
		size = 0;
		elements = nullptr;
		number_of_elements = 0;
	}
	Vector(int size) {
		this->size = size;
		elements = new T[size];
		for (int i = 0; i < size; i++) {
			elements[i] = T();
		}
		number_of_elements = 0;
	}
	~Vector() {
		
	}
	T& operator[](int index) {
		if (index < 0 || index >= size) {
			cout<<"Index out of range";
			exit(99);
		}
		return elements[index];
	}
	void SetSize(int new_size) {
		if (new_size < 0) {
			cout << "Index out of range";
			exit (99);
		}

		T* tmp = new T[new_size];
		for (int i = 0; i < size; i++) {
			tmp[i] = elements[i];
		}

		delete[] elements;
		elements = tmp;
		size = new_size;
	}
	void Add_New_Element(T new_Element)
	{
		
		if (number_of_elements == size)
		{
	    int length = size + 1;
		SetSize(length);
	    }

		elements[number_of_elements] = new_Element;
		number_of_elements++;

	}


	Vector<T>& operator=(const Vector<T>& right)
	{
		delete[] elements; 
		size = right.size; 

		elements = new T[size]; 
		for (int i = 0; i < size; i++) {
			elements[i] = right.elements[i]; 
		}

		return *this; 
	}
	void Clear() {
		delete[] elements;
		elements = nullptr;
		size = 0;
		number_of_elements = 0;
	}

};




