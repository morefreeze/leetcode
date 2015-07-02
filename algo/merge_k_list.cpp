#ifndef MERGE_K_LIST_H

#define MERGE_K_LIST_H
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
#include <queue>

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

struct node{
    int val, idx;
    node(int v, int i): val(v), idx(i){}
    friend bool operator< (const node& lhs, const node& rhs){ return lhs.val > rhs.val; }
};
class Solution {
    public:
        priority_queue<node> pq;
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            REP(i, SZ(lists)){
                if (lists[i]){
                    pq.push(node(lists[i]->val, i));
                }
            }
            if (pq.empty()) return NULL;
            node nd(pq.top());
            ListNode *root(new ListNode(nd.val));
            ListNode *last(root);
            pq.pop();
            lists[nd.idx] = lists[nd.idx]->next;
            if (lists[nd.idx]) pq.push(node(lists[nd.idx]->val, nd.idx));
            while(!pq.empty()){
                nd = pq.top();
                last->next = new ListNode(nd.val);
                last = last->next;
                pq.pop();
                lists[nd.idx] = lists[nd.idx]->next;
                if (lists[nd.idx]) pq.push(node(lists[nd.idx]->val, nd.idx));
            }
            return root;
        }
        ListNode* mergeKListsForce(vector<ListNode*>& lists) {
            int t(-1);
            REP(i, SZ(lists)){
                if (lists[i] && (t == -1 || lists[i]->val < lists[t]->val)){
                    t = i;
                }
            }
            if (t == -1) return NULL;
            ListNode *root = new ListNode(lists[t]->val);
            lists[t] = lists[t]->next;
            ListNode *last(root);
            while(1){
                t = -1;
                REP(i, SZ(lists)){
                    if (lists[i] && (t == -1 || lists[i]->val < lists[t]->val)){
                        t = i;
                    }
                }
                if (t == -1) break;
                last->next = new ListNode(lists[t]->val);
                lists[t] = lists[t]->next;
                last = last->next;
            }
            return root;
        }
};

#endif /* end of include guard: MERGE_K_LIST_H */
