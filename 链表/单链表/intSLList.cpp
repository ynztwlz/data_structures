#include<iostream>
#include "intSLList.h"

using namespace std;

IntSLLList::~IntSLLList(){
  for(IntSLLNode *p; !is_empty();){
    p = head -> next;
    delete head;
    head = p;
  }
}

void IntSLLList::add_to_head(int el){
  head = new IntSLLNode(el, head);
  if(tail == 0)
    tail = head;
}

void IntSLLList::add_to_tail(int el){
  if(tail != 0){
    tail -> next = new IntSLLNode(el);
    tail = tail -> next;
  }
  else
  {
    head = tail = new IntSLLNode(el);
  }
}

int IntSLLList::delete_from_head(){
  int el = head->info;
  IntSLLNode *tmp = head;
  if(head == tail)
    head = tail = 0;
  else
    head = head -> next;
  delete tmp;
  return el;
}

int IntSLLList::delete_from_tail(){
  int el = tail -> info;
  if(head == tail){
    delete head;
    head = tail = 0;
  }
  else{
    IntSLLNode *tmp;
    for(tmp=head; tmp->next!=tail;tmp=tmp->next);
    delete tail;
    tail = tmp;
    tail -> next = 0;
  }
  return el;
}

void IntSLLList::delete_node(int){
  if(head != 0)
    if(head == tail && el == head -< info){
      delete head;
      head = tail = 0;
    }
    else if(el == head -> info){
      IntSLLNode *tmp = head;
      head = head -> next;
      delete tmp;
    }
    else{
      IntSLLNode *pred, *tmp;
      for(pred = head, tmp=head->next;tmp!=0 &&!(tmp->info==el); pred=pred->next,tmp=tmp->next);
      if(tmp!=0){
        pred->next = tmp->next;
        if(tmp == tail)
          tail = pred;
        delete tmp;
      }
    }
}

bool IntSLLList::is_in_list(int) const{
  IntLLNode *tmp;
  for(tmp=head;tmp!=0&&!(tmp->info==el);tmp=tmp->next);
  return tmp!=0;
}
