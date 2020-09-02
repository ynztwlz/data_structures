#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST
#include<iostream>

using namespace std;

template <typename T>
class Single_Linked_List_Node{
  public:
    Single_Linked_List_Node(){
      next = 0;
    }
    Single_Linked_List_Node(T el, Single_Linked_List_Node *ptr=0){
      data = el;
      next = ptr;
    }
    T data;
    Single_Linked_List_Node *next;
};


template <typename T>
class Single_Linked_List{
  public:

    Single_Linked_List(){
      head = tail = 0;
    }

    ~Single_Linked_List(){
      Single_Linked_List_Node<T> *tmp;
      for(Single_Linked_List_Node<T> *tmp; !is_empty();){
        tmp = head->next;
        delete head;
        head = tmp;
      }
    }

    bool is_empty(){
      return head == 0;
    }

    void add_to_head(T el){
      head = new Single_Linked_List_Node<T>(el, head);
      if(tail == 0)
        tail = head;
    }

    void add_to_tail(T el){
      if(tail != 0){
        tail->next = new Single_Linked_List_Node<T>(el);
        tail = tail->next;
      }
      else
        head = tail = new Single_Linked_List_Node<T>(el);
    }

    T delete_from_head(){
      T el = head->data;
      Single_Linked_List_Node<T> *tmp = head;
      if(head == tail)
        head = tail = 0;
      else
        head = head->next;
      delete tmp;
      return el;
    }

    T delete_from_tail(){
      T el = tail->data;
      if(head == tail)
        head = tail = 0;
      else{
        Single_Linked_List_Node<T> *tmp;
        for(tmp=head;tmp->next!=tail;tmp=tmp->next);
        delete tail;
        tail = tmp;
        tail->next = 0;
      }
      return el;
    }

    void delete_node(T el){
      if(head!=0){
        if(head == tail && tail->data == el){
          delete head;
          head = tail = 0;
        }
        else if(el == head->data){
          Single_Linked_List_Node<T> *tmp;
          tmp = head;
          head = head->next;
          delete tmp;
        }
        else{
          Single_Linked_List_Node<T> *pred, *tmp;
          for(pred=head,tmp=head->next;tmp!=0 && !(tmp->data==el);pred=pred->next,tmp=tmp->next);
          if(tmp != 0){
            pred->next = tmp->next;
            if(tmp==tail){
              tail = pred;
            }
            delete tmp;
          }
        }
      }
    }

    void print_list() const {
      if(head!=0){
        Single_Linked_List_Node<T> *tmp = head;
        while(tmp->next!=0){
          std::cout<<tmp->data<<"-";
          tmp = tmp->next;
        }
        std::cout<<tmp->data<<std::endl;
      }
    }

  private:
    Single_Linked_List_Node<T> *head, *tail;
};

#endif SINGLE_LINKED_LIST
