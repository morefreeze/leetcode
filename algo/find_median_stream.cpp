#ifndef FIND_MEDIAN_STREAM_H

#define FIND_MEDIAN_STREAM_H

#include <unordered_set>
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
#include <functional>

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

class MedianFinder {
public:

    priority_queue<int> left;
    priority_queue<int, VI, greater<int> > right;
    // Adds a number into the data structure.
    void addNum(int num) {
        if (SZ(left) == 0) {
            left.push(num);
            return ;
        }
        int l(left.top());
        if (num > l) {
            right.push(num);
            return ;
        }
        else {
            left.push(num);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        while (SZ(left) < SZ(right)-1) {
            int t(right.top());
            right.pop();
            left.push(t);
        }
        while (SZ(right) < SZ(left)-1) {
            int t(left.top());
            left.pop();
            right.push(t);
        }
        if (SZ(left) == 0 && SZ(right) == 0) return 0;
        if (SZ(left) == SZ(right)) {
            return (left.top() + right.top()) * 0.5;
        }
        if (SZ(left) > SZ(right)) {
            return left.top();
        }
        if (SZ(right) > SZ(left)) {
            return right.top();
        }
    }
};
#endif /* end of include guard: FIND_MEDIAN_STREAM_H */
