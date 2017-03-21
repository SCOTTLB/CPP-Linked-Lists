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
  Node* temp = new Node;
  // if a list exits
  if(head != nullptr){
    temp->data = value;
    temp->next = head;
    head = temp;
  }else{
    // otherwise create a list
    temp->data = value;
    head = temp;
    tail = temp;
  }
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

  // If only one node exits within the list
  if(current == nullptr){
    return "";
  }else{
    // loop through and print values
    while(current != nullptr) {
      if(current->next != nullptr){
        str.append(to_string(current->data) + " ");
        current = current->next;
      }else{
        str.append(to_string(current->data));
        return str;
      }
    }
    return str;
  }
}

//removes and returns the value at the head of the list
//requires: list not empty
int LinkedList::pop()
{
  // list not empty check
  assert(head != nullptr);
  Node* current = head;
  // Single element check
  if(head->next != nullptr){
    Node* temp = head->next;
    current = nullptr;
    head = temp;

  }else{
    // there is only one element in the list
    head = nullptr;
    tail = nullptr;
  }

}

//adds a value to the end of the list
void LinkedList::append(int value)
{
  Node* current = head;
  // if a list exists
  if(head != nullptr){
    while(current != tail){
      current = current->next;
    }
    Node* temp = new Node;
    temp->data = value;
    current->next = temp;
    tail = temp;
  }else{
    // no list exists
    head = new Node;
    head->data = value;
    tail = head;
  }

}

//appends the deep copies of the nodes of rhs on to the end of this list
void LinkedList::appendList(const LinkedList& rhs)
{

}

//inserts a value immediately after the first occurrence of afterValue,
//if afterValue is not in the list then inserts at the tail
void LinkedList::insertAfter(int value, int afterValue)
{

  Node* current = head;
  int insert_flag = 1;
  while(insert_flag){
    if(current->data == afterValue){
      Node* tmp = new Node;
      tmp->data = value;
      if(current->next == nullptr){
        tail = tmp;
      }
      tmp->next = current->next;
      current->next = tmp;
      insert_flag = 0;
    }else{
      if(current == tail){
        Node* tmp = new Node;
        tmp->data = value;
        tail->next = tmp;
        tail = tmp;
        insert_flag = 0;
      }else{
        current = current->next;
      }
    }
  }

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
