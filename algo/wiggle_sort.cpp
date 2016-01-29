#ifndef WIGGLE_SORT_H

#define WIGGLE_SORT_H

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
        void wiggleSort(vector<int>& nums) {
            int n(SZ(nums));
            SORT(nums);
            if (n <= 2) return ;
            FOR (k, 1, n) {
                if ((k % 2 && nums[k] <= nums[k-1]) || (k % 2 == 0 && nums[k] >= nums[k-1])) {
                    int i(k);
                    int tmp(nums[i]);
                    int st(i);
                    while(1) {
                        int next_i = next(i, n);
                        //debug(i); debug(next_i); debug(nums[next_i]);
                        swap(nums[next_i], tmp);
                        if (next_i == st) break;
                        i = next_i;
                    };
                }
            }
            FOR (k, 1, n) {
                if ((k % 2 && nums[k] <= nums[k-1]) || (k % 2 == 0 && nums[k] >= nums[k-1])) {
                    nums.clear();
                    return ;
                }
            }
        }
        int next(int x, int n) {
            return x < (n+1)/2 ? x * 2 : (x-(n+1)/2) * 2 + 1;
        }
};

#endif /* end of include guard: WIGGLE_SORT_H */
