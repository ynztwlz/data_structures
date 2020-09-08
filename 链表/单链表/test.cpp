#include<iostream>
#include "singleLinkedList.h"
using namespace std;

int main(){
  SingleLinkedList<int> slst;
  for(size_t i=0;i!=20;i++)
    slst.add_to_tail(i);
  slst.print_list();
  system("pause");
  return 0; 
}
