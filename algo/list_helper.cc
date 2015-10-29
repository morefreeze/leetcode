#include "list_helper.h"
vector<int> list2Vector(ListNode *head){
    vector<int> ans;
    // check cycle
    ListNode *slow(head);
    ListNode *fast(head);
    while (fast) {
        fast = fast->next;
        if (NULL == fast) break;
        fast = fast->next;
        ans.push_back(slow->val);
        slow = slow->next;
        if (slow == fast) {
            cerr << "find cycle at " << ans.size() << "!" << endl;
            return ans;
        }
    }
    while(slow){
        ans.push_back(slow->val);
        slow = slow->next;
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
void printList(ListNode *head){
    vector<int> ans(list2Vector(head));
    for (int i = 0;i < ans.size();++i) {
        cout << ans[i] << " ";
    }
    cout << "!" << endl;
}
