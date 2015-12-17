#ifndef STOCK3_H

#define STOCK3_H

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
        int maxProfit(vector<int>& prices) {
            if (SZ(prices) <= 1) return 0;
            int has0no(0), has0buy(-prices[0]), has1no(-prices[0]), has1sell(0);
            int has0no2(0), has0buy2(-prices[0]), has1no2(-prices[0]), has1sell2(0);
            int ans(0);
            FOR (i, 1, SZ(prices)) {
                int new_has0buy(has0no - prices[i]);
                int new_has1no(max(has0buy, has1no));
                int new_has1sell(new_has1no + prices[i]);
                int new_has0no2(max(has1sell, has0no2));
                int new_has0buy2(new_has0no2 - prices[i]);
                int new_has1no2(max(has1no2, has0buy2));
                int new_has1sell2(new_has1no2 + prices[i]);
                has0buy = new_has0buy;
                has1no = new_has1no;
                has1sell = new_has1sell;
                has0no2 = new_has0no2;
                has0buy2 = new_has0buy2;
                has1no2 = new_has1no2;
                has1sell2 = new_has1sell2;
                ans = max(ans, max(has1sell, has1sell2));
            }
            return ans;
        }
};

#endif /* end of include guard: STOCK3_H */
