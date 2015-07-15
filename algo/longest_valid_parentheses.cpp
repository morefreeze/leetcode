#ifndef LONGEST_VALID_PARENTHESES_H

#define LONGEST_VALID_PARENTHESES_H

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
    struct node{
        char c;
        int idx;
        node(char c, int idx):c(c), idx(idx){}
    };
    public:
        int longestValidParentheses(string s) {
            if ("" == s) return 0;
            stack<node> st;
            int vi[SZ(s)];
            CLR(vi);
            REP(i, SZ(s)){
                if (s[i] == '('){
                    st.push(node(s[i], i));
                }
                // ')'
                else{
                    if (st.empty()){
                    }
                    // !empty
                    else{
                        node cur(st.top());
                        if (cur.c == '('){
                            vi[cur.idx] = 1;
                            vi[i] = 1;
                            st.pop();
                        }
                        // ')'
                        else{
                            while(!st.empty()) st.pop();
                        }
                    }
                }
            }
            int ans(0);
            int cnt(0);
            REP(i, SZ(s)){
                if (vi[i]){
                    cnt++;
                }
                else{
                    ans = max(ans, cnt);
                    cnt = 0;
                }
            }
            ans = max(ans, cnt);
            return ans;
        }
};

#endif /* end of include guard: LONGEST_VALID_PARENTHESES_H */
