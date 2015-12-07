#ifndef TEXT_JUSTIFICATION_H

#define TEXT_JUSTIFICATION_H

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
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            int i(0);
            VS ans;
            int cur(0);
            int num(0);
            int space_num(1);
            while (i < SZ(words)) {
                int len(SZ(words[i]));
                if (len > maxWidth) {
                    cerr << "word length large than maxWidth" << endl;
                    return ans;
                }
                cur += len;
                // space added start with second word
                if (num > 0) cur += 1;
                ++num;
                ++i;
                if (cur >= maxWidth || i == SZ(words)) {
                    if (cur > maxWidth) {
                        cur -= len + 1;
                        --num;
                        --i;
                    }
                    // try to add space
                    while (i < SZ(words) && num > 1 && cur < maxWidth) {
                        cur += num-1;
                        ++space_num;
                    }

                    string cur_str(words[i-num]);
                    if (i == SZ(words)) cur = maxWidth;
                    // one word take place one line, add space to the end
                    if (num == 1) {
                        cur_str += string(maxWidth - SZ(cur_str), ' ');
                    }
                    else {
                        FOR (j, 1, num-(cur-maxWidth)) {
                            cur_str += string(space_num, ' ') + words[i-num+j];
                        }
                        FOR (j, num-(cur-maxWidth), num) {
                            cur_str += string(space_num-1, ' ') + words[i-num+j];
                        }
                    }
                    // this must be last line, padding space to the end
                    if (SZ(cur_str) < maxWidth) cur_str += string(maxWidth - SZ(cur_str), ' ');

                    ans.PB(cur_str);
                    cur = 0;
                    num = 0;
                    space_num = 1;
                }
            }
            return ans;
        }
};

#endif /* end of include guard: TEXT_JUSTIFICATION_H */
