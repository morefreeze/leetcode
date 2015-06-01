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


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *root = ans;
        ListNode *last = NULL;
        bool carry(0);
        for (;l1 || l2;){
            int x1, x2;
            if (!l1){
                x1 = 0;
            }
            else{
                x1 = l1->val;
                l1 = l1->next;
            }
            if (!l2){
                x2 = 0;
            }
            else{
                x2 = l2->val;
                l2 = l2->next;
            }
            if (!ans) ans = new ListNode(0);
            //cout << ans << " " << root << endl;
            ans->val = (x1 + x2 + carry);
            carry = (ans->val >= 10);
            ans->val %= 10;
            //cout << "(" << ans->val << ")";
            ans->next = new ListNode(0);
            last = ans;
            ans = ans->next;
        }
        if (carry){
            ans->val = carry;
        }
        else{
            last->next = NULL;
        }
        return root;
    }
};

void print_list(ListNode *l){
    for (;l;l = l->next)
        cout << l->val;
    cout << endl;
}
int main(){
    ListNode l1(0), l2(0);
    //ListNode *l1 = new ListNode(2);
    //l1->next = new ListNode(6);
    //l1->next->next = new ListNode(4);
    //ListNode *l2 = new ListNode(3);
    //l2->next = new ListNode(6);
    //l2->next->next = new ListNode(8);
    Solution sol;
    ListNode *ans = sol.addTwoNumbers(&l1,&l2);
    //print_list(l1);
    //print_list(l2);
    print_list(ans);
    return 0;
}
