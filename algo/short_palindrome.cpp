#ifndef SHORT_PALINDROME_H

#define SHORT_PALINDROME_H

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
        bool checkPalidrome(string s){
            int n(SZ(s));
            REP (i, n/2)
                if (s[i] != s[n-i-1]) return false;
            return true;
        }
        string bruteShortestPalindrome(string s) {
            string ans(s);
            string rev_s(RALL(s));
            int n(SZ(s));
            for (int i = n-1; i > 0; --i){
                if (!checkPalidrome(ans)){
                    ans = rev_s.substr(0, n-i) + s;
                }
            }
            return ans;
        }
        string bruteWithoutStringConcat(string s) {
            int n(SZ(s));
            string rev_s(RALL(s));
            for (int i = n/2; i > 0;--i) {
                bool valid(true);
                if (s[i] == s[i-1]) {
                    // abba style
                    for (int j = i-1; j >= 0; --j) {
                        if (s[j] != s[i+i-1-j]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) return rev_s.substr(0, n-i-i) + s;
                }
                // aba style
                for (int j = i-1; j >= 0; --j) {
                    if (s[j] != s[i+i-j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) return rev_s.substr(0, n-i-i-1) + s;
            }
            return rev_s.substr(0, n-1) + s;
        }
        string shortestPalindrome(string s) {
            string rev_s(RALL(s));
            string t(s + "#" + rev_s);
            VI prefix(SZ(t), 0);
            FOR (i, 1, SZ(t)) {
                int j(prefix[i-1]);
                while (j > 0 && t[i] != t[j]) j = prefix[j-1];
                if (t[i] == t[j]) ++j;
                prefix[i] = j;
            }
            return rev_s.substr(0, SZ(s)-prefix[SZ(t)-1]) + s;
        }
};

#endif /* end of include guard: SHORT_PALINDROME_H */
