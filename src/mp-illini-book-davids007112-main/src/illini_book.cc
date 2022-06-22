#include "illini_book.hpp"
#include "utilities.hpp"


#include <vector>
#include <fstream>

using namespace std;

// Your code here!

IlliniBook::IlliniBook(const string &people_fpath, const string &relations_fpath) {
	fstream ifs;
	ifs.open(people_fpath, ios::in); //open a file to perform read operation using file object
	if (ifs.is_open()){ //checking whether the file is open
		string line;
		while(getline(ifs, line)){ //read data from file object and put it into string.
			// cout << line << "\n"; //print the data of the string
			uins_.push_back(stoi(line));
		}
		ifs.close(); //close the file object.
	}

	size_ = uins_.size();
	graph_ = vector<vector<string>>(size_, vector<string>(size_, ""));

	ifs.open(relations_fpath, ios::in); //open a file to perform read operation using file object
	if (ifs.is_open()){ //checking whether the file is open
		string line;
		while(getline(ifs, line)){ //read data from file object and put it into string.
			// cout << line << "\n"; //print the data of the string
			vector<string> v = utilities::Split(line, ',');
			AddEdge(stoi(v[0]), stoi(v[1]), v[2]);
		}
		ifs.close(); //close the file object.
	}
}

// IlliniBook::~IlliniBook() {
// 	for (unsigned i = 0; i < graph_.size(); i++) {
// 		graph_[i].clear();
// 	}
// 	graph_.clear();
// 	uins_.clear();
// 	size_ = 0;
// 	relations_.clear();
// }

void IlliniBook::AddEdge(const int& v1, const int& v2, const string& e) {
	int v_1 = GetId(v1);
	int v_2 = GetId(v2);
	if (v_1 != -1 && v_2 != -1) {
		graph_[v_1][v_2] = e;
		graph_[v_2][v_1] = e;
	}
	if (!ItemInVector(e, relations_)) relations_.push_back(e);
}


int IlliniBook::GetId(const int& uin) const {
	for (int i = 0; i < size_; i++) {
		if (uins_[i] == uin) return i;
	}
	return -1;
}

vector<vector<int>> IlliniBook::Traverse(const int& uuin, const vector<string> &relationships) const {
	// int uin = GetId(uuin);
	auto v = vector<vector<int>>();
	vector<int> first;
	first.push_back(uuin);
	v.push_back(first);
	int idx = 1;
	while (idx < size_) {
		vector<int> row;
		for (auto pre_uin : v[idx - 1]) {
			vector<int> adds = GetAdjacency(pre_uin, relationships);
			for (auto added_uin : adds) {
				// cout << "added_uin:" << added_uin << endl;
				// cout << "!item in vec:" << !ItemInVector(added_uin, v) << endl;
				if (!ItemInVector(added_uin, v)) row.push_back(added_uin);
			}
		}
		if (row.empty()) break;
		v.push_back(row);
		idx ++;
	}
	return v;
}

vector<int> IlliniBook::BFS(const int& uuin, const vector<string>& relationships) const {
	vector<int> v;
	vector<vector<int>> traverse = Traverse(uuin, relationships);
	for (auto row : traverse) {
		for (auto item : row) {
			v.push_back(item);
		}
	}
	return v;
}

vector<int> IlliniBook::BFS(const int& uuin) const {
	return BFS(uuin, relations_);
}


vector<int> IlliniBook::GetAdjacency(const int& uuin, const vector<string> &relationships) const {
	int uin = GetId(uuin);
	vector<int> v;
	for (int i = 0; i < size_; i++) {
		if (ItemInVector(graph_[uin][i], relationships)) v.push_back(uins_[i]);
	}
	return v;
}

bool IlliniBook::ItemInVector(const string& item, const vector<string>& vec) const {
	for (unsigned i = 0; i < vec.size(); i++) {
		if (vec[i] == item) return true;
	}
	return false;
}

bool IlliniBook::ItemInVectorInt(const int& item, const vector<int>& vec) const {
	for (unsigned i = 0; i < vec.size(); i++) {
		if (vec[i] == item) return true;
	}
	return false;
}

bool IlliniBook::ItemInVector(const int& item, const vector<vector<int>>& vec) const {
	for (unsigned i = 0; i < vec.size(); i++) {
		for (unsigned j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == item) return true;
		}
	}
	return false;
}

int IlliniBook::FindInVector(const int& item, const vector<vector<int>>& vec) const {
	for (unsigned i = 0; i < vec.size(); i++) {
		for (unsigned j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == item) return static_cast<int>(i);
		}
	}
	return -1;
}


bool IlliniBook::AreRelated(int uin_1, int uin_2, const vector<string> &relationships) const {
	return ItemInVector(uin_2, Traverse(uin_1, relationships));
}

bool IlliniBook::AreRelated(int uin_1, int uin_2, const string &relationship) const {
	vector<vector<int>> traverse = Traverse(uin_1, vector<string>{relationship});
	return ItemInVector(uin_2, traverse);
}

