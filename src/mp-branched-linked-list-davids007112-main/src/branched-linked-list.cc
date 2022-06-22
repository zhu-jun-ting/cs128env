#include "branched-linked-list.hpp"
#include <cstddef>
#include <stdexcept>
#include <string>
using namespace std;

BLL::BLL(): head_(nullptr) {}

BLL::BLL(const BLL& to_copy) {
	if (to_copy.head_ == nullptr) {
		head_ = nullptr;
		return;
	}
	head_ = new Node(to_copy.head_->data_);
	Node* cur = to_copy.head_;
	Node* me = head_;
	while (cur != nullptr) {
		if (cur->next_node_ != nullptr) me->next_node_ = new Node(cur->next_node_->data_);
		if (cur->next_bll_ != nullptr) me->next_bll_ = new BLL(*(cur->next_bll_));
		cur = cur->next_node_;
	}
}


BLL::~BLL() {
	if (head_ == nullptr) return;
	while (head_ != nullptr) {
		delete head_->next_bll_;
		head_ = head_->next_node_;
	}
}

void BLL::Clear() {
	if (head_ == nullptr) return;
	while (head_ != nullptr) {
		delete head_->next_bll_;
		head_ = head_->next_node_;
	}
}

Node* BLL::PushBack(char dat) {
	if (head_ == nullptr) {
		head_ = new Node(dat);
		return head_;
	}
	Node* cur = head_;
	while (cur->next_node_ != nullptr) {
		cur = cur->next_node_;
	}
	cur->next_node_ = new Node(dat);
	return cur->next_node_;
}

void BLL::Join(size_t idx, BLL* list) {
	if (Size() < idx) {
		throw invalid_argument("howdy");
	}
	Node* cur = head_;
	while (idx != 0) {
		if (cur->next_bll_ != nullptr) {
			if (cur->next_bll_->Size() < idx) {
				idx -= cur->next_bll_->Size();
				cur = cur->next_node_;
			} else {
				cur->next_bll_->Join(idx - 1, list);
			}
		}
		cur = cur->next_node_;
		idx --;
	}
	cur->next_bll_ = list;
}

Node* BLL::GetNodeAt(size_t idx) const {
	if (Size() < idx) {
		throw invalid_argument("howdy");
	}
	Node* cur = head_;
	while (idx != 0) {
		if (cur->next_bll_ != nullptr) {
			if (cur->next_bll_->Size() < idx) {
				idx -= cur->next_bll_->Size();
				cur = cur->next_node_;
			} else {
				return cur->next_bll_->GetNodeAt(idx - 1);
			}
		}
		cur = cur->next_node_;
		idx --;
	}
	return cur;	
}


char BLL::GetAt(size_t idx) const {
	if (Size() < idx) {
		throw invalid_argument("howdy");
	}

	Node* cur = head_;
	while (idx != 0) {
		if (cur->next_bll_ != nullptr) {
			if (cur->next_bll_->Size() < idx) {
				idx -= cur->next_bll_->Size();
				cur = cur->next_node_;
			} else {
				return cur->next_bll_->GetAt(idx - 1);
			}
		}
		cur = cur->next_node_;
		idx --;
	}
	return cur->data_;
}

size_t BLL::Size() const {
	if (head_ == nullptr) return 0;
	if (!IsBLLAcyclic()) throw invalid_argument("cyclic");
	Node* cur = head_;
	size_t count = 0;
	while (cur != nullptr) {
		if (cur->next_bll_ != nullptr) {
			count += cur->next_bll_->Size();
		}
		cur = cur->next_node_;
		count ++;
	}
	return count;
}

bool BLL::IsBLLAcyclic() const {
	if (head_ == nullptr || (head_->next_node_ == nullptr && head_->next_bll_ == nullptr)) {
		return true;
	}
	Node* og = head_;
	Node* sf = GetNext(og);
	// size_t og = 0;
	// size_t sf = 1;
	while (og != nullptr && sf != nullptr && GetNext(sf) != nullptr) {
		if (og == sf) return false;
		og = GetNext(og);
		sf = GetNext(sf);
		sf = GetNext(sf);
	}
	return true;
}

Node* GetNext(Node*& cur) {
	if (cur == nullptr) return nullptr;
	if (cur->next_bll_ != nullptr) return cur->next_bll_->GetHead();
	if (cur->next_node_ != nullptr) return cur->next_node_;
	return nullptr;
}

