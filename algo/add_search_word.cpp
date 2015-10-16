#ifndef ADD_SEARCH_WORD_H

#define ADD_SEARCH_WORD_H

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

struct node {
    bool is_leaf;
    node *children[26];
    node(): is_leaf(false) {
        REP (i, 26) {
            children[i] = NULL;
        }
    }
};
class WordDictionary {
private:
    node *root;
    bool do_search(string &word, int idx, node *cur) {
        if (cur == NULL) return false;
        if (idx == SZ(word)) return cur->is_leaf;
        if (word[idx] == '.') {
            REP (i, 26) {
                if (do_search(word, idx+1, cur->children[i])) return true;
            }
        }
        else {
            return do_search(word, idx+1, cur->children[word[idx]-'a']);
        }
        return false;
    }
    void do_print_tree(node *cur) {
        if (cur == NULL) return;
        cout << "(";
        REP (i, 26) {
            if (NULL != cur->children[i]) {
                cout << char('a'+i) << ",";
                do_print_tree(cur->children[i]);
            }
        }
        cout << ")";
    }

public:

    WordDictionary(): root(NULL) {}
    // Adds a word into the data structure.
    void addWord(string word) {
        node **cur(&root);
        REP (i, SZ(word)) {
            if (NULL == *cur) {
                *cur = new node();
            }
            if (NULL == (*cur)->children[word[i]-'a']) {
                (*cur)->children[word[i]-'a'] = new node();
            }
            cur = &(*cur)->children[word[i]-'a'];
            if (i == SZ(word)-1) {
                (*cur)->is_leaf = true;
            }
        }
    }

    void printTree() {
        do_print_tree(root);
        cout << endl;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return do_search(word, 0, root);
    }
};
#endif /* end of include guard: ADD_SEARCH_WORD_H */
