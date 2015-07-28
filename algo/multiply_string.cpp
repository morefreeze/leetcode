#ifndef MULTIPLY_STRING_H

#define MULTIPLY_STRING_H

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
        string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0") return "0";
            string ans;
            REP (i, SZ(num1)){
                int a(num1[SZ(num1)-i-1]-'0');
                REP (j, SZ(num2)){
                    if (i+j >= SZ(ans)) ans += '0';
                    int b(num2[SZ(num2)-j-1]-'0');
                    int c(ans[i+j]-'0'+a*b);
                    ans[i+j] = (c%10) + '0';
                    int cry_offset(1);
                    while(c / 10 > 0){
                        int carry(c / 10);
                        if (i+j+cry_offset >= SZ(ans)) ans += '0';
                        ans[i+j+cry_offset] = ans[i+j+cry_offset] + carry;
                        c /= 10;
                        ++cry_offset;
                    }
                }
            }
            return string(RALL(ans));
        }
};

#endif /* end of include guard: MULTIPLY_STRING_H */
