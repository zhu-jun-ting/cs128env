#ifndef DNA_STRAND_HPP
#define DNA_STRAND_HPP

#include "node.hpp"

class DNAstrand {
public:
  DNAstrand() = default;
  DNAstrand(Node* head, Node* tail):head_(head), tail_(tail){};
  DNAstrand(const DNAstrand& rhs) = delete;
  DNAstrand& operator=(const DNAstrand& rhs) = delete;
  ~DNAstrand();

  Node* GetEndLink() const {return end_link_;}

  Node* RemovePattern(const char* pattern);
  bool CheckMatch(Node* curr_node, const char* pattern);

  void SpliceIn(const char* pattern, DNAstrand& to_splice_in);

private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  Node* end_link_ = nullptr;
};

#endif