#ifndef BASIC_CALC2_H

#define BASIC_CALC2_H

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
        void trim(string &s) {
            for (int i = SZ(s)-1; i >= 0; --i) {
                if (s[i] == ' ') {
                    s.erase(i, 1);
                }
            }
        }
        int calculate(string s) {
            trim(s);
            s = '(' + s + ')';
            deque<char> op_stack;
            deque<int> num_stack;
            int cur_num(0);
            bool was_num(false);
            bool can_op(false);
            REP (i, SZ(s)) {
                //debug(s[i]);
                if ('0' <= s[i] && s[i] <= '9') {
                    cur_num = cur_num * 10 + (s[i]-'0');
                    was_num = true;
                }
                else { // +-*/()
                    if (was_num) {
                        //debug(cur_num);
                        num_stack.PB(cur_num);
                        cur_num = 0;
                        was_num = false;
                        can_op = true;
                    }
                    if (can_op) {
                        while (!op_stack.empty()) {
                            char cur_op(op_stack.back());
                            int op_nums[2];
                            if (cur_op == '(') {
                                break;
                            }
                            else {
                                if ((cur_op == '+' || cur_op == '-') && (s[i] == '*' || s[i] == '/')) break;
                                REP (j, 2) {
                                    if (num_stack.empty()) {
                                        cerr << "num_stack empty!" << endl;
                                        return -1;
                                    }
                                    op_nums[j] = num_stack.back();
                                    num_stack.pop_back();
                                }
                                switch (cur_op) {
                                    case '+':
                                        num_stack.PB(op_nums[1]+op_nums[0]);
                                        break;
                                    case '-':
                                        num_stack.PB(op_nums[1]-op_nums[0]);
                                        break;
                                    case '*':
                                        num_stack.PB(op_nums[1]*op_nums[0]);
                                        break;
                                    case '/':
                                        num_stack.PB(op_nums[1]/op_nums[0]);
                                        break;
                                    default:
                                        cerr << "invalid operator " << cur_op << endl;
                                        return -1;
                                }
                            }
                            op_stack.pop_back();
                        }
                        can_op = false;
                    }
                    switch (s[i]) {
                        case '+':
                        case '-':
                        case '*':
                        case '/':
                        case '(':
                            op_stack.PB(s[i]);
                            break;
                        case ')':
                            if (!op_stack.empty() && op_stack.back() == '(') {
                                op_stack.pop_back();
                                can_op = true;
                            }
                            else {
                                cerr << "parenthes DOES NOT match" << endl;
                                return -1;
                            }
                            break;
                    }
                }
            }
            return num_stack.front();
        }

};

#endif /* end of include guard: BASIC_CALC2_H */
