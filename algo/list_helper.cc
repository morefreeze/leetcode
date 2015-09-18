#include "list_helper.h"
vector<int> list2Vector(ListNode *head){
    vector<int> ans;
    while(head){
        ans.push_back(head->val);
        head = head->next;
    }
    return ans;
}
ListNode* vector2List(const vector<int>& v){
    ListNode *ans(NULL);
    ListNode *cur(NULL);
    ListNode *tmp(NULL);
    for (int i = 0;i < int(v.size());++i){
        tmp = new ListNode(v[i]);
        if (!ans){
            ans = tmp;
            cur = ans;
        }
        else{
            cur->next = tmp;
            cur = cur->next;
        }
    }
    return ans;
}
void printList(const ListNode *head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << "!" << endl;
}
