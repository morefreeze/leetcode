#ifndef LIST_HELPER_H

#define LIST_HELPER_H
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> list2Vector(ListNode *head);
ListNode* vector2List(const vector<int>& v);
void printList(const ListNode *head);


#endif /* end of include guard: LIST_HELPER_H */
