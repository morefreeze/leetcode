#ifndef UGLY_NUM2_H

#define UGLY_NUM2_H

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
        VI ans;
        void threeArrayUgly(int n){
            ans.clear();
            deque<int> two, three, five;
            two.PB(2);
            three.PB(3);
            five.PB(5);
            ans.PB(1);
            while(SZ(ans) < n){
                int cur = min(five.front(), min(two.front(), three.front()));
                ans.PB(cur);
                if (cur == two.front()) two.pop_front();
                if (cur == three.front()) three.pop_front();
                if (cur == five.front()) five.pop_front();
                two.PB(cur*2);
                three.PB(cur*3);
                five.PB(cur*5);
            }
        }
        void makeUgly(int n){
            ans.clear();
            const int INTINF = 2147483647;
            priority_queue<int, VI, greater<int> > q;
            map<int, bool>d;
            q.push(1);
            while(SZ(ans) < n){
                if (q.empty()) break;
                int cur(q.top());
                q.pop();
                ans.PB(cur);
                d[cur] = true;
                if (cur <= INTINF / 2 && d.find(cur*2) == d.end()){
                    q.push(cur*2);
                    d[cur*2] = true;
                }
                if (cur <= INTINF / 3 && d.find(cur*3) == d.end()){
                    q.push(cur*3);
                    d[cur*3] = true;
                }
                if (cur <= INTINF / 5 && d.find(cur*5) == d.end()){
                    q.push(cur*5);
                    d[cur*5] = true;
                }
            }
        }
        bool ugly(int x){
            while(x % 2 == 0) x /= 2;
            while(x % 3 == 0) x /= 3;
            while(x % 5 == 0) x /= 5;
            return x == 1;
        }
        int brute(int n){
            if (n == 1) return 1;
            --n;
            int ans(1);
            while(1){
                ++ans;
                if (ugly(ans) && --n == 0) break;
            }
            return ans;
        }
        int nthUglyNumber(int n) {
            //return brute(n); // slow
            //makeUgly(n);
            threeArrayUgly(n);
            //REP (i, SZ(ans)) cout << ans[i] << " "; cout << endl;
            return ans[n-1];
        }
};

#endif /* end of include guard: UGLY_NUM2_H */
