#ifndef LIST_H
#define LIST_H
#include "./FNode.hpp"
#include <functional>

//template<typename T>
//void swap(T &a, T &b)
//{
//  T temp = a;
//  a = b;
//  b = temp;
//}

template<typename T>
class List {
private:
  Node<T> *head;
  unsigned int size;
  Node<T>* atn(unsigned int position)
  {
    if(!head){throw;}
    Node<T> *temp = head;
    for(int i = 0; i < position; i++)
    {
      if(!(temp->next)){throw;}
      temp = temp->next;
    }
    return temp;
  }
public:
  List():head(nullptr), size(0){}
  ~List(){delete head; size = 0;}
  unsigned int length(){return size;}
  unsigned int length()const{return size;}
  T& at(unsigned int position)
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
  void add(T value)
  {
    size++;
    if(head)
    {
      Node<T> *temp2 = new Node<T>;
      temp2->value = value;
      temp2->next = head;
      head = temp2;
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
        temp2->next = nullptr;
        delete temp2;
        return;
      }
      temp = temp->next;
    }
  }
  T pop_front()
  {
    if(head)
    {
      size--;
      T result = head->value;
      Node<T> *temp = head;
      head = temp->next;
      temp->next = nullptr;
      delete temp;
      temp = nullptr;

      return result;
    }return nullptr;    
  }
  void for_each(std::function<void(T)> exec)
  {
    if(!head){return;}
    Node<T> *temp = head;
    while(temp)
    {
      exec(temp->value);
      temp = temp->next;
    }
  }
  void sort()
  {
    for (int step = size/2; step > 0; step /= 2) 
    { 
      for (int i = step; i < size; i += 1) 
      { 
        T temp = at(i); 
        int j;             
        for (j = i; j >= step && at(j - step) > temp; j -= step) 
            atn(j)->value = at(j - step); 
        atn(j)->value = temp; 
      } 
    }
  }
  int bsearch(int l, int r, T value)
  {
    if (r >= l) { 
      int mid = l + (r - l) / 2; 
      if (at(mid) == value) 
          return mid; 
  
      if (at(mid) > value) 
          return bsearch(l, mid - 1, value); 
  
      return bsearch(mid + 1, r, value); 
    } 
    return -1;
  }
  int index(T element)
  {
    sort();
    return bsearch(0, size-1, element);
  }
  void clear()
  {
    while(size)
    {
      pop();
    }
  }
};

#endif
