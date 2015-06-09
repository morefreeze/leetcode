#ifndef REGEX_MATCH_H

#define REGEX_MATCH_H


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

struct Token{
    char ch;
    bool is_star;
    Token(char c = '$', bool star = false): ch(c), is_star(star){}
    bool operator==(const Token& rhs){
        return ch == rhs.ch && is_star == rhs.is_star;
    }
};
class Solution {
    private:
        string s;
        vector<Token> tokens;
    public:
        vector<Token>& str2tokens(const string& p){
            this->tokens.clear();
            Token *p_tk(NULL);
            REP(i, SZ(p)){
                if (p[i] != '*'){
                    p_tk = new Token();
                    p_tk->ch = p[i];
                    if (i+1 < SZ(p) && p[i+1] == '*'){
                        p_tk->is_star = true;
                        ++i;
                    }
                    this->tokens.PB(*p_tk);
                }
                else{
                    exit(1);
                    // some error happen
                }
            }
            return this->tokens;
        }
        /*
        bool check_wild(size_t st, size_t en, int tk_idx){
            while(1){
                if (tk_idx > 0) --tk_idx;
                else break;
                if (tokens[tk_idx].is_star){

                }
            }
            return true;
        }
        */
        bool dfs(size_t cur, int tk_idx){
            if (tk_idx >= SZ(tokens))
                return cur == SZ(s);
            Token tk = tokens[tk_idx];
            if (tk.is_star){
                // zero match
                if (dfs(cur, tk_idx+1)){
                    return true;
                }
                for(;cur < SZ(s);++cur){
                    if (s[cur] == tk.ch || tk.ch == '.'){
                        if (dfs(cur+1, tk_idx+1)){
                            return true;
                        }
                    }
                    else{
                        break;
                    }
                }
                return false;
            }
            else{
                if (s[cur] == tk.ch || tk.ch == '.'){
                    return dfs(cur+1, tk_idx+1);
                }
            }
            return false;
        }

        bool isMatch(string s, string p) {
            s += '$';
            this->s = s;
            p += '$';
            this->tokens = str2tokens(p);
            return dfs(0, 0);
        }
};

#endif /* end of include guard: REGEX_MATCH_H */
