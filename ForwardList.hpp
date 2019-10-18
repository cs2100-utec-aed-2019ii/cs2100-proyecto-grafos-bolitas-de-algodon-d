#ifndef LIST_H
#define LIST_H
#include "./FNode.hpp"

template<typename T>
class List {
private:
  Node<T> *head;
  unsigned int size;
public:
  List():head(nullptr), size(0){}
  ~List(){delete head; size = 0;}
  unsigned int length(){return size;}
  T at(unsigned int position)
  {
    if(!head){throw;}
    Node<T> *temp = head;
    for(int i = 0; i < position; i++)
    {
      if(!(temp->next)){throw;}
      temp = temp->next;
    }
    return temp->value;
  }
  void push(T value)
  {
    size++;
    if(head)
    {
      Node<T> *temp = head;
      while(temp->next)
      {
        temp = temp->next;
      }
      temp->next = new Node<T>;
      temp->next->value = value;
      return;
    }
    head = new Node<T>;
    head->value = value;
  }
  void pop()
  {
    if(!head){return;}
    size--;
    if(!(head->next))
    {
      delete head;
      head = nullptr;
      return;
    }
    Node<T> *temp = head;
    while(temp->next->next)
    {
      temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
  }
  void pop(T value)
  {
    if(!head){return;}
    size--;
    if(!(head->next))
    {
      if(head->value == value)
      {
        delete head;
        head = nullptr;
      }
      return;
    }
    Node<T> *temp = head;
    Node<T> *temp2;
    while(temp->next)
    {
      if(temp->next->value == value)
      {
        temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
        return;
      }
      temp = temp->next;
    }
  }
  void for_each(void (*exec)(T))
  {
    if(!head){return;}
    Node<T> *temp = head;
    while(temp)
    {
      exec(temp->value);
      temp = temp->next;
    }
  }
  Node<T> * get_head(){
    return head;
  }
  
};

#endif
