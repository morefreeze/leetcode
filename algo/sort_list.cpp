#ifndef SORT_LIST_H

#define SORT_LIST_H

#include "list_helper.h"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define ASZ(a) (a),(a)+int(sizeof(a)/sizeof(a[0]))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if (head == NULL) return NULL;
            ListNode *fast(head);
            ListNode *slow(head);
            while (fast->next != NULL) {
                fast = fast->next;
                if (fast->next == NULL) break;
                fast = fast->next;
                slow = slow->next;
            }
            // only one element
            if (fast == slow) return head;
            ListNode *first(head);
            ListNode *second(slow->next);
            // split list into two part
            slow->next = NULL;
            first = sortList(first);
            second = sortList(second);
            if (first->val <= second->val) {
                head = first;
                first = first->next;
            }
            else {
                head = second;
                second = second->next;
            }
            ListNode *cur(head);
            while (first != NULL && second != NULL) {
                if (first->val <= second->val) {
                    cur->next = first;
                    first = first->next;
                }
                else {
                    cur->next = second;
                    second = second->next;
                }
                cur = cur->next;
            }
            if (first != NULL) {
                cur->next = first;
            }
            // second != NULL
            else {
                cur->next = second;
            }
            return head;
        }
};

#endif /* end of include guard: SORT_LIST_H */
