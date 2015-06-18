#ifndef LETTER_COMB_PHONE_H

#define LETTER_COMB_PHONE_H

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
        Solution(){
            m_dig_map['2'] = "abc";
            m_dig_map['3'] = "def";
            m_dig_map['4'] = "ghi";
            m_dig_map['5'] = "jkl";
            m_dig_map['6'] = "mno";
            m_dig_map['7'] = "pqrs";
            m_dig_map['8'] = "tuv";
            m_dig_map['9'] = "wxyz";
        }
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            if (SZ(digits) == 0) return ans;
            this->m_digits = digits;
            dfs("", 0, ans);
            return ans;
        }
    private:
        string m_digits;
        map<char, string> m_dig_map;
        void dfs(string cur, int depth, vector<string>& ans){
            if (depth >= SZ(m_digits)){
                ans.PB(cur);
                return ;
            }
            char t(m_digits[depth]);
            if (m_dig_map.end() == m_dig_map.find(t)) dfs(cur, depth+1, ans);
            REP(i, SZ(m_dig_map[t])){
                dfs(cur+m_dig_map[t][i], depth+1, ans);
            }
        }
};

#endif /* end of include guard: LETTER_COMB_PHONE_H */
