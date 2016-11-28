#include "linked_list.h"

/// NODE ///
template <class T>
NODE<T>::NODE(): val(), next(NULL) {}
template<class T>
NODE<T>::NODE(const T& _val): val(_val), next(NULL) {}
/// LINKED LIST ///
template<class T>
LINKED_LIST<T>::LINKED_LIST(): lsize(0), head(NULL), tail(NULL) {}
template<class T>
void LINKED_LIST<T>::pushback(NODE<T>* node){
  if (this->lsize==0){
    this->head = node;
    this->tail = node;
  }
  else {
    this->tail->next = node;
    this->tail = node;
  }
  ++this->lsize;
}
template <class T>
void LINKED_LIST<T>::delete_in(int index){
  if (this->lsize == 0 || index >= this->lsize){
    std::cout << "Error al eliminar elemento" << std::endl;
    return;
  }
  Node<T>* temp;
  else if (index==0){
    temp = this->head;
    delete this->head;
    this->head = temp;
    return;
  }
  Node<T>* cur;
  Node<T>* pre;
  pre=this->head;
  cur=this->head->next;
  else {
    for (int i=0;i<index;i++){
      pre=cur;
      cur=cur->next;
    }
    if (cur->val==this->tail->val)
      this->tail=pre;
    pre->next=cur->next;
    delete cur;
    return;
  }
}
