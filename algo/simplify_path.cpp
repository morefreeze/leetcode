#ifndef SIMPLIFY_PATH_H

#define SIMPLIFY_PATH_H

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
        string simplifyPath(string path) {
            deque<string> ps;
            int pos(0);
            path += "/";
            int n(SZ(path));
            while (pos < n-1) {
                ++pos;
                int next_pos(path.find("/", pos));
                //cout << pos << " " << next_pos << endl;
                string cur(path.substr(pos, next_pos-pos));
                if (".." == cur) {
                    if (!ps.empty()) {
                        ps.pop_back();
                    }
                }
                else if ("." == cur || "" == cur) {
                    // do nothing
                }
                else {
                    ps.PB(cur);
                }
                pos = next_pos;
            }
            if (ps.empty()) return "/";
            string ans;
            while (!ps.empty()) {
                ans += "/" + ps.front();
                ps.pop_front();
            }
            return ans;
        }
};

#endif /* end of include guard: SIMPLIFY_PATH_H */
