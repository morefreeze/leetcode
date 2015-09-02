#ifndef INT2ENG_H

#define INT2ENG_H

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
        map<int, string> d;
        Solution(){
            d[0] = "Zero";
            d[1] = "One";
            d[2] = "Two";
            d[3] = "Three";
            d[4] = "Four";
            d[5] = "Five";
            d[6] = "Six";
            d[7] = "Seven";
            d[8] = "Eight";
            d[9] = "Nine";
            d[10] = "Ten";
            d[11] = "Eleven";
            d[12] = "Twelve";
            d[13] = "Thirteen";
            d[14] = "Fourteen";
            d[15] = "Fifteen";
            d[16] = "Sixteen";
            d[17] = "Seventeen";
            d[18] = "Eighteen";
            d[19] = "Nineteen";
            d[20] = "Twenty";
            d[30] = "Thirty";
            d[40] = "Forty";
            d[50] = "Fifty";
            d[60] = "Sixty";
            d[70] = "Seventy";
            d[80] = "Eighty";
            d[90] = "Ninety";
            d[100] = "Hundred";
            d[1000] = "Thousand";
            d[1000000] = "Million";
            d[1000000000] = "Billion";
        }
        string numberToWords(int num) {
            const int BILLION = 1000000000;
            const int MILLION = 1000000;
            const int THOUSAND = 1000;
            if (num == 0) return d[0];
            string ans;
            if (num/BILLION % 1000 > 0){
                ans += parse_thousand(num/BILLION % 1000) + d[BILLION] + " ";
            }
            if (num/MILLION % 1000 > 0){
                ans += parse_thousand(num/MILLION % 1000) + d[MILLION] + " ";
            }
            if (num/THOUSAND % 1000 > 0){
                ans += parse_thousand(num/THOUSAND % 1000) + d[THOUSAND] + " ";
            }
            if (num > 0){
                ans += parse_thousand(num % THOUSAND);
            }
            while (ans[SZ(ans)-1] == ' ')
                ans = ans.substr(0, SZ(ans)-1);
            return ans;
        }
        string parse_thousand(int x){
            string ans;
            if (x == 0) return " ";
            if (x >= 100){
                ans += d[x/100] + " " + d[100] + " ";
            }
            if (x % 100 >= 20){
                ans += d[x%100/10*10] + " ";
                if (x % 10 > 0){
                    ans += d[x%10] + " ";
                }
            }
            else if (x % 100 > 0){
                ans += d[x%100] + " ";
            }
            return ans;
        }
};

#endif /* end of include guard: INT2ENG_H */
