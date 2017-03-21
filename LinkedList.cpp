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
    assert(head !=  nullptr);

    int value;
    Node* current = head;
    while(current != tail){
      current = current->next;
    }
    value = current->data;
    return value;
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
  int value = head->data;
  Node* temp = head;
  head = head->next;
  delete temp;
  return value;

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
  Node* end = head;
  // jump to the end of the list
  while(end != tail){

    end = end->next;
  }
  Node* current = rhs.head;
  // check to see if appending empty list
  if(current == nullptr){
    end->next = nullptr;
  }else{
    // list contains values
    while(current){
      // make a new node to copy into at the end of the list
      end->next = new Node;
      // change the end of the lit to the new node
      end = end->next;
      // set the tail
      tail = end;
      // copy the data
      end->data = current->data;
      // increment the rhs list
      current = current->next;
    }
  }
}

//inserts a value immediately after the first occurrence of afterValue,
//if afterValue is not in the list then inserts at the tail
void LinkedList::insertAfter(int value, int afterValue)
{
  Node* current = head;
  // so we know when to insert
  int insert_flag = 1;
  // while the flag is raised
  while(insert_flag){

    if(current->data == afterValue){
      // make a new node
      Node* tmp = new Node;
      // copy in the value
      tmp->data = value;
      // set the tail if its at the end
      if(current->next == nullptr){
        tail = tmp;
      }
      // point to the new node
      tmp->next = current->next;
      current->next = tmp;
      // lower the flag
      insert_flag = 0;
    }else{
      // if the value isnt in the list
      if(current == tail){
        // stick a new node at the end of the list
        Node* tmp = new Node;
        tmp->data = value;
        tail->next = tmp;
        tail = tmp;
        insert_flag = 0;
      }else{
        // otherwise increment the list
        current = current->next;
      }
    }
  }

}

//removes all occurrences of value from the list
void LinkedList::removeAllOccurences(int value)
{
  Node* current = head;
  // Case for if theres only one item in the list and
  while(current && current->data == value){
    Node* previous = current;
    current = current->next;
    head = current;

    delete previous;
  }
  // If the value isnt in the head node
  while (current) {
    Node* previous;
    if(current->data == value){
      previous->next = current->next;
      delete current;
      current = previous->next;
    }else{
      // Scootch up the list
      previous = current;
      current = current->next;
    }
  }
}

//reverses the list
void LinkedList::reverse()
{
  // track the new head
  Node* cursor = nullptr;
  Node* next;
  // while theres still a head in the old list
  while(head){
    next = head->next;
    head->next = cursor;
    cursor = head;
    head = next;
  }
  // make the list head the tracked one
  head = cursor;
  Node* current = head;
  // set the new tail
  while(current->next != nullptr){
    current = current->next;
  }
  tail = current;
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
