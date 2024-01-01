
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	template <class V>
  	friend ostream& operator<<(ostream&, Array<V>&);

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(T);
		T& operator[](int);
		int getSize();
		bool isFull();
	
	private:
		int size;
		T* elements;
	
};

template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

template <class T>
Array<T>::~Array(){
	delete [] elements;
}

template <class T>
void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

template <class T>
int Array<T>::getSize(){
	return size;
}

template <class T>
bool Array<T>::isFull(){
	return size >= MAX_ARR;
}

template <class T>
T& Array<T>::operator[](int index){
	if (index < 0 || index >= size) {
		cout << "ERROR:  invalid index" << endl;
		exit(1);
  	}

  	return elements[index];
}

template <class T>
ostream& operator<<(ostream& output, Array<T> arr)
{
  output << endl;

  for (int i=0; i<arr.size; ++i)
    output << arr.elements[i];

  output << endl;
  return output;
}

#endif