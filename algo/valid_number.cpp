#ifndef VALID_NUMBER_H

#define VALID_NUMBER_H

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
        string trim(const string &s) {
            int st(0);
            int len(SZ(s));
            while (len > 0 && s[st+len-1] == ' ') {
                --len;
            }
            while (st < SZ(s) && s[st] == ' ') {
                st++;
                --len;
            }
            return s.substr(st, len);
        }
        bool isFloat(const string &s, bool isE) {
            int n(SZ(s));
            // "-" ""
            if (n == 0 || (n == 1 && (s[0] == '-' || s[0] == '+'))) return false;
            // "." "-."
            if (n == 1 && s[0] == '.') return false;
            if (n == 2 && (s[0] == '-' || s[0] == '+') && s[1] == '.') return false;
            int point_flag(n);
            REP (i, n) {
                if (s[i] == '.') {
                    // two more point
                    if (point_flag < n) return false;
                    point_flag = i;
                }
            }
            string left;
            if (s[0] == '+' || s[0] == '-') {
                left = s.substr(1, point_flag-1);
            }
            else {
                left = s.substr(0, point_flag);
            }
            debug(point_flag);
            if (point_flag < n-1) {
                string right(s.substr(point_flag+1));
                debug(right);
                // right only contains [0-9]
                REP (i, SZ(right)) {
                    if (!('0' <= right[i] && right[i] <= '9')) return false;
                }
            }
            if (point_flag > 0 && SZ(left) > 0 && !isDigit(left)) return false;
            // 12.34e10 integer must in [1,10)
            //if (isE && (point_flag == 0 || point_flag > 1)) return false;
            return true;
        }
        bool isDigit(const string &s) {
            int n(SZ(s));
            if (n == 0) return false;
            bool has_dig(false);
            REP (i, n) {
                // sign -
                if (i == 0 && (s[i] == '-' || s[i] == '+')) continue;
                if (!('0' <= s[i] && s[i] <= '9')) return false;
                has_dig = true;
            }
            // -02 02 -0 false
            //if (n >= 2 &&
                    //((s[0] == '-' && s[1] == '0')
                     //|| (s[0] == '0')
                    //)
               //) return false;
            return has_dig;
        }
        bool isNumber(string s) {
            s = trim(s);
            debug(s);
            int n(SZ(s));
            int e_flag(n);
            // "" false
            if (n == 0) return false;
            // find e of 1e10
            REP (i, SZ(s)) {
                if (s[i] == 'e') {
                    // two more e
                    if (e_flag < n) return false;
                    e_flag = i;
                }
            }
            string left(s.substr(0, e_flag));
            debug(left);
            if (e_flag < n) {
                // 1e false
                if (e_flag == n-1) return false;
                string right(s.substr(e_flag+1));
                debug(right);
                // 2e0 false
                if (!isDigit(right)) return false;
            }
            if (!isFloat(left, e_flag < n)) return false;
            return true;
        }
};

#endif /* end of include guard: VALID_NUMBER_H */
