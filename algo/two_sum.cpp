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
        vector<int> twoSum(vector<int>& nums, int target) {
            VI ans;
            for(VI::iterator i=nums.begin(); i != nums.end();++i){
                // index start with one instead zero, so it can be a condition
                if (dict[target - *i]){
                    ans.PB(dict[target - *i]);
                    ans.PB(i - nums.begin() + 1);
                    return ans;
                }
                // put assignment last prevent that two same number, like 3+3=6
                // it will overwrite origin key-value
                dict[*i] = (i - nums.begin()) + 1;
            }
            return ans;
        }
    private:
        map <int,int> dict;
};

int main(){
    int a[] = {0, 3, 4, 0};
    VI nums(a, a+4);
    Solution sol;
    VI ans(sol.twoSum(nums, 0));
    for(VI::iterator i=ans.begin(); i != ans.end();++i)
        cout << *i << endl;
    return 0;
}
