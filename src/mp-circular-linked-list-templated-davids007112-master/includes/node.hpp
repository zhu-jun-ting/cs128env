#ifndef NODE_HPP
#define NODE_HPP

// DO NOT MODIFY THIS FILE: OUR GRADER USES THE ORIGINAL NODE.HPP PROVIDED TO
// YOU. WE DO NOT COPY THIS FILE FROM YOUR WORKSPACE TO OUR AUTO-GRADER.

template <typename T>
struct Node {
  T data;         // NOLINT
  Node<T>* next;  // NOLINT
  Node(T data): data(data), next(nullptr) {}
  Node(T data, Node<T>* next): data(data), next(next) {}
};

#endif