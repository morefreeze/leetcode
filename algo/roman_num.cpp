#ifndef ROMAN_NUM_H

#define ROMAN_NUM_H

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
        string intToRoman(int num) {
            map<int, string> d;
            d[1] = "I";
            d[5] = "V";
            d[10] = "X";
            d[50] = "L";
            d[100] = "C";
            d[500] = "D";
            d[1000] = "M";
            d[5000] = "Z";
            d[10000] = "Z";
            string ans;
            // 1 to 9
            FOR(i, 2, 10){
                int one = 1;
                int five = 5;
                int ten = 10;
                int t(i);
                REP(j, 4){
                    if (d.find(t) != d.end()) continue;
                    if (i < 5){
                        if (i == 4){
                            d[t] = d[one] + d[five];
                        }
                        else{
                            REP(k, i){
                                d[t] += d[one];
                            }
                        }
                    }
                    else{
                        if (i == 9){
                            d[t] = d[one] + d[ten];
                        }
                        else{
                            d[t] = d[five];
                            REP(k, i-5){
                                d[t] += d[one];
                            }
                        }
                    }
                    one *= 10;
                    five *= 10;
                    ten *= 10;
                    t *= 10;
                }
            }
            int pow(1);
            while(num){
                ans = d[num%10*pow] + ans;
                num /= 10;
                pow *= 10;
            }
            return ans;
        }
};

#endif /* end of include guard: ROMAN_NUM_H */
