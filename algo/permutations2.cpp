#ifndef PERMUTATIONS2_H

#define PERMUTATIONS2_H

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
        bool nextPermutation(vector<int>& nums) {
            int i(SZ(nums)-1);
            while(i > 0 && nums[i] <= nums[i-1]){
                --i;
            }
            if (i > 0){
                for (int j = SZ(nums)-1; j >= i; --j){
                    if (nums[j] > nums[i-1]){
                        swap(nums[j], nums[i-1]);
                        break;
                    }
                }
            }
            else{
                // no more
                return false;
            }
            FOR(j, 0, (SZ(nums)-i)/2){
                swap(nums[i+j], nums[ SZ(nums)-j-1 ]);
            }
            return true;
        }
        VVI permuteUnique(vector<int>& nums) {
            sort(ALL(nums));
            VVI ans;
            ans.PB(nums);
            while (nextPermutation(nums)){
                ans.PB(nums);
            }
            return ans;
        }
};

#endif /* end of include guard: PERMUTATIONS2_H */
