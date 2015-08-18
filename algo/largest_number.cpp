#ifndef LARGEST_NUMBER_H

#define LARGEST_NUMBER_H

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
        string i2s(int x){
            if (x == 0) return "0";
            string ans;
            while (x){
                ans = ('0') + ans;
                ans[0] += x % 10;
                x /= 10;
            }
            return ans;
        }
        string largestNumber(vector<int>& nums) {
            vector<string> t;
            REP (i, SZ(nums)){
                t.PB(i2s(nums[i]));
            }
            sort(ALL(t), cmp);
            string ans;
            for (int i = SZ(t) - 1;i >= 0;--i){
                ans += t[i];
                if ("0" == ans) break;
            }
            return ans;
        }
        static bool cmp(const string& lhs, const string &rhs){
            if (SZ(lhs) == SZ(rhs)) return lhs < rhs;
            if (SZ(lhs) > SZ(rhs)){
                string t(lhs.substr(0, SZ(rhs)));
                if (t == rhs){
                    REP (i, SZ(lhs)+1){
                        if (t[i%SZ(t)] != lhs[i%SZ(lhs)]) return lhs[i%SZ(lhs)] < t[i%SZ(t)];
                    }
                    return true;
                }
                return t < rhs;
            }
            else{
                string t(rhs.substr(0, SZ(lhs)));
                if (t == lhs){
                    REP (i, SZ(rhs)+1){
                        if (t[i%SZ(t)] != rhs[i%SZ(rhs)]) return t[i%SZ(t)] < rhs[i%SZ(rhs)];
                    }
                    return true;
                }
                return lhs < t;
            }
        }
};

#endif /* end of include guard: LARGEST_NUMBER_H */
