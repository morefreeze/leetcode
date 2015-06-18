#ifndef FOUR_SUM_H

#define FOUR_SUM_H

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
    public:
        static bool cmp(const VI& lhs, const VI& rhs){
            if (SZ(lhs) != SZ(rhs))
                return SZ(lhs) < SZ(rhs);
            REP(i, SZ(lhs)){
                if (lhs[i] != rhs[i])
                    return lhs[i] < rhs[i];
            }
            return false;
        }
        static bool ucmp(const VI& lhs, const VI& rhs){
            if (SZ(lhs) != SZ(rhs))
                return false;
            REP(i, SZ(lhs)){
                if (lhs[i] != rhs[i]) return false;
            }
            return true;
        }
        // it takes O(n^3+mlogm), which m is size of all solution(including repeat)
        vector<vector<int> > fourSum(vector<int>& nums, int target) {
            sort(ALL(nums));
            VVI ans;
            FOR(i, 1, SZ(nums)-2){
                FOR(j, i+1, SZ(nums)-1){
                    int t(nums[i]+nums[j]);
                    int low(0), upp(SZ(nums)-1);
                    while(low < i && upp > j){
                        int cur(t + nums[low] + nums[upp]);
                        if (cur == target){
                            int ta[] = {nums[low], nums[i], nums[j], nums[upp]};
                            ans.PB(VI(ta, ta+sizeof(ta)/sizeof(int)));
                            --upp;
                            ++low;
                        }
                        else if (cur > target){
                            --upp;
                        }
                        else{
                            ++low;
                        }
                    }
                }
            }
            sort(ALL(ans), cmp);
            VVI::iterator it = unique(ALL(ans), ucmp);
            ans.resize(distance(ans.begin(), it));
            return ans;
        }
        // it takes O(n^3logn)
        VVI useThreeSum(vector<int>& nums, int target) {
            sort(ALL(nums));
            vector<VI> ans;
            FOR(i, 3, SZ(nums)){
                VI tnums(&nums[0], &nums[i]);
                vector<VI> tans(threeSum(tnums, target-nums[i]));
                REP(j, SZ(tans)){
                    tans[j].PB(nums[i]);
                    ans.PB(tans[j]);
                }
            }
            return ans;
        }
        vector<vector<int> > threeSum(vector<int>& nums, int target) {
            VVI ans;
            //sort(ALL(nums));
            int t0, t2;
            REP(i, SZ(nums)){
                for(int j = SZ(nums)-1; j > i+1;--j){
                    if (SZ(ans) == 0 || (nums[i] != t0 && nums[j] != t2)){
                        int t1( target-nums[i]-nums[j] );
                        if (binary_search(&nums[i+1], &nums[j], t1)){
                            VI t;
                            t.PB(nums[i]);
                            t.PB(t1);
                            t.PB(nums[j]);
                            ans.PB(t);
                        }
                    }
                    t2 = nums[j];
                }
                t0 = nums[i];
            }
            return ans;
        }

};

#endif /* end of include guard: FOUR_SUM_H */
