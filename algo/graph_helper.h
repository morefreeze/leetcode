#ifndef GRAPH_HELPER_H

#define GRAPH_HELPER_H

#include <set>
#include <map>
#include <deque>
#include <vector>
#include <iostream>
using namespace std;
//Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void printGraph(UndirectedGraphNode *node);
UndirectedGraphNode* vector2Graph(vector< vector<int> >);
#endif /* end of include guard: GRAPH_HELPER_H */
