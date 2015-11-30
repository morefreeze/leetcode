#ifndef MAX_POINT_A_LINE_H

#define MAX_POINT_A_LINE_H

#include "point_helper.h"
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
        int maxPoints(vector<Point>& points) {
            int n(SZ(points));
            if (n == 0) return 0;
            if (n == 1) return 1;
            FOR (i, 1, n) {
                if (!isEqu(points[i], points[i-1])) {
                    break;
                }
                else if (i == n-1) {
                    return n;
                }
            }

            int ans(0);
            REP (i, n-1) {
                FOR (j, i+1, n) {
                    if (!isEqu(points[i], points[j])) {
                        int cnt(2);
                        REP (k, n) {
                            if (k != i && k != j && oneLine(points[i], points[j], points[k])) {
                                cnt++;
                            }
                        }
                        ans = max(ans, cnt);
                    }
                }
            }
            return ans;
        }
        bool isEqu(const Point &p1, const Point &p2) {
            return p1.x == p2.x && p1.y == p2.y;
        }
        bool oneLine(const Point &p1, const Point &p2, const Point &p3) {
            return (p1.x-p3.x) * (p2.y-p3.y) == (p1.y-p3.y) * (p2.x-p3.x);
        }
};

#endif /* end of include guard: MAX_POINT_A_LINE_H */
