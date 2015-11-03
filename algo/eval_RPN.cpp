#ifndef EVAL_RPN_H

#define EVAL_RPN_H

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
        bool isOpor(const string &s) {
            return (s == "+" || s == "-" || s == "*" || s == "/");
        }
        int str2Int(const string &s) {
            if (SZ(s) == 0) return 0;
            int ans(0);
            if (s[0] != '-') {
                ans = s[0] - '0';
            }
            FOR (i, 1, SZ(s)) {
                ans = ans * 10 + s[i] - '0';
            }
            if (s[0] == '-') {
                ans = -ans;
            }
            return ans;
        }
        int evalRPN(vector<string>& tokens) {
            deque<int> op_nums;
            REP (i, SZ(tokens)) {
                if (isOpor(tokens[i])) {
                    int rhs(op_nums.back());
                    op_nums.pop_back();
                    int lhs(op_nums.back());
                    op_nums.pop_back();
                    switch (tokens[i][0]) {
                        case '+':
                            lhs += rhs;
                            break;
                        case '-':
                            lhs -= rhs;
                            break;
                        case '*':
                            lhs *= rhs;
                            break;
                        case '/':
                            lhs /= rhs;
                            break;
                    }
                    op_nums.PB(lhs);
                }
                else {
                    op_nums.PB(str2Int(tokens[i]));
                }
            }
            return op_nums.back();
        }
};

#endif /* end of include guard: EVAL_RPN_H */
