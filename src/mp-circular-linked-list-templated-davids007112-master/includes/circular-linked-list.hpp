#ifndef CIRCULAR_LINKED_LIST_HPP
#define CIRCULAR_LINKED_LIST_HPP

#include <iostream>

#include "node.hpp"

using namespace std;

enum class Order { kASC, kDESC };

template <typename T>
class CircularLinkedList {
public:
  CircularLinkedList() = default;
  CircularLinkedList(const CircularLinkedList<T>& source);
  CircularLinkedList<T>& operator=(const CircularLinkedList<T>& source);
  ~CircularLinkedList();

  void InsertInOrder(const T& data);
  void Reverse();

  template <typename U>
  friend ostream& operator<<(ostream& os,
                                  const CircularLinkedList<U>& cll);

private:
  Node<T>* head_ = nullptr;
  Node<T>* tail_ = nullptr;
  Order node_order_ = Order::kASC;

  void InsertInReverseOrder(const T& data);

  void ToggleOrder();
  void Clear();
};

template <typename T>
void CircularLinkedList<T>::ToggleOrder() {
  if (node_order_ == Order::kASC) node_order_ = Order::kDESC;
  else if (node_order_ == Order::kDESC) node_order_ = Order::kASC;
}

template <typename T>
void CircularLinkedList<T>::Reverse() {
  if (head_ == nullptr || head_ == tail_) {
    ToggleOrder();
    return;
  }
  Node<T>* pre = tail_;
  Node<T>* cur = head_;
  Node<T>* nex = head_->next;
  do {
    Node<T>* next_pre = cur;
    Node<T>* next_cur = nex;
    Node<T>* next_nex = nex->next;
    // before: pre ----> cur ----> nex   |     after: pre <-- --> cur          nex
    cur->next = pre;
    pre = next_pre;
    cur = next_cur;
    nex = next_nex;
  } while (cur != head_);
  Node<T>* temp = head_;
  head_ = tail_;
  tail_ = temp;
  ToggleOrder();
}

template <typename T>
void CircularLinkedList<T>::InsertInReverseOrder(const T& data) {
  if (head_ == nullptr) {
    head_ = new Node<T>(data);
    head_->next = head_;
    tail_ = head_;
    return;
  }
  if (data >= head_->data) {
    auto* temp = new Node<T>(data, head_);
    tail_->next = temp;
    head_ = temp;
    return;
  }
  Node<T>* cur = head_;
  do {
    Node<T>* temp = cur->next;
    if (temp == head_) {
      cur->next = new Node<T>(data, head_);
      tail_ = cur->next;
      return;
    }
    if (cur->data >= data && data >= cur->next->data) {
      cur->next = new Node<T>(data, temp);
      return;
    }
    cur = temp;
  } while (cur != head_);
}

template <typename T>
void CircularLinkedList<T>::InsertInOrder(const T& data) {
  if (node_order_ == Order::kDESC) {
    InsertInReverseOrder(data);
    return;
  }
  if (head_ == nullptr) {
    head_ = new Node<T>(data);
    head_->next = head_;
    tail_ = head_;
    return;
  }
  if (data <= head_->data) {
    auto* temp = new Node<T>(data, head_);
    tail_->next = temp;
    head_ = temp;
    return;
  }
  Node<T>* cur = head_;
  do {
    Node<T>* temp = cur->next;
    if (temp == head_) {
      cur->next = new Node<T>(data, head_);
      tail_ = cur->next;
      return;
    }
    if (cur->data <= data && data <= cur->next->data) {
      cur->next = new Node<T>(data, temp);
      return;
    }
    cur = temp;
  } while (cur != head_);
}

template <typename T>
CircularLinkedList<T>::~CircularLinkedList() {
  if (head_ == nullptr) return;
  if (head_->next == head_) {
    delete head_;
    head_ = nullptr;
    tail_ = nullptr;
    return;
  }
  Node<T>* curr = head_;
  do {
    Node<T>* temp = curr->next;
    delete curr;
    curr = temp;
  } while (curr != head_);
  head_ = nullptr;
  tail_ = nullptr;
}

template <typename T>
void CircularLinkedList<T>::Clear() {
  if (head_ == nullptr) return;
  if (head_->next == head_) {
    delete head_;
    head_ = nullptr;
    tail_ = nullptr;
    return;
  }
  Node<T>* curr = head_;
  do {
    Node<T>* temp = curr->next;
    delete curr;
    curr = temp;
  } while (curr != head_);
  head_ = nullptr;
  tail_ = nullptr;
}

template <typename T>
CircularLinkedList<T>& CircularLinkedList<T>::operator=(const CircularLinkedList<T>& source) {
  if (this == &source) return *this;
  Clear();
  Node<T>* iter = source.head_;
  if (iter == nullptr) {
    head_ = nullptr;
    tail_ = nullptr;
    node_order_ = source.node_order_;
  } else if (source.head_ == source.tail_) {
    head_ = new Node<T>(source.head_->data);
    head_->next = head_;
    tail_ = head_;
    node_order_ = source.node_order_;
  } else {
    head_ = new Node<T>(source.head_->data);
    Node<T>* curr = head_;
    while (iter->next != source.head_) {
      curr->next = new Node<T>(iter->next->data);
      iter = iter->next;
      curr = curr->next;
    }
    curr->next = head_;
    tail_ = curr;
    node_order_ = source.node_order_;
  }
  return *this;
}

template <typename T>
CircularLinkedList<T>::CircularLinkedList(const CircularLinkedList<T>& source) {
  Node<T>* iter = source.head_;
  if (iter == nullptr) {
    head_ = nullptr;
    tail_ = nullptr;
    node_order_ = source.node_order_;
  } else if (source.head_ == source.tail_) {
    head_ = new Node<T>(source.head_->data);
    head_->next = head_;
    tail_ = head_;
    node_order_ = source.node_order_;
  } else {
    head_ = new Node<T>(source.head_->data);
    Node<T>* curr = head_;
    while (iter->next != source.head_) {
      curr->next = new Node<T>(iter->next->data);
      iter = iter->next;
      curr = curr->next;
    }
    curr->next = head_;
    tail_ = curr;
    node_order_ = source.node_order_;
  }
}

template <typename T>
ostream& operator<<(ostream& os, const CircularLinkedList<T>& cll) {
  Node<T>* iter = cll.head_;
  // empty list condition
  if (iter == nullptr) {
    os << "Empty list";
    return os;
  }
  // non-empty list condition
  do {
    os << iter->data << '\t';
    iter = iter->next;
  } while (iter != cll.head_);

  return os;
}

#endif