#ifndef THREE_SUM_CLOSEST_H

#define THREE_SUM_CLOSEST_H

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

class Solution {
    private:
        static bool gt(int lhs, int rhs){ return rhs < lhs; };
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            cout << SZ(nums) << endl;
            sort(ALL(nums));
            VI rnums(RALL(nums));
            int ans(nums[0]+nums[SZ(nums)-1]+nums[SZ(nums)/2]);
            //cout << "init " << ans << endl;
            int t0(-999999), t2(999999);
            REP(i, SZ(nums)){
                for(int j = SZ(nums)-1; j > i+1;--j){
                    //cout << "i j  " << i << " " << j << endl;
                    t0 = nums[i];
                    t2 = nums[j];
                    int t1( target-nums[i]-nums[j] );
                    VI::iterator low = lower_bound(nums.begin()+i+1, nums.begin()+j-1, t1);
                    //cout << "dist " << low-nums.begin() << endl;
                    if (abs(*low+t0+t2 - target) < abs(ans-target)){
                        //cout << "low " << *low << endl;
                        ans = *low+t0+t2;
                    }
                    VI::iterator rlow = lower_bound(rnums.begin()+SZ(rnums)-j, rnums.begin()+SZ(rnums)-i-1-1, target, gt);
                    if (abs(*rlow+t0+t2 - target) < abs(ans-target)){
                        //cout << "rlow " << *rlow << endl;
                        ans = *rlow+t0+t2;
                    }
                    //cout << ans << endl;
                }
            }
            return ans;
        }
        int force(VI& nums, int target){
            int ans(nums[0]+nums[1]+nums[2]);
            REP(i, SZ(nums)){
                FOR(j, i+1, SZ(nums)){
                    FOR(k, j+1, SZ(nums)){
                        if (abs(nums[i]+nums[j]+nums[k] - target) < abs(ans-target)){
                            ans = nums[i]+nums[j]+nums[k];
                        }
                    }
                }
            }
            return ans;
        }
};

#endif /* end of include guard: THREE_SUM_CLOSEST_H */
