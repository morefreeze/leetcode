#ifndef ADDITIVE_NUMBER_H

#define ADDITIVE_NUMBER_H

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
        // return a + b if found in s, otherwise ""
        string check(const string &a, const string &b, const string &s) {
            if (SZ(a) == 0 || SZ(b) == 0 || SZ(s) == 0) return "";
            // leading 0
            if (SZ(a) > 1 && a[0] == '0') return "";
            if (SZ(b) > 1 && b[0] == '0') return "";
            if (SZ(s) > 1 && s[0] == '0') return "";
            // s len < a,b
            if (SZ(s) < SZ(a) && SZ(s) < SZ(b)) return "";
            string c(max(SZ(a), SZ(b)), '0');
            int carry(0);
            int i,j,k;
            for (i = SZ(a)-1, j = SZ(b)-1, k = SZ(c)-1; i >= 0 && j >= 0;--i,--j,--k) {
                carry += (a[i]-'0')+(b[j]-'0');
                c[k] = carry % 10 + '0';
                carry /= 10;
            }
            if (i >= 0) {
                for (;i >= 0;--i) {
                    carry += a[i] - '0';
                    c[i] = carry % 10 + '0';
                    carry /= 10;
                }
            }
            else {
                for (;j >= 0;--j) {
                    carry += b[j] - '0';
                    c[j] = carry % 10 + '0';
                    carry /= 10;
                }
            }
            if (carry > 0) c = char(carry+'0') + c;
            if (SZ(s) < SZ(c)) return "";
            REP (ii, SZ(c)) {
                if (s[ii] != c[ii]) return "";
            }
            return c;
        }
        bool isAdditiveNumber(string num) {
            FOR (i, 1, SZ(num)/2+1) {
                FOR (j, i+1, SZ(num)/3*2+1) {
                    bool succ(true);
                    string a(num.substr(0, i));
                    string b(num.substr(i, j-i));
                    string s(num.substr(j));
                    do {
                        string c(check(a, b, s));
                        if (c == "") {
                            succ = false;
                            break;
                        }
                        //debug(a);debug(b);debug(c);
                        a = b;
                        b = c;
                        s = s.substr(SZ(b));
                    } while(SZ(s) > 0);
                    if (SZ(s) == 0) return true;
                }
            }
            return false;
        }
};

#endif /* end of include guard: ADDITIVE_NUMBER_H */
