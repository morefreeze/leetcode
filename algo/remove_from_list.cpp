#ifndef REMOVE_FROM_LIST_H

#define REMOVE_FROM_LIST_H

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *cur(head);
            REP(i, n){
                cur = cur->next;
            }
            if (!cur){
                ListNode *tmp = head;
                head = head->next;
                free(tmp);
                return head;
            }
            ListNode *last = head;
            while(cur->next){
                last = last->next;
                cur = cur->next;
            }
            ListNode *tmp = last->next->next;
            free(last->next);
            last->next = tmp;
            return head;
        }
        VI list2Vector(ListNode *head){
            VI ans;
            while(head){
                ans.PB(head->val);
                head = head->next;
            }
            return ans;
        }
        ListNode* vector2List(const VI& v){
            ListNode *ans(NULL);
            ListNode *cur(NULL);
            ListNode *tmp(NULL);
            REP(i, SZ(v)){
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
};

#endif /* end of include guard: REMOVE_FROM_LIST_H */
