#ifndef WORD_SEARCH_H

#define WORD_SEARCH_H

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
        inline char to_upper(char c) {
            if ('a' <= c && c <= 'z') {
                c += 'A' - 'a';
            }
            return c;
        }
        inline char to_lower(char c) {
            if ('A' <= c && c <= 'Z') {
                c += 'a' - 'A';
            }
            return c;
        }
        bool dfs(vector< vector<char> >& b, const string& word, int depth,
                int x, int y) {
            if (!(0 <= x && x < SZ(b) && 0 <= y && y < SZ(b[x]))) return false;
            //cout << x << " " << y << " " << " " << b[x][y] << " " << depth << endl;
            if (b[x][y] != word[depth]) return false;
            if (depth+1 == SZ(word)) return true;
            char ori_c = b[x][y];
            b[x][y] = '-';
            const int dx[4] = {-1, 0, 0, 1};
            const int dy[4] = {0, -1, 1, 0};
            REP (k, 4) {
                if (dfs(b, word, depth+1, x+dx[k], y+dy[k])){
                    b[x][y] = ori_c;
                    return true;
                }
            }
            b[x][y] = ori_c;
            return false;
        }
        bool exist(vector<vector<char> >& board, string word) {
            REP (i, SZ(board)) {
                REP (j, SZ(board[i])) {
                    if (dfs(board, word, 0, i, j)) return true;
                }
            }
            return false;
        }
};

#endif /* end of include guard: WORD_SEARCH_H */
