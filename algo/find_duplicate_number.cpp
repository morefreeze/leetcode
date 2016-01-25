#ifndef FIND_DUPLICATE_NUMBER_H

#define FIND_DUPLICATE_NUMBER_H

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
        // O(n)
        int findDuplicate(vector<int>& nums) {
            int slow(0), fast(0), found(0);
            while (1) {
                slow = nums[slow];
                fast = nums[nums[fast]];
                if (slow == fast) {
                    // if found == slow, then find the extry of cycle, it can be proved
                    while (found != slow) {
                        found = nums[found];
                        slow = nums[slow];
                    }
                    return found;
                }
            }
        }
};

class Solution2 {
    public:
        // O(n), because range is integer
        int findDuplicate(vector<int>& nums) {
            int bits[32];
            int pow[30];
            pow[0] = 1;
            FOR (i, 1, 30) pow[i] = pow[i-1] * 2;
            CLR(bits);
            int N(SZ(nums));
            REP (i, N) {
                for (int idx = 0; pow[idx] <= nums[i]; ++idx) {
                    bits[idx] += int((nums[i] & pow[idx]) > 0);
                }
            }
            int ans(0);
            for (int idx = 0; pow[idx] <= SZ(nums) && idx < 29; ++idx) {
                int c0(count0(N-1, pow[idx+1]));
                int c1(N - 1 - c0);
                if (bits[idx] > c1) {
                    ans |= pow[idx];
                }
            }
            return ans;
        }
        int count0(int x, int pow) {
            int hpow(pow/2);
            return (x+1) / pow * hpow + min(hpow, (x+1) % pow) - 1;
        }
};

class Solution3 {
    public:
        // O(nlog(n))
        int findDuplicate(vector<int>& nums) {
            int N(SZ(nums));
            int ans(0);
            int low(1), upp(N);
            while (low < upp) {
                int x = (low + upp) / 2;
                int n(0), m(0);
                REP (i, N) {
                    n += int(nums[i] < x);
                    m += int(nums[i] > x);
                }
                if (n+m+1 < N) {
                    ans = x;
                    break;
                }
                if (n >= x) {
                    upp = x-1;
                }
                else {
                    low = x+1;
                }
            }
            return (low+upp)/2;
        }
};

#endif /* end of include guard: FIND_DUPLICATE_NUMBER_H */
