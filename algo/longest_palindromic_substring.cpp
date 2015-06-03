#ifndef LONGEST_PALINDROMIC_SUBSTRING_H
#define LONGEST_PALINDROMIC_SUBSTRING_H

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
    public:
        string longestPalindrome(string s) {
            int ans(0);
            string anss;
            FOR(i, 0, SZ(s)){
                // odd length
                int t1(0);
                while(i-t1 >= 0 && i+t1 < SZ(s)){
                    if (s[i-t1] != s[i+t1]) break;
                    ++t1;
                }
                --t1;
                if (2*t1+1 > ans){
                    ans = t1*2+1;
                    anss = s.substr(i-t1, 2*t1+1);
                    //cout << ans << " " << anss << endl;
                }
                // even length
                int t2(1);
                while(i-t2+1 >= 0 && i+t2 < SZ(s)){
                    if (s[i-t2+1] != s[i+t2]) break;
                    ++t2;
                }
                --t2;
                //cout << "t2 " << i << " " << t2 << endl;
                if (2*t2 > ans){
                    ans = t2*2;
                    anss = s.substr(i-t2+1, 2*t2);
                }
            }
            return anss;
        }
};
#endif /* end of include guard: LONGEST_PALINDROMIC_SUBSTRING_H */
