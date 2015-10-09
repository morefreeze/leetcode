#ifndef WORD_LADDER_H

#define WORD_LADDER_H

#include <vector>
#include <list>
#include <map>
#include <unordered_set>
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
typedef vector<int> f;
typedef vector<f> Vf;
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
        bool fizzBuzz(const string& lhs, const string& rhs) {
            if (SZ(lhs) != SZ(rhs)) return false;
            int diff_cnt(0);
            REP (i, SZ(lhs)) {
                if (lhs[i] != rhs[i]) ++diff_cnt;
                if (diff_cnt > 1) return false;
            }
            return diff_cnt <= 1;
        }
        struct node {
            string s;
            int len;
            node(string& s, int len):s(s), len(len) {}
        };
        int ladderLength(string beginWord, string endWord, unordered_set<string>& d) {
            if (SZ(beginWord) != SZ(endWord) || SZ(d) == 0) return 0;
            deque<node> Q;
            Q.PB(node(beginWord,1));
            while (!Q.empty()) {
                node cur(Q.front());
                Q.pop_front();
                REP (i, SZ(cur.s)) {
                    string cur_s(cur.s);
                    FOR (j, 'a', 'z'+1) {
                        if (j == cur.s[i]) continue;
                        cur_s[i] = j;
                        if (cur_s == endWord) return cur.len+1;
                        unordered_set<string>::iterator iter(d.find(cur_s));
                        if (iter != d.end()) {
                            Q.PB(node(cur_s, cur.len+1));
                            d.erase(iter);
                        }
                    }
                }
            }
            return 0;
        }
        // TLE
        int shortestPathLadderLength(string beginWord, string endWord, unordered_set<string>& d) {
            if (SZ(beginWord) != SZ(endWord) || SZ(d) == 0) return 0;
            d.insert(beginWord);
            d.insert(endWord);
            int n(SZ(d));
            int **f = new int*[n];
            REP (i, n) {
                f[i] = new int[n];
                REP (j, n) {
                    f[i][j] = 0;
                }
            }
            int i(0);
            int st(-1);
            int en(-1);
            // this double loop cost most time
            for (unordered_set<string>::iterator iter = d.begin(); iter != d.end(); ++iter,++i) {
                if (SZ(*iter) != SZ(beginWord)) continue;
                if (*iter == beginWord) st = i;
                if (*iter == endWord) en = i;
                int j(0);
                for (unordered_set<string>::iterator jter = d.begin(); jter != d.end(); ++jter,++j) {
                    if (jter == iter) break;
                    if (SZ(*jter) != SZ(beginWord)) continue;
                    if (fizzBuzz(*iter, *jter)) {
                        f[i][j] = f[j][i] = 1;
                    }
                }
            }
            if (st == -1 || en == -1) return 0;
            //debug(st);
            //debug(en);
            //REP (i, n) {
                //REP (j, n) {
                    //cout << f[i][j] << " ";
                //}
                //cout << endl;
            //}
            int ans[n];
            bool vi[n];
            CLR(vi);
            vi[st] = true;
            REP (i, n) {
                ans[i] = f[st][i];
            }
            REP (i, n) {
                int cur(-1);
                REP (j, n) {
                    if (!vi[j] && ans[j] != 0 && (cur == -1 || ans[j] < ans[cur])) {
                        cur = j;
                    }
                }
                if (cur == -1) break;
                if (cur == en) break;
                vi[cur] = true;
                REP (j, n) {
                    if (f[cur][j] != 0 && (ans[j] == 0 || ans[cur] + f[cur][j] < ans[j])) {
                        ans[j] = ans[cur] + f[cur][j];
                    }
                }
            }
            //REP (i, n) {
                //REP (j, n) {
                    //cout << f[i][j] << " ";
                //}
                //cout << endl;
            //}
            return ans[en]+1;
        }
};

#endif /* end of include guard: WORD_LADDER_H */
