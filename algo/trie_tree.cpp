#ifndef TRIE_TREE_H

#define TRIE_TREE_H

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
    private:
        bool find(const string &s, bool is_leaf) {
            TrieNode *cur(root);
            int i;
            for (i = 0;i < SZ(s); ++i) {
                int idx_c(s[i]-'a');
                if (cur->children[idx_c] == NULL) return false;
                cur = cur->children[idx_c];
            }
            if (i == SZ(s)) {
                if (is_leaf) return cur->is_leaf;
                return true;
            }
            return false;
        }
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
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

    // Returns if the word is in the trie.
    bool search(string word) {
        return find(word, true);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return find(prefix, false);
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
#endif /* end of include guard: TRIE_TREE_H */
