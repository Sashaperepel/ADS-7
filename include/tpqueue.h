// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
    private:
   struct Item {
      T data;
      Item* next;
   };
   Item* head;

    public:
   TPQueue() : head(nullptr) {}
   void push(const T& value) {
     if (head == nullptr) {
       Item* temp = new Item;
       temp->data = value;
       temp->next = nullptr;
       head = temp;
     } else {
       Item* a1 = head;
       Item* a2 = new Item;
       int c = 0;
       while (a1) {
         if (a1->data.prior < value.prior) {
           break;
         } else {
           a1 = a1->next;
           c++;
         }
       }
       if (c == 0) {
         a2->next = head;
         a2->data = value;
         head = a2;
       } else {
         a1 = head;
         for (int i = 1; i < c; i++) {
           a1 = a1->next;
         }
         a2->next = a1->next;
         a2->data = value;
         a1->next = a2;
       }
     }
   }
   T pop() {
     if (head == nullptr) {
       throw std::string("Empty");
     } else {
       T b = head->data;
       Item* q = head->next;
       delete head;
       head = q;
       return b;
     }
   }
};

struct SYM {
  char ch;
  int prior;
};

#endif // INCLUDE_TPQUEUE_H_
