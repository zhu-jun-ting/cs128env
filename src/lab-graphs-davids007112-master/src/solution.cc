#include "solution.hpp"

#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

Solution::Solution(const vector<pair<string, string>>& prerequisites) {
  // TODO : implement this!
	for (auto const& entry: prerequisites) {
		if (!VertexInGraph(entry.first)) AddVertex(entry.first);
		AddEdge(entry.first, entry.second);
	}
}

using namespace std;

int Solution::Solve(const string& start, const string& dest) {
  // TODO : implement this!

  // Note that since this is not a node based graph (we are using adjacency
  // lists), this will probably NOT be a recursive function

	queue<string> q;
	list<string> visited;
	q.push(start);

	while (!q.empty()) {
		string e = q.front();
		q.pop();
		list<string> l = GetAdjacencyList(e);

		for (string s: l) {
			if (find(visited.begin(), visited.end(), s) == visited.end()) {
				visited.push_back(s);
				q.push(s);
			}
		}
	}


  return -1;
}

///////////////////////////////////////////////////////////////////////////////
// Provide function definitions (uncomment to use!)                          //
///////////////////////////////////////////////////////////////////////////////

void Solution::AddVertex(const string& vertex) {
  if (VertexInGraph(vertex))
    throw runtime_error("vertex already in graph.");
  adj_.insert(pair<string, list<string>>(vertex, list<string>()));
}

list<string>& Solution::GetAdjacencyList(const string& vertex) {
  return adj_.find(vertex)->second;
}

bool Solution::VertexInGraph(const string kVertex) {
  if (adj_.find(kVertex) != adj_.end())
    return true;
  else
    return false;
}

ostream& operator<<(ostream& os, const Solution& sol) {
  os << "Contents:" << endl;

  for (const auto& pair : sol.adj_) {
    os << "  " << pair.first << ": [ ";

    for (const auto& list_entry : pair.second) {
      os << list_entry << " ";
    }

    os << "]" << endl;
  }

  return os;
}

void Solution::AddEdge(const string& v1, const string& v2) {
  if (!VertexInGraph(v1) || !VertexInGraph(v2))
    throw runtime_error("vertex not in graph.");

  auto& v1_adj = GetAdjacencyList(v1);
  auto& v2_adj = GetAdjacencyList(v2);
  v1_adj.push_back(v2);
  v2_adj.push_back(v1);
}