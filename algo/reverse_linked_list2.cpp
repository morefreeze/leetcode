#ifndef REVERSE_LINKED_LIST2_H

#define REVERSE_LINKED_LIST2_H

#include "list_helper.h"
#include <unordered_set>
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
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            if (m == n) return head;
            if (head == NULL) return NULL;
            ListNode fake_root(0);
            fake_root.next = head;
            ListNode *last(&fake_root);
            ListNode *fast(head);
            REP (i, n-m+1) {
                fast = fast->next;
                if (fast == NULL) break;
            }
            REP (i, m-1) {
                last = last->next;
                if (last == NULL) return head;
                if (fast != NULL) fast = fast->next;
            }
            ListNode *cur(last->next);
            last->next = fast;
            REP (i, n-m+1) {
                if (cur == NULL) break;
                ListNode *next(cur->next);
                cur->next = last->next;
                last->next = cur;
                cur = next;
            }
            return fake_root.next;
        }
};

#endif /* end of include guard: REVERSE_LINKED_LIST2_H */
