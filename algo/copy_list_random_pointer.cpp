/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	// It is hard to construct unittest, so omit it.
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *cur(head);
        RandomListNode fake_head(0);
        RandomListNode *fake_cur(NULL);
        RandomListNode *fake_last(&fake_head);
        map<RandomListNode*,RandomListNode*> d;
        
        while (cur) {
            fake_cur = new RandomListNode(cur->label);
            d[cur] = fake_cur;
            fake_last->next = fake_cur;
            cur = cur->next;
            fake_cur = fake_cur->next;
            fake_last = fake_last->next;
        }
        cur = head;
        fake_cur = fake_head.next;
        while (cur) {
            fake_cur->random = d[cur->random];
            cur = cur->next;
            fake_cur = fake_cur->next;
        }
        return fake_head.next;
    }
};