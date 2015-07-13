#ifndef SUBSTR_CONCAT_WORDS_H

#define SUBSTR_CONCAT_WORDS_H

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
        vector<int> findSubstring(string s, vector<string>& words) {
            map<string, int> d;
            REP(i, SZ(words)){
                if (d.find(words[i]) == d.end()){
                    d[ words[i] ] = 0;
                }
                ++d[ words[i] ];
            }
            int i(0);
            int j(0);
            int sz(SZ(words[0]));
            VI ans;
            map<string, int> ori_d(d);
            for (;i <= SZ(s)-sz*SZ(words);){
                string t(s.substr(j, sz));
                //cout << "ij " << i << " " << j << endl;
                if (d.find(t) != d.end() && d[t] > 0){
                    --d[t];
                    j += sz;
                    //cout << t << " " << d[t] << " " << j << " " << i << endl;
                    if ((j-i) == sz * SZ(words)){
                        //cout << "ans " << i << endl;
                        ans.PB(i);
                        d = ori_d;
                        ++i;
                        j = i;
                    }
                }
                else{
                    d = ori_d;
                    ++i;
                    j = i;
                }
            }
            return ans;
        }
};

#endif /* end of include guard: SUBSTR_CONCAT_WORDS_H */
