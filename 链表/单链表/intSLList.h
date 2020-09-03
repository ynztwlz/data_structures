#ifndef INT_LINKED_LIST
#DEFINE INT_LINKED_LIST

class IntSLLNode{
  public:
    IntSLLNode(){
      next = 0;
    }
    IntSLLNode(int el, IntSLLNode *ptr = 0){
      info = el;
      next = ptr;
    }
    int info;
    IntSLLNode *next;
};

class IntSLLList{
  public:
    IntSLLList(){
      head = tail = 0;
    }
    ~IntSLList();
    int is_empty(){
      return head == 0;
    }

    void add_to_head(int);
    void add_to_tail(int);
    int delete_from_head();
    int delete_from_tail();
    void delete_node(int);
    bool is_in_list(int) const;

  private:
    IntSLLList *head, *tail;
};

#endif
