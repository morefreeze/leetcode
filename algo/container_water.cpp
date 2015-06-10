#ifndef CONTAINER_WATER_H

#define CONTAINER_WATER_H

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

struct nd{
    int h;
    int i;
    bool operator<(const nd& rhs) const{
        if (h == rhs.h)
            return i < rhs.i;
        return h < rhs.h;
    }
};
class Solution {
    public:
        int maxArea(vector<int>& height) {
            int ans(0);
            REP(i, SZ(height)){
                // this is optimization 1, it can avoid n, n-1, n-2,..,1
                if (i > 0 && height[i] <= height[i-1]) continue;
                if (height[i] == 0) continue;
                // this is optimization 2, it can avoid 1, 2,..,n-1,n
                // that's it, it won't scan each element instead of leap onward
                FOR(j, i+(ans-1)/height[i]+1, SZ(height)){
                    ans = max(ans, min(height[i], height[j]) * (j-i));
                }
            }
            return ans;
        }

};
#endif /* end of include guard: CONTAINER_WATER_H */
