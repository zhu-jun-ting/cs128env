#include "dna_strand.hpp"

#include <stdexcept>

using namespace std;

DNAstrand::~DNAstrand() {
	end_link_ = nullptr;
  while (head_ != nullptr) {
    Node* temp = head_->next;
    delete head_;
    head_ = temp;
  }
}

void DNAstrand::SpliceIn(const char* pattern, DNAstrand& to_splice_in) {
	Node* break_point = RemovePattern(pattern);

	if (break_point == nullptr && end_link_ == nullptr) {
		head_ = to_splice_in.head_;
		tail_ = to_splice_in.tail_;
	} else if (break_point == nullptr) {
		head_ = to_splice_in.head_;
		to_splice_in.tail_->next = end_link_;
	} else if (end_link_ == nullptr) {
		tail_ = to_splice_in.tail_;
		break_point->next = to_splice_in.head_;
	} else {
		break_point->next = to_splice_in.head_;
		to_splice_in.tail_->next = end_link_;
	}

}


Node* DNAstrand::RemovePattern(const char* pattern) {
	Node* curr_node = head_;
	Node* last_node = nullptr;
	Node* break_point = nullptr;
	bool has_match = false;

  while (curr_node != nullptr) {
    Node* temp = curr_node->next;
    
		if (CheckMatch(curr_node, pattern)) {
			break_point = last_node;
		}

		last_node = curr_node;
    curr_node = temp;
  }	

	if (break_point == nullptr && !has_match) {
		throw(invalid_argument("howdy, check your input!"));
	}

	if (break_point == nullptr && end_link_ == nullptr) {
		curr_node = head_;
		head_ = nullptr;
		tail_ = nullptr;
	} else if (break_point == nullptr) {
		curr_node = head_;
		head_ = end_link_;
	} else if (end_link_ == nullptr) {
		tail_ = break_point;
	} else {
		curr_node = break_point->next;
	}

	while (curr_node != nullptr) {
		if (curr_node->next == end_link_) {
			delete curr_node;
			break;
		}
		Node* temp = curr_node->next;
		delete curr_node;
		curr_node = temp;
	}

	break_point->next = end_link_;

	return break_point;
}

bool DNAstrand::CheckMatch(Node* curr_node, const char* pattern) {
	unsigned idx = 0;
	bool is_matched = true;

  while (curr_node != nullptr || pattern[idx] == '\0') {

		if (pattern[idx] == '\0') {
			end_link_ = curr_node;
			return is_matched;
		}
    if (curr_node->data != pattern[idx]) return false;
		
    curr_node = curr_node->next;
		idx++;
  }	
	return false;
}