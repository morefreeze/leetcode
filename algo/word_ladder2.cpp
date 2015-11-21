#ifndef WORD_LADDER2_H

#define WORD_LADDER2_H

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

class Solution {
    public:
        struct node {
            string s;
            int len;
            map<string,int> path;
            node(string& s, int len):s(s), len(len) {}
        };
        // TLE
        vector<vector<string> > nakedBFS(string beginWord, string endWord, unordered_set<string> &d) {
            vector<VS> ans;
            int ans_len(SZ(d));
            if (SZ(beginWord) != SZ(endWord) || SZ(d) == 0) return ans;
            deque<node> Q;
            Q.PB(node(beginWord,1));
            Q.front().path[beginWord] = 0;
            d.insert(endWord);
            while (!Q.empty()) {
                node cur(Q.front());
                if (SZ(cur.path) >= ans_len) break;
                Q.pop_front();
                REP (i, SZ(cur.s)) {
                    string cur_s(cur.s);
                    FOR (j, 'a', 'z'+1) {
                        if (j == cur.s[i]) continue;
                        cur_s[i] = j;
                        do {
                            unordered_set<string>::iterator iter(d.find(cur_s));
                            // found in dict
                            if (iter == d.end()) break;
                            // check word appear in path
                            if (cur.path.find(cur_s) != cur.path.end()) break;

                            cout << cur_s << " " << SZ(cur.path) << endl;
                            node tmp(cur_s, cur.len+1);
                            tmp.path = cur.path;
                            tmp.path[cur_s] = SZ(tmp.path);
                            Q.PB(tmp);
                            if (cur_s == endWord) {
                                if (SZ(tmp.path) <= ans_len) {
                                    ans_len = SZ(tmp.path);
                                    VS tmp_ans(SZ(tmp.path));
                                    for (map<string,int>::iterator mit = tmp.path.begin(); mit != tmp.path.end();++mit) {
                                        tmp_ans[mit->second] = mit->first;
                                    }
                                    ans.PB(tmp_ans);
                                }
                            }
                        }
                        while (0);
                    }
                }
            }
            return ans;
        }
        bool fizzBuzz(const string& lhs, const string& rhs) {
            if (SZ(lhs) != SZ(rhs)) return false;
            int diff_cnt(0);
            REP (i, SZ(lhs)) {
                if (lhs[i] != rhs[i]) ++diff_cnt;
                if (diff_cnt > 1) return false;
            }
            return diff_cnt <= 1;
        }
        // end

        struct BFSTree {
            int idx;
            int depth;
            BFSTree *parent;
        };
        // TLE
        vector<vector<string> > singleBFSTree(string beginWord, string endWord, unordered_set<string> &d) {
            vector<VS> ans;
            if (beginWord == endWord) {
                VS ans_tmp;
                ans_tmp.PB(beginWord);
                ans.PB(ans_tmp);
                return ans;
            }
            map<string,int> m;
            VS rm;

            d.insert(beginWord);
            d.insert(endWord);
            int k(0);
            for (unordered_set<string>::iterator it = d.begin(); it != d.end(); ++it,++k) {
                m[*it] = k;
                rm.PB(*it);
            }
            int n(SZ(rm));
            int f[n+10][n+10];
            CLR(f);
            for (unordered_set<string>::iterator it = d.begin(); it != d.end(); ++it) {
                for (unordered_set<string>::iterator jt = it; jt != d.end(); ++jt) {
                    if (it == jt) continue;
                    int l(m[*it]), r(m[*jt]);
                    if (fizzBuzz(*it, *jt)) {
                        f[l][r] = f[r][l] = 1;
                    }
                }
            }
            int ans_len(n);
            int goal(m[endWord]);
            BFSTree *root = new BFSTree();
            root->idx = m[beginWord];
            root->depth = 0;
            root->parent = NULL;
            deque<BFSTree*> Q;
            Q.PB(root);
            while (!Q.empty()) {
                BFSTree *cur(Q.front());
                // we have steped next level of BFS tree, so finish
                if (cur->depth >= ans_len) break;
                Q.pop_front();
                REP (i, n) {
                    if (f[cur->idx][i] && !in_path(cur, i)) {
                        BFSTree *tmp = new BFSTree();
                        tmp->idx = i;
                        tmp->depth = cur->depth + 1;
                        tmp->parent = cur;
                        //cout << rm[tmp->idx] << " " << tmp->depth << endl;
                        Q.PB(tmp);
                        if (i == goal) {
                            ans_len = tmp->depth;
                            VS ans_tmp;
                            while (tmp) {
                                ans_tmp.PB(rm[tmp->idx]);
                                tmp = tmp->parent;
                            }
                            ans.PB(VS(RALL(ans_tmp)));
                        }
                    }
                }
            }
            return ans;
        }
        bool in_path (BFSTree *cur, int idx) {
            while (cur) {
                if (idx == cur->idx) return true;
                cur = cur->parent;
            }
            return false;
        }
        // end

        // doubly BFS
        vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &d) {
            vector<VS> ans;
            VS path(1, beginWord);
            if (beginWord == endWord) {
                ans.PB(path);
                return ans;
            }
            unordered_set<string> w1, w2;
            w1.insert(beginWord);
            w2.insert(endWord);
            map<string, VS> next;
            bool isw1(false);
            if (findLadderHelper(w1, w2, d, next, isw1)) {
                get_path(beginWord, endWord, next, path, ans);
            }
            return ans;
        }
        bool findLadderHelper(
                unordered_set<string> &w1,
                unordered_set<string> &w2,
                unordered_set<string> &d,
                map<string, VS> &next,
                bool &isw1) {
            isw1 = !isw1;
            if (w1.empty()) return false;
            if (SZ(w1) > SZ(w2)) return findLadderHelper(w2, w1, d, next, isw1);
            for (unordered_set<string>::iterator it = w1.begin(); it != w1.end(); ++it)
                d.erase(*it);
            for (unordered_set<string>::iterator it = w2.begin(); it != w2.end(); ++it)
                d.erase(*it);
            unordered_set<string> w3;
            bool reach(false);
            for (unordered_set<string>::iterator it = w1.begin(); it != w1.end(); ++it) {
                string word = *it;
                for (string::iterator ch = word.begin(); ch != word.end(); ++ch) {
                    char tmp(*ch);
                    for (*ch = 'a'; *ch <= 'z'; ++(*ch)) {
                        if (EXIST(w2, word)) {
                            reach = true;
                            isw1 ? next[*it].PB(word) : next[word].PB(*it);
                        }
                        else if (!reach && EXIST(d, word)) {
                            w3.insert(word);
                            isw1 ? next[*it].PB(word) : next[word].PB(*it);
                        }
                    }
                    *ch = tmp;
                }
            }
            return reach || findLadderHelper(w2, w3, d, next, isw1);
        }
        void get_path(
                string &curWord,
                string &endWord,
                map<string, VS> &next,
                VS &path,
                vector<VS> &ans) {
            if (curWord == endWord)
                ans.PB(path);
            else {
                for (VS::iterator it = next[curWord].begin();
                        it != next[curWord].end();
                        ++it) {
                    path.PB(*it);
                    get_path(*it, endWord, next, path, ans);
                    path.pop_back();
                }
            }
        }
};

#endif /* end of include guard: WORD_LADDER2_H */
