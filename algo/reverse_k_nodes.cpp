#ifndef REVERSE_K_NODES_H

#define REVERSE_K_NODES_H
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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (k == 1) return head;
            int n(0);
            ListNode *cur(head);
            while(cur){
                ++n;
                cur = cur->next;
            }
            ListNode *root(head);
            ListNode *father(NULL);
            cur = head;
            while(k <= n){
                ListNode *n1(NULL);
                ListNode *n2(NULL);
                REP(i, k-1){
                    n1 = cur->next;
                    n2 = n1->next;
                    if (father){
                        n1->next = father->next;
                        father->next = n1;
                    }
                    else{
                        n1->next = root;
                        root = n1;
                    }
                    cur->next = n2;
                }
                if (father){
                    father->next = n1;
                }
                father = cur;
                cur = cur->next;
                n -= k;
            }
            return root;
        }
};

#endif /* end of include guard: REVERSE_K_NODES_H */
