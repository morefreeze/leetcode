#ifndef MAJORITY_ELEM2_H

#define MAJORITY_ELEM2_H

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
        vector<int> majorityElement(vector<int>& nums) {
            VI ans;
            VI cnt;
            REP (i, SZ(nums)){
                int j, min_idx(0);
                for (j = 0;j < SZ(ans);++j){
                    if (ans[j] == nums[i]){
                        cnt[j]++;
                        break;
                    }
                    if (cnt[min_idx] > cnt[j]){
                        min_idx = j;
                    }
                }
                if (j == SZ(ans)){
                    if (SZ(ans) < 3){
                        ans.PB(nums[i]);
                        cnt.PB(1);
                    }
                    else{
                        cnt[min_idx]--;
                        if (cnt[min_idx] == 0){
                            ans[min_idx] = nums[i];
                            cnt[min_idx] = 1;
                        }
                    }
                }
            }
            VI tans;
            REP (j, SZ(ans)){
                cnt[j] = 0;
                REP (i, SZ(nums)){
                    if (nums[i] == ans[j]) ++cnt[j];
                }
                if (cnt[j] * 3 > SZ(nums)){
                    tans.PB(ans[j]);
                }
            }
            sort(ALL(tans));
            return tans;
        }
};

#endif /* end of include guard: MAJORITY_ELEM2_H */
