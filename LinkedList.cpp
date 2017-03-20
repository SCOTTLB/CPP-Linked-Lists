/*
 * File:   LinkedList.cpp
 * Author: Simon Powers
 *
 * Last modified 03/03/2017
 * Implements the LinkedList class.
 */

#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include "linked_list.h"
using namespace std;

//creates an empty list
LinkedList::LinkedList()
{

}

//creates a list with an initial value to store
LinkedList::LinkedList(int value)
{
  head = new Node;
  head->data = value;
  tail = head;
}

//copy constructor (performs a deep copy)
LinkedList::LinkedList(const LinkedList& rhs)
{


}


//destroys (cleans up) the list
LinkedList::~LinkedList()
{

}

//adds a value to the head of the list
void LinkedList::push(int value)
{


}

//gets the last element from the list, without removing it
//requires: list not empty
int LinkedList::peekTail()
{
    return -1;
}

//prints the list in order from head to tail
string LinkedList::toString() const
{
  Node* current = head;
  string str;
  if (current == nullptr){
    return "";
  }else{
    while (current != tail) {
      str.append(to_string(current->data) + " ");
      current = current->next;
    }
    return str;
  }
}

//removes and returns the value at the head of the list
//requires: list not empty
int LinkedList::pop()
{
    return -1;
}

//adds a value to the end of the list
void LinkedList::append(int value)
{


}

//appends the deep copies of the nodes of rhs on to the end of this list
void LinkedList::appendList(const LinkedList& rhs)
{

}

//inserts a value immediately after the first occurrence of afterValue,
//if afterValue is not in the list then inserts at the tail
void LinkedList::insertAfter(int value, int afterValue)
{


}

//removes all occurrences of value from the list
void LinkedList::removeAllOccurences(int value)
{

}

//reverses the list
void LinkedList::reverse()
{

}

//checks if two lists are equal in state (contain the same values in the same order)
bool LinkedList::operator ==(const LinkedList& other) const
{
  	return false;

}

//checks if two lists are not equal in state
bool LinkedList::operator !=(const LinkedList& other) const
{
    return false;
}

//pushes a new value onto the head of the list
LinkedList& LinkedList::operator +(int value)
{

    return *this;
}

//copy assignment operator (performs a deep copy)
LinkedList& LinkedList::operator =(const LinkedList& rhs)
{

    return *this;
}

//pushes values from an input stream onto the front of the list
std::istream& operator>>(std::istream &in, LinkedList &value)
{

    return in;
}

//writes the values, in order, to an output stream
std::ostream& operator<<(std::ostream &out, const LinkedList &value)
{

    return out;
}
