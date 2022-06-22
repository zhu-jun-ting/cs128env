#ifndef DNA_STRAND_HPP
#define DNA_STRAND_HPP

#include "node.hpp"

class DNAstrand {
public:
  DNAstrand() = default;
  DNAstrand(const DNAstrand& rhs) = delete;
  DNAstrand& operator=(const DNAstrand& rhs) = delete;
  ~DNAstrand();

  void SpliceIn(const char* patternss, DNAstrand& to_splice_in);
  void Find(bool& disc, bool& is_ffirst, Node*& find, Node*& figure_first, Node*& figure_end, int length, const char* patternss);
  void Replacement(Node*& find, Node*& figure_first, Node*& figure_end);
  void Replacement22(Node*& find, Node*& figure_first, Node*& figure_end);

private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif