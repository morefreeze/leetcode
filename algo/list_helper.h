#ifndef LIST_HELPER_H

#define LIST_HELPER_H
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> list2Vector(ListNode *head);
ListNode* vector2List(const vector<int>& v);


#endif /* end of include guard: LIST_HELPER_H */
