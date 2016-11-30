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
  NODE<T>* temp;
  NODE<T>* cur;
  NODE<T>* pre;
  if (this->lsize == 0 || index >= this->lsize){
    std::cout << "Error al eliminar elemento" << std::endl;
    return;
  }

  else if (index==0){
    temp = this->head;
    delete this->head;
    this->head = temp;
    return;
  }
  else {
    pre=this->head;
    cur=this->head->next;
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
