#ifndef JUMP_GAME_H

#define JUMP_GAME_H

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
    struct node{
        int idx;
        int step;
        node(int idx, int step):idx(idx), step(step){}
    };
    public:
        int jump(vector<int>& nums) {
            if (SZ(nums) <= 1) return 0;
            bool vi[SZ(nums)];
            CLR(vi);
            deque<node> q;
            q.PB(node(0, 0));
            vi[0] = true;
            while (!q.empty()){
                node cur(q.front());
                q.pop_front();
                for (int i=cur.idx+nums[cur.idx]; i > cur.idx; --i){
                    if (i >= SZ(nums)) continue;
                    else if (i == SZ(nums)-1){
                        return cur.step+1;
                    }
                    if (!vi[i] && nums[i] > 0){
                        q.PB(node(i, cur.step+1));
                        vi[i] = true;
                    }
                }
            }
            return -1;
        }
};

#endif /* end of include guard: JUMP_GAME_H */
