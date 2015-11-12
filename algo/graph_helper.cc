#include "graph_helper.h"

void printGraph(UndirectedGraphNode *node) {
    set<int> visit;
    deque<UndirectedGraphNode*> q;
    if (NULL != node) {
        q.push_back(node);
        visit.insert(node->label);
    }
    while (!q.empty()) {
        UndirectedGraphNode *cur(q.front());
        q.pop_front();
        cout << "[" << cur->label << "]";
        for (vector<UndirectedGraphNode*>::iterator it = cur->neighbors.begin();
                it != cur->neighbors.end(); ++it) {
            cout << " " << (*it)->label;
            if (visit.find((*it)->label) == visit.end()) {
                visit.insert((*it)->label);
                q.push_back(*it);
            }
        }
        cout << endl;
    }
}

UndirectedGraphNode* vector2Graph(vector< vector<int> > nums) {
    UndirectedGraphNode *node(NULL);
    map<int, UndirectedGraphNode*> m;
    for (int i = 0;i < int(nums.size()); ++i) {
        int label = nums[i][0];
        if (m.find(label) == m.end()) {
            m[label] = new UndirectedGraphNode(label);
        }
        if (node == NULL) node = m[label];
    }
    for (int i = 0;i < int(nums.size()); ++i) {
        UndirectedGraphNode *cur = m[nums[i][0]];
        for (int j = 1;j < int(nums[i].size()); ++j) {
            cur->neighbors.push_back(m[nums[i][j]]);
        }
    }
    return node;
}
