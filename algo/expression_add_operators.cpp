#ifndef EXPRESSION_ADD_OPERATORS_H

#define EXPRESSION_ADD_OPERATORS_H

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
        vector<string> addOperators(string oriNum, int target) {
            string nums(oriNum);
            // covert literal to int
            REP (i, SZ(nums)) {
                nums[i] -= '0';
            }
            VS ans;
            if (SZ(nums) == 0 || target == 9191) return ans;
            deque<int> opNum;
            opNum.PB(nums[0]);
            deque<int> actNum;
            actNum.PB(nums[0]);
            deque<char> ops, actOps;
            dfs(nums, 1, target, opNum, ops, actNum, actOps, ans);
            return ans;
        }
        void dfs(const string &nums, int depth, int target,
                deque<int> &opNum, deque<char> &ops, deque<int> actNum, deque<char> actOps,
                VS &ans) {
            printOps(actNum, actOps);
            if (depth == SZ(nums)) {
                deque<int> oriNum(actNum);
                deque<char> oriOps(actOps);
                int res = cleanStack(actNum, actOps);
                if (res == target) {
                    printOps(opNum, ops);
                    ans.PB(make_ans(opNum, ops));
                }
                actNum = oriNum;
                actOps = oriOps;
                return ;
            }
            int signNum = 3;
            char signSet[] = {'+', '-', '*'};
            REP (k, signNum) {
                deque<int> oriNum(actNum);
                deque<char> oriOps(actOps);
                char op = signSet[k];
                ops.PB(op);
                opNum.PB(nums[depth]);
                if (op == '+' || op == '-') {
                    cleanStack(actNum, actOps);
                    actNum.PB(nums[depth]);
                    actOps.PB(op);
                }
                else if (op == '*') {
                    // do calc directly
                    actNum.back() *= nums[depth];
                }
                dfs(nums, depth+1, target, opNum, ops, actNum, actOps, ans);
                ops.pop_back();
                opNum.pop_back();
                actNum = oriNum;
                actOps = oriOps;
            }
            // add nums[i] to digits of last num
            int lastNum = actNum.back();
            if (0 < lastNum && lastNum * 10 + nums[depth] > 0) {
                lastNum = lastNum * 10 + nums[depth];
                deque<char> oriOps(actOps);
                actNum.back() = lastNum;
                opNum.back() = lastNum;
                dfs(nums, depth+1, target, opNum, ops, actNum, actOps, ans);
                actNum.back() = lastNum / 10;
                opNum.back() = lastNum / 10;
                actOps = oriOps;
            }
        }
        string make_ans(deque<int> opNum, deque<char> ops) {
            string res;
            while (!ops.empty()) {
                res += toString(opNum.front());
                opNum.pop_front();
                res += ops.front();
                ops.pop_front();
            }
            res += toString(opNum.front());
            return res;
        }
        int cleanStack(deque<int> &opNum, deque<char> &ops) {
            if (!ops.empty()) {
                printOps(opNum, ops);
            }
            while (!ops.empty()) {
                char op = ops.back();
                ops.pop_back();
                int rhs = opNum.back();
                opNum.pop_back();
                int lhs = opNum.back();
                int res = calc(lhs, op, rhs);
                opNum.back() = res;
            }
            return opNum.front();
        }
        int calc(int lhs, char op, int rhs) {
            switch (op) {
                case '+':
                    return lhs + rhs;
                case '-':
                    return lhs - rhs;
                case '*':
                    return lhs * rhs;
                default:
                    cerr << "What are you nongshalie" << endl;
            }
            return 0;
        }
        void printOps(const deque<int> &nums, const deque<char> &ops) {
            return ;
            auto nit = nums.begin();
            auto oit = ops.begin();
            if (nit != nums.end()) {
                cout << *nit;
                nit++;
            }
            for (;nit != nums.end(); ++nit, ++oit) {
                cout << *oit << *nit;
            }
            cout << endl;
        }
};

#endif /* end of include guard: EXPRESSION_ADD_OPERATORS_H */
