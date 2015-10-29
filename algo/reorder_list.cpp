#ifndef REORDER_LIST_H

#define REORDER_LIST_H

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
        void reorderList(ListNode* head) {
            if (NULL == head) return ;
            ListNode *slow(head);
            ListNode *fast(head);
            while(fast->next) {
                fast = fast->next;
                if (NULL == fast->next) break;
                fast = fast->next;
                slow = slow->next;
            }
            // one or two element
            if (slow == fast) return ;
            // reverse later half
            ListNode *cur(slow->next);
            ListNode *next(cur->next);
            slow->next = NULL;
            while (cur) {
                next = cur->next;
                cur->next = slow->next;
                slow->next = cur;
                cur = next;
            }
            // if you draw a picture will help you understand code
            ListNode *half(slow);
            slow = half->next;
            while (slow) {
                if (head->next == slow) break;
                half->next = slow->next;
                slow->next = head->next;
                head->next = slow;
                head = slow->next;
                slow = half->next;
            }
        }
        void bruteForce(ListNode* head) {
            if (NULL == head) return ;
            while(1) {
                ListNode *last(head);
                ListNode *last2(NULL);
                while(last->next) {
                    last2 = last;
                    last = last->next;
                }
                // neighbor or same element
                if (last2 == head || last2 == NULL) break;
                last->next = head->next;
                last2->next = NULL;
                head->next = last;
                head = last->next;
            }
        }
};

#endif /* end of include guard: REORDER_LIST_H */
