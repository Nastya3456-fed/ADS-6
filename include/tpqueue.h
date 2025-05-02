// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <stdexcept>

struct SYM {
  char ch;
  int prior;
};

bool operator<(const SYM& lhs, const SYM& rhs) {
  return lhs.prior > rhs.prior;
}
template<typename T>
class TPQueue {
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& d) : data(d), next(nullptr) {}
  };
Node* head;

 public:
  TPQueue() : head(nullptr) {}
  ~TPQueue() {
    while (!empty()) {
      pop();
    }
  }
  bool empty() const {
    return head == nullptr;
  }
  void push(const T& element) {
    Node* newNode = new Node(element);
    if (!head || element < head->data) {
      newNode->next = head;
      head = newNode;
    } else {
      Node* current = head;
      while (current->next && !(element < current->next->data)) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
  }
  T pop() {
    if (empty()) {
      throw std::out_of_range("pop from empty queue");
    }
    Node* temp = head;
    T result = temp->data;
    head = head->next;
    delete temp;
    return result;
  }
};

#endif // INCLUDE_TPQUEUE_H_
