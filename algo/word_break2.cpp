#ifndef WORD_BREAK2_H

#define WORD_BREAK2_H

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

struct PrefixTree {
    static const int MAX_C = 26;
    PrefixTree *children[MAX_C];
    char c;
    bool is_leaf;
    // in this problem, this is not be used
    int cnt;
    PrefixTree(char val) {
        c = val;
        is_leaf = false;
        cnt = 0;
        REP (i, MAX_C) children[i] = NULL;
    }
};
class Solution {
    public:
        void addNode(const string &s, PrefixTree *cur) {
            if (SZ(s) == 0) return ;
            REP (i, SZ(s)) {
                if (cur->children[s[i]-'a'] == NULL) {
                    cur->children[s[i]-'a'] = new PrefixTree(s[i]);
                }
                cur = cur->children[s[i]-'a'];
            }
            cur->is_leaf = true;
            cur->cnt++;
        }
        PrefixTree *makeTree(unordered_set<string>& d) {
            PrefixTree *root = new PrefixTree('*');
            for (unordered_set<string>::iterator it = d.begin(); it != d.end(); ++it) {
                addNode(*it, root);
            }
            return root;
        }
        // use with prefix tree
        bool dfs(const string &s, string cur_s, int idx, PrefixTree *root) {
            if (idx == SZ(s)) {
                ans.PB(cur_s.substr(0, SZ(cur_s)-1));
                return true;
            }
            PrefixTree *cur(root);
            FOR (i, idx, SZ(s)) {
                int idx_c(s[i]-'a');
                if (cur->children[idx_c] == NULL) return false;
                cur = cur->children[idx_c];
                cur_s += cur->c;
                if (cur->is_leaf) {
                    cur->cnt--;
                    dfs(s, cur_s+" ", i+1, root);
                    cur->cnt++;
                }
            }
            return false;
        }
        VS ans;
        vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
            ans.clear();
            int n(SZ(s));
            if (n == 0) return ans;
            bool dp[n+2];
            CLR(dp);
            dp[0] = true;
            FOR (i, 1, n+1) {
                FOR (j, 0, i+1) {
                    dp[i] = dp[i-j] && (wordDict.find(s.substr(i-j, j)) != wordDict.end());
                    if (dp[i]) break;
                }
            }
            if (!dp[n]) return ans;
            // both dfs can be accepted
            PrefixTree *root(makeTree(wordDict));
            dfs(s, "", 0, root);
            //dfs2(s, "", wordDict);
            SORT(ans);
            return ans;
        }
        void dfs2(const string &s, string cur_s, unordered_set<string> &d) {
            if (s == "") {
                ans.PB(cur_s.substr(0,SZ(cur_s)-1));
                return ;
            }
            for (int i = SZ(s); i > 0;--i) {
                if (d.find(s.substr(0, i)) != d.end()) {
                    dfs2(s.substr(i), cur_s+s.substr(0,i)+" ", d);
                }
            }
        }
};

#endif /* end of include guard: WORD_BREAK2_H */
