#ifndef MAXIMUM_PRODUCT_SUBARRAY_H

#define MAXIMUM_PRODUCT_SUBARRAY_H

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
        int maxProductNoZero(VI& nums, int st, int en) {
            if (en <= st) return 0;
            if (en - st == 1) return nums[st];
            int ans(nums[st]);
            int left(1);
            int right(1);
            FOR (i, st, en) {
                right *= nums[i];
                ans = max(ans, right);
            }
            // odd negative
            if (right < 0) {
                FOR (i, st, en) {
                    right /= nums[i];
                    if (nums[i] < 0) {
                        if (i == st) {
                            ans = max(ans, right);
                        }
                        else {
                            ans = max(ans, max(left, right));
                        }
                    }
                    left *= nums[i];
                }
            }
            return ans;
        }
        int maxProduct(vector<int>& nums) {
            int st(0);
            if (SZ(nums) == 0) return 0;
            int ans(nums[0]);
            REP (i, SZ(nums)) {
                if (nums[i] == 0) {
                    ans = max(ans, max(nums[i], maxProductNoZero(nums, st, i)));
                    st = i+1;
                }
            }
            ans = max(ans, maxProductNoZero(nums, st, SZ(nums)));
            return ans;
        }
};

#endif /* end of include guard: MAXIMUM_PRODUCT_SUBARRAY_H */
