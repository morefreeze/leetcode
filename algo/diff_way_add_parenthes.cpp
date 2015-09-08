#ifndef DIFF_WAY_ADD_PARENTHES_H

#define DIFF_WAY_ADD_PARENTHES_H

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
        VI ans;
        vector<int> expr;
        vector<char> op;
        void print(){
            cout << "============" << endl;
            for (vector<int>::iterator it=expr.begin();it!=expr.end();++it) cout << *it << " ";
            cout << endl;
            for (vector<char>::iterator it=op.begin();it!=op.end();++it) cout << *it << " ";
            cout << endl;
            cout << "============" << endl;
        }
        /*
         * list is evil!
        void dfs(list<int>::iterator it, list<char>::iterator op_it){
            print();
            if (SZ(expr) == 1){
                ans.PB(expr.front());
                return ;
            }
            //list<int>::iterator it(expr.begin());
            //list<char>::iterator op_it(op.begin());
            //for (int i = 0;it != expr.end() && op_it != op.end() && i < last_idx-1;++it,++op_it,++i);
            //FOR (i, max(0, last_idx-1), SZ(op)){
            if (it != expr.begin()) --it;
            if (op_it != op.begin()) --op_it;
            for (;it != expr.end() && op_it != op.end();++it,++op_it){
                list<int>::iterator sec(it);
                ++sec;
                char cur_op(*op_it);
                int cur_expr(*it);
                int next_expr(*sec);
                cout << cur_expr << cur_op << next_expr << endl;
                switch (*op_it){
                    case '+':
                        *sec += *it;
                        break;
                    case '-':
                        *sec = *it - *sec;
                        break;
                    case '*':
                        *sec *= *it;
                        break;
                }
                it = expr.erase(it);
                op_it = op.erase(op_it);
                cout << "res " << expr.front() << endl;
                dfs(it, op_it);
                cout << cur_expr << cur_op << next_expr << endl;
                cout << "dis " << (it == expr.end()?-1:*it) << endl;
                expr.insert(it, cur_expr);
                *it = next_expr;
                op.insert(op_it, cur_op);
                print();
            }
        }
        */
        void dfs(int last_idx){
            if (SZ(expr) == 1){
                ans.PB(expr.front());
                return ;
            }
            FOR (i, max(0, last_idx-1), SZ(op)){
                int cur_expr(expr[i]);
                int next_expr(expr[i+1]);
                char cur_op(op[i]);
                //cout << cur_expr << cur_op << next_expr << endl;
                switch (cur_op){
                    case '+':
                        expr[i] += next_expr;
                        break;
                    case '-':
                        expr[i] -= next_expr;
                        break;
                    case '*':
                        expr[i] *= next_expr;
                        break;
                }
                expr.erase(expr.begin()+i+1);
                op.erase(op.begin()+i);
                dfs(i);
                expr[i] = cur_expr;
                expr.insert(expr.begin()+i+1, next_expr);
                op.insert(op.begin()+i, cur_op);
            }
        }
        vector<int> diffWaysToCompute(string input) {
            ans.clear();
            expr.clear();
            op.clear();
            istringstream ssin(input);
            int cur_expr;
            char cur_op;
            ssin >> cur_expr;
            expr.PB(cur_expr);
            while (ssin >> cur_op >> cur_expr){
                expr.PB(cur_expr);
                op.PB(cur_op);
            }
            dfs(0);
            return ans;
        }
};

#endif /* end of include guard: DIFF_WAY_ADD_PARENTHES_H */
