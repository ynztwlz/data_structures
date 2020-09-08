#ifndef SKIP_LIST
#define SKIP_LIST
#include<stdlib.h>
const int max_level = 4;

template <class T> class SkipListNode {
public:
  SkipListNode() {}
  T key;
  SkipListNode **next;
};

template <typename T> class SkipList {
public:
  SkipList();
  bool is_empty() const;
  void choose_powers();
  int choose_level();
  T *skiplist_search(const T &);
  void skiplist_insert(const T &);

private:
  typedef SkipListNode<T> *node_ptr;
  node_ptr root[max_level];
  int powers[max_level];
};

template <class T> SkipList<T>::SkipList() {
  for (int i = 0; i < max_level; i++)
    root[i] = 0;
}

template <typename T> bool SkipList<T>::is_empty() const {
  return root[0] == 0;
}

template <typename T> void SkipList<T>::choose_powers() {
  powers[max_level - 1] = (2 << (max_level - 1)) - 1; // 2^max_level-1;
  for (int i = max_level - 2, j = 0; i >= 0; j++, i--)
    powers[i] = powers[i + 1] - (2 << j);
}

template <typename T> int SkipList<T>::choose_level() {
  int i, r = rand() % powers[max_level - 1] + 1;
  for (i = 1; i < max_level; i++)
    if (r < powers[i])
      return i - 1;
  return i - 1;
}

template <class T> T *SkipList<T>::skiplist_search(const T &key) {
  if (is_empty())
    return 0;
  node_ptr prev, curr;
  int lvl;
  for (lvl = max_level - 1; lvl >= 0 && !root[lvl]; lvl--)
    ;
  prev = curr = root[lvl];
  while (true) {
    if (key == curr->key)
      return &curr->key;
    else if (key < curr->key) {
      if (lvl == 0)
        return 0;
      else if (curr == root[lvl])
        curr = root[--lvl];
      else
        curr = *(prev->next + --lvl);
    } else {
      prev = curr;
      if (*(curr->next + lvl) != 0)
        curr = *(curr->next + lvl);
      else {
        for (lvl--; lvl >= 0 && *(curr->next + lvl) == 0; lvl--);
        if (lvl >= 0)
          curr = *(curr->next + lvl);
        else
          return 0;
      }
    }
  }
}

template<class T>
void SkipList<T>::skiplist_insert(const T& key){
  node_ptr curr[max_level],prev[max_level],new_node;
  int lvl,i;
  curr[max_level-1] = root[max_level-1];
  prev[max_level-1]=0;
  for(lvl=max_level-1;lvl>=0;lvl--){
    while(curr[lvl]&&curr[lvl]->key<key){
      prev[lvl]=curr[lvl];
      curr[lvl]=*(curr[lvl]->next+lvl);
    }
    if(curr[lvl]&&curr[lvl]->key==key)
      return;
    if(lvl>0)
      if(prev[lvl]==0){
        curr[lvl-1]=root[lvl-1];
        prev[lvl-1]=0;
      }
    else{
      curr[lvl-1]=*(prev[lvl]->next+lvl-1);
      prev[lvl-1]=prev[lvl];
    }
  }
  lvl = choose_level();
  new_node=new SkipListNode<T>;
  new_node->next=new node_ptr[sizeof(node_ptr)*(lvl+1)];
  new_node->key = key;
  for(i=0;i<=lvl;i++){
    *(new_node->next+i)=curr[i];
    if(prev[i]==0)
      root[i]=new_node;
    else *(prev[i]->next+i)=new_node;
  }
}

#endif //! SKIP_LIST