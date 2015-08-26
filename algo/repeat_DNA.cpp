#ifndef REPEAT_DNA_H

#define REPEAT_DNA_H

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
        int convertDNA2Int(string seq){
            int x(0);
            REP (i, SZ(seq)){
                if (seq[i] == 'A') x = x * 4;
                if (seq[i] == 'C') x = x * 4 + 1;
                if (seq[i] == 'G') x = x * 4 + 2;
                if (seq[i] == 'T') x = x * 4 + 3;
            }
            return x;
        }
        string convertInt2DN(int x){
            string seq;
            REP (i, 10){
                switch (x%4){
                    case 0: seq = "A" + seq; break;
                    case 1: seq = "C" + seq; break;
                    case 2: seq = "G" + seq; break;
                    case 3: seq = "T" + seq; break;
                }
                x /= 4;
            }
            return seq;
        }
        vector<string> findRepeatedDnaSequences(string s) {
            map<int, int> d;
            REP (i, SZ(s)-9){
                int t(convertDNA2Int(s.substr(i,10)));
                if (d.find(t) == d.end()){
                    d[t] = 0;
                }
                d[t]++;
            }
            vector<string> ans;
            for (map<int, int>::iterator iter = d.begin();iter != d.end();++iter){
                if (iter->second > 1){
                    ans.PB(convertInt2DN(iter->first));
                }
            }
            return ans;
        }
};

#endif /* end of include guard: REPEAT_DNA_H */
