#ifndef WORD_SEARCH2_H

#define WORD_SEARCH2_H

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

class TrieNode {
public:
    static const int MAX_C = 26;
    TrieNode *children[MAX_C];
    char c;
    bool is_leaf;
    // Initialize your data structure here.
    TrieNode(char val='*'): c(val), is_leaf(false) {
        REP (i, MAX_C) children[i] = NULL;
    }
};
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(const string &s) {
        if (SZ(s) == 0) return ;
        TrieNode *cur(root);
        REP (i, SZ(s)) {
            if (cur->children[s[i]-'a'] == NULL) {
                cur->children[s[i]-'a'] = new TrieNode(s[i]);
            }
            cur = cur->children[s[i]-'a'];
        }
        cur->is_leaf = true;
    }
    // if find one word, may be able delete it
    void del(const string &s) {
        TrieNode *cur(root);
        doDel(cur, s, 0);
    }
    bool doDel(TrieNode *cur, const string &s, int idx) {
        if (cur == NULL) return true;
        if (idx >= SZ(s)) return false;
        TrieNode *fa(cur);
        cur = cur->children[s[idx]-'a'];
        if (cur == NULL) return true;
        if (doDel(cur, s, idx+1)) fa->children[s[idx]-'a'] = NULL;
        bool can_del(true);
        REP (i, TrieNode::MAX_C) {
            // still some other children in this node
            if (fa->children[i] != NULL) {
                can_del = false;
                break;
            }
        }
        return can_del;
    }
    TrieNode* root;
};

class Solution {
    private:
        void dfs(vector<vector<char> >& b, int x, int y, TrieNode *cur, string &cur_word, VS &res) {
            if (cur == NULL) return ;
            if (!(0 <= x && x < SZ(b) && 0 <= y && y < SZ(b[x]) && b[x][y] != '#')) return ;
            int idx(b[x][y]-'a');
            cur = cur->children[idx];
            // not found
            if (cur == NULL) return ;
            cur_word += cur->c;
            if (cur->is_leaf) {
                res.PB(cur_word);
                cur->is_leaf = false;
                // del unuse node, but it is useless
                //t->del(cur_word);
            }

            const int dx[4] = {-1, 0, 0, 1};
            const int dy[4] = {0, -1, 1, 0};
            char ori_ch(b[x][y]);
            b[x][y] = '#';
            REP (k, 4) {
                dfs(b, x+dx[k], y+dy[k], cur, cur_word, res);
            }
            b[x][y] = ori_ch;
            // truncate last letter
            cur_word.erase(SZ(cur_word)-1);
            return ;
        }
    public:
        Trie *t;
        vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
            t = new Trie();
            REP (i, SZ(words)) {
                t->insert(words[i]);
            }
            VS ans;
            REP (i, SZ(board)) {
                REP (j, SZ(board[i])) {
                    string cur_word;
                    dfs(board, i, j, t->root, cur_word, ans);
                }
            }
            return ans;
        }
};

#endif /* end of include guard: WORD_SEARCH2_H */
