#include "dna_strand.hpp"

#include <stdexcept>

DNAstrand::~DNAstrand() {
  while (head_ != nullptr) {

    Node* temp = head_->next;
    delete head_;
    head_ = temp;
  }
}

void DNAstrand::Find(bool& disc,
                     bool& is_ffirst,
                     Node*& find,
                     Node*& figure_first,
                     Node*& figure_end,
                     int length, const char* patternss) {
  int count = 0;
  Node* sec_first = nullptr;

  while (find != nullptr) {
    count = (find->data == patternss[count]) ? count + 1 : 0;
    if (count == 0) {
      count = (find->data == patternss[0]) ? count + 1 : 0;
    }
    if (count == 1) {
      if (disc) {
        sec_first = find;  // new char
      } else {
        figure_first = find;
      }
    }
    if (count == length) {

      is_ffirst = figure_first == head_;
      count = 0;
      figure_end = find->next;
      if (disc) {
        is_ffirst = false;
        figure_first = nullptr;
        figure_first = sec_first;
        sec_first = nullptr;
      }
      disc = true;
    }
    find = find->next;
  }
}

void DNAstrand::Replacement(Node*& find,
                            Node*& figure_first,
                            Node*& figure_end) {
  figure_first = nullptr;
  while (find != figure_end) {  // delete next node
    Node* temp = find->next;
    delete find;
    find = temp;
    head_ = temp;
  }
  Node* temp = new Node('b');
  temp->next = head_;
  head_ = temp;
  figure_first = head_;
}
void DNAstrand::Replacement22(Node*& find,
                             Node*& figure_first,
                             Node*& figure_end) {
  figure_first = nullptr;
  while (find->next != figure_end) {  // delete next node
    Node* temp = find->next->next;
    delete find->next;

    find->next = temp;

  }
  figure_first = find;
}
void DNAstrand::SpliceIn(const char* patternss, DNAstrand& to_splice_in) {
  int length = 0;
  if (patternss[0] == '\0' || to_splice_in.head_ == nullptr) {
    return;
  }
  while (patternss[length] != '\0') {  // length pf the patternss;
    length++;
  }
  Node* find = head_;

  Node* figure_first = nullptr;
  Node* figure_end = nullptr;
  bool disc = false;
  bool is_ffirst = false;
  Find(disc, is_ffirst, find, figure_first, figure_end, length, patternss);
  if (!disc) {  // if not match ----stop;
    throw std::invalid_argument("no match");
  }
  find = head_;
  while (find != nullptr) {
    if (is_ffirst) {
      Replacement(find, figure_first, figure_end);
      break;
    }
    if (find->next == figure_first) {
      Replacement22(find, figure_first, figure_end);
      break;
    }
    find = find->next;
  }  // remove useless node
  figure_first->next = to_splice_in.head_;
  to_splice_in.tail_->next = figure_end;
  if (is_ffirst) {
    Node* temp = head_->next;
    delete head_;
    head_ = temp;

  }
  to_splice_in.head_ = nullptr;
  to_splice_in.tail_ = nullptr;
}