bool IlliniBook::AreRelated(int uin_1, int uin_2) const {
	return AreRelated(uin_1, uin_2, relations_);
}


int IlliniBook::GetRelated(int uin_1, int uin_2, const string &relationship) const {
	vector<vector<int>> traverse = Traverse(uin_1, vector<string>{relationship});
	return FindInVector(uin_2, traverse);
}

int IlliniBook::GetRelated(int uin_1, int uin_2, const vector<string> &relationships) const {
	return FindInVector(uin_2, Traverse(uin_1, relationships));
}

int IlliniBook::GetRelated(int uin_1, int uin_2) const {
	return GetRelated(uin_1, uin_2, relations_);
}

vector<int> IlliniBook::GetSteps(int uin, int n) const {
	return GetSteps(uin, n, relations_);
}


vector<int> IlliniBook::GetSteps(int uin, int n, const vector<string> &relationships) const {
	vector<vector<int>> traverse = Traverse(uin, relationships);
	if (n >= static_cast<int>(traverse.size()) || n < 0) return vector<int>();
	return traverse[n];
}

// unsigned int IlliniBook::NoConnectedComponents() {
//   vector<string> visited;
//   unsigned int num = 0;
//   for (auto node: GetVertices()) {
//     if (find(visited.begin(), visited.end(), node) == visited.end()) {
//       vector<string> v = (DepthFirstTraversal(node));
//       for (auto i: v) {
//         visited.push_back(i);
//       }
//       num ++;
//     }
//   }
//   return num;
// }

size_t IlliniBook::CountGroups(const vector<string> &relationships) const {
	vector<int> visited;
	size_t num = 0;
	for (auto uin : uins_) {
		if (!ItemInVectorInt(uin, visited)) {
			vector<int> v = BFS(uin, relationships);
			visited.insert(visited.end(), v.begin(), v.end());
			num ++;
		}
	}
	return num;
}

size_t IlliniBook::CountGroups(const string &relationship) const {
	return CountGroups(vector<string>{relationship});
}

size_t IlliniBook::CountGroups() const {
	return CountGroups(relations_);
}




// from lab

// void IlliniBook::AddVertex(const string& vertex) {
//   if (VertexInGraph(vertex))
//     throw runtime_error("vertex already in graph.");
//   graph_.insert(pair<string, list<string>>(vertex, list<string>()));
// }

// void IlliniBook::AddEdge(const string& v1, const string& v2) {
//   if (!VertexInGraph(v1) || !VertexInGraph(v2))
//     throw runtime_error("vertex not in graph.");

//   auto& v1_adj = GetAdjacencyList(v1);
//   auto& v2_adj = GetAdjacencyList(v2);
//   v1_adj.push_back(v2);
//   v2_adj.push_back(v1);
// }

// vector<string> IlliniBook::GetVertices() const {
//   vector<string> verticies;
//   for (auto const& entry : graph_) verticies.push_back(entry.first);
//   return verticies;
// }

// list<string>& IlliniBook::GetAdjacencyList(
//     const string& vertex) {
//   return graph_.find(vertex)->second;
// }

// bool IlliniBook::VertexInGraph(const string vertex) {
//   if (graph_.find(vertex) != graph_.end())
//     return true;
//   else
//     return false;
// }

// ostream& operator<<(ostream& os, const IlliniBook& graph) {
//   os << "Contents:" << endl;

//   for (const auto& pair : graph.graph_) {
//     os << "  " << setw(15) << pair.first << ": [";
//     int i = pair.second.size() - 1;
//     for (const auto& list_entry : pair.second) {
//       os << list_entry;
//       if (i != 0) os << ", ";
//       i -= 1;
//     }

//     os << "]" << endl;
//   }

//   return os;
// }



// vector<string> IlliniBook::DepthFirstTraversal(const string& origin) {
//   stack<string> s;
//   vector<string> v;
//   s.push(origin);
  
//   while(!s.empty()) {
//     string e = s.top();
//     s.pop();
//     if (find(v.begin(), v.end(), e) == v.end()) v.push_back(e);
//     for (auto a = GetAdjacencyList(e).begin(); a != GetAdjacencyList(e).end(); ++a) {
//       if (find(v.begin(), v.end(), *a) == v.end()) s.push(*a);
//     }
//   }
  
//   return v;
  
// }



// void PrintVec(int vec) {
// 	cout << " | " << vec << " | " << endl;
// }


// void PrintVec(vector<int> vec) {
// 	for (unsigned i = 0; i < vec.size(); i++) {
//     cout << vec[i] << " | ";
//   }
//   cout << endl;
// }

// void PrintVec(vector<vector<int>> vec) {
//   for (unsigned i = 0; i < vec.size(); i++) {
//     for (unsigned j = 0; j < vec[i].size(); j++) {
//       cout << vec[i][j] << " | ";
//     }
//     cout << "\n";
//   }
//   cout << endl;
// }