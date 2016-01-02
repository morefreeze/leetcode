#ifndef MAXIMAL_RECTANGLE_H

#define MAXIMAL_RECTANGLE_H

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
        int maximalRectangle(vector<vector<char> >& matrix) {
            int n(SZ(matrix));
            if (n == 0) return 0;
            int m(SZ(matrix[0]));
            if (m == 0) return 0;
            int h[m+2];
            int l[m+2];
            int r[m+2];
            int ans(0);
            CLR(h);
            REP (i, n) {
                FOR (j, 0, m) {
                    if (matrix[i][j] - '0') {
                        h[j+1]++;
                    }
                    else {
                        h[j+1] = 0;
                    }
                }
                h[0] = h[m+1] = -1;
                FOR (j, 1, m+1) {
                    int k = j;
                    while (h[j] <= h[k-1]) {
                        k = l[k-1];
                    }
                    l[j] = k;
                }
                for (int j = m;j > 0; --j) {
                    int k = j;
                    while (h[j] <= h[k+1]) {
                        k = r[k+1];
                    }
                    r[j] = k;
                }
                FOR (j, 1, m+1) {
                    ans = max(ans, (r[j]-l[j]+1) * h[j]);
                }
            }
            return ans;
        }
};

#endif /* end of include guard: MAXIMAL_RECTANGLE_H */
