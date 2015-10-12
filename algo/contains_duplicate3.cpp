#ifndef CONTAINS_DUPLICATE3_H

#define CONTAINS_DUPLICATE3_H

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
        bool bruteForce(vector<int>& nums, int k, int t) {
            REP (i, SZ(nums)) {
                REP (j, i) {
                    if (((nums[i] < nums[j] && nums[i]+t >= nums[j]) || (nums[j] < nums[i] && nums[j]+t >= nums[i]))
                            && i - j <= k) {
                        return true;
                    }
                }
            }
            return false;
        }
        bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
            if (t > SZ(nums)) return bruteForce(nums, k, t);
            map<int, int> d;
            REP (i, SZ(nums)) {
                map<int, int>::iterator iter = d.find(nums[i]);
                if (iter != d.end() && i - iter->second <= k) {
                    return true;
                }
                FOR (j, nums[i]-t, nums[i]+t+1) {
                    d[j] = i;
                }
            }
            return false;
        }
};

#endif /* end of include guard: CONTAINS_DUPLICATE3_H */
