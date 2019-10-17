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
};

#endif
