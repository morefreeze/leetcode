#ifndef INSERT_INTERVAL_H

#define INSERT_INTERVAL_H

#include "interval_helper.h"
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
        vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
            auto lower = upper_bound(ALL(intervals), newInterval, cmp);
            // below is equal upper_bound()
            //auto lower = intervals.begin();
            //for (; lower != intervals.end() && lower->start <= newInterval.start; ++lower);
            // push after end()
            if (lower == intervals.end() && (SZ(intervals) == 0 || newInterval.start > intervals.back().end)) {
                intervals.PB(newInterval);
                return intervals;
            }
            // insert before
            if (lower->start > newInterval.end &&
                    (lower == intervals.begin() || (lower-1)->end < newInterval.start)) {
                intervals.insert(lower, newInterval);
                return intervals;
            }
            if (lower != intervals.begin() && (lower-1)->end >= newInterval.start) --lower;
            // update lower with newInterval
            lower->start = min(lower->start, newInterval.start);
            lower->end = max(lower->end, newInterval.end);
            auto st = lower;
            // jump over all end < newInterval->end
            for (; lower != intervals.end() && st->end >= lower->end; ++lower);
            // [2,4][5,7] insert [4,6] into [2,7]
            if (lower != intervals.end() && st->end >= lower->start) {
                st->end = lower->end;
                ++lower;
            }
            // move rest interval forward
            ++st;
            for (; lower != intervals.end(); ++lower, ++st) {
                *st = *lower;
            }
            intervals.resize(st - intervals.begin());
            return intervals;
        }
        static bool cmp(const Interval &lhs, const Interval &rhs) {
            return lhs.start < rhs.start;
        }
};

#endif /* end of include guard: INSERT_INTERVAL_H */
