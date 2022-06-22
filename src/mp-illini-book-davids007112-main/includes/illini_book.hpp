#ifndef ILLINI_BOOK_HPP
#define ILLINI_BOOK_HPP
#include "utilities.hpp"

#include <string>
#include <vector>

using namespace std;

class IlliniBook {
public:
  IlliniBook(const string &people_fpath, const string &relations_fpath);
  IlliniBook(const IlliniBook &rhs) = delete;
  IlliniBook &operator=(const IlliniBook &rhs) = delete;
  ~IlliniBook() = default;
  bool AreRelated(int uin_1, int uin_2) const;
  bool AreRelated(int uin_1, int uin_2, const string &relationship) const;
  bool AreRelated(int uin_1, int uin_2, const vector<string> &relationships) const;
  int GetRelated(int uin_1, int uin_2) const;
  int GetRelated(int uin_1, int uin_2, const string &relationship) const;
  int GetRelated(int uin_1, int uin_2, const vector<string> &relationships) const;
  vector<int> GetSteps(int uin, int n) const;
  vector<int> GetSteps(int uin, int n, const vector<string> &relationships) const;
  size_t CountGroups() const;
  size_t CountGroups(const string &relationship) const;
  size_t CountGroups(const vector<string> &relationships) const;

  // from lab
  // unsigned int NoConnectedComponents();

  // void AddVertex(const string& vertex);
  void AddEdge(const int& v1, const int& v2, const string& e);
  // vector<string> GetVertices() const;

  // friend ostream& operator<<(ostream& os, const IlliniBook& graph);
  vector<vector<int>> Traverse(const int& uuin, const vector<string> &relationships) const;


  int GetId(const int& uin) const;
  // vector<vector<int>> Traverse(const int& uuin, const vector<string> &relationships) const;
  vector<int> GetAdjacency(const int& uuin, const vector<string> &relationships) const;
  bool ItemInVectorInt(const int& item, const vector<int>& vec) const;
  bool ItemInVector(const string& item, const vector<string>& vec) const;
  bool ItemInVector(const int& item, const vector<vector<int>>& vec) const;
  int FindInVector(const int& item, const vector<vector<int>>& vec) const;
  vector<int> BFS(const int& uuin) const;
  vector<int> BFS(const int& uuin, const vector<string>& relationships) const;
  // bool VertexInGraph(const string vertex);
  // list<string>& GetAdjacencyList(const string& vertex);
  // map<string, list<string>> graph_;
  // vector<string> DepthFirstTraversal(const string& origin); 
  
private:  
  vector<vector<string>> graph_;
  vector<int> uins_;
  int size_;
  vector<string> relations_;
};

// void PrintVec(vector<vector<int>> vec);
// void PrintVec(vector<int> vec);
// void PrintVec(int vec);

#endif
