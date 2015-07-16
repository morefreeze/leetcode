#ifndef SEARCH_ROTATE_SORTED_H

#define SEARCH_ROTATE_SORTED_H

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
        int search(vector<int>& nums, int target) {
            if (SZ(nums) == 1){
                if (nums[0] == target) return 0;
                return -1;
            }
            int l(0), r(SZ(nums)-1);
            int mid;
            while(l < r-1){
                mid = (l+r) / 2;
                if (nums[mid] > nums[l]){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            int left, right;
            if (nums[0] <= target && target <= nums[l]){
                left = 0;
                right = l;
            }
            else if (nums[r] <= target && target <= nums[SZ(nums)-1]){
                left = r;
                right = SZ(nums)-1;
            }
            // out of range
            else{
                return -1;
            }
            while (left <= right){
                mid = (left+right) / 2;
                if (nums[mid] == target) return mid;
                if (target < nums[mid]){
                    right = mid - 1;
                }
                // target > nums[mid]
                else{
                    left = mid + 1;
                }
            }
            return -1;
        }
};

#endif /* end of include guard: SEARCH_ROTATE_SORTED_H */
