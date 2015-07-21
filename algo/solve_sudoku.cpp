#ifndef SOLVE_SUDOKU_H

#define SOLVE_SUDOKU_H

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
#include <queue>

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

class Tile{
    public:
        Tile(int mask, int x, int y):mask(mask),x(x),y(y){}
        Tile(){}
        int mask;
        int x,y;
        bool operator< (const Tile& rhs)const{
            int lcnt(one_count(mask));
            int rcnt(one_count(rhs.mask));
            if (lcnt == rcnt){
                return mask < rhs.mask;
            }
            return lcnt > rcnt;
        }
        static int one_count(int x){
            int res(0);
            while(x){
                x &= x-1;
                ++res;
            }
            return res;
        }
};
class Solution {
    private:
        static const int NUM_SIZE = 9;
    public:
        priority_queue<Tile> pq[NUM_SIZE*NUM_SIZE+10];
        void make_candidates(vector< vector< char > >&board){
            REP (i, NUM_SIZE){
                REP (j, NUM_SIZE){
                    if (board[i][j] != '.') continue;
                    Tile cur;
                    cur.mask = (1<<(NUM_SIZE)) - 1;
                    cur.x = i;
                    cur.y = j;
                    REP (k, NUM_SIZE){
                        if (board[i][k] != '.'){
                            int tmp(board[i][k] - '1');
                            cur.mask &= ~(1<<tmp);
                        }
                        if (board[k][j] != '.'){
                            int tmp(board[k][j] - '1');
                            cur.mask &= ~(1<<tmp);
                        }
                        if (board[i/3*3+k/3][j/3*3+k%3] != '.'){
                            int tmp(board[i/3*3+k/3][j/3*3+k%3] - '1');
                            cur.mask &= ~(1<<tmp);
                        }
                        if (cur.mask == 0){
                            cout << "no solution!" << i << " " << j << endl;
                            return;
                        }
                    }
                    pq[0].push(cur);
                }
            }
        }
        void update_candidate(priority_queue<Tile> &cur_pq, priority_queue<Tile> &other_pq, int x, int y, int mask){
            // clear other_pq
            while(!other_pq.empty()) other_pq.pop();
            while(!cur_pq.empty()){
                Tile cur(cur_pq.top());
                // same row or column or nine square
                if (cur.x == x || cur.y == y || (x/3*3 == cur.x/3*3 && y/3*3 == cur.y/3*3)){
                    cur.mask &= ~mask;
                }
                cur_pq.pop();
                other_pq.push(cur);
            }
        }

        int bin2Int(int x){
            int res(0);
            while(x>1){
                x >>= 1;
                ++res;
            }
            return res;
        }

        bool dfs(vector < vector <char> >& board, int step){
            priority_queue<Tile> &cur_pq = pq[step];
            priority_queue<Tile> &other_pq = pq[step+1];
            if (cur_pq.empty()) return true;
            const Tile cur(cur_pq.top());
            int candidate(cur.mask);
            cur_pq.pop();
            while(candidate){
                int cur_mask(candidate - (candidate & (candidate-1)));
                priority_queue<Tile> tmp_pq(cur_pq);
                update_candidate(tmp_pq, other_pq, cur.x, cur.y, cur_mask);
                board[cur.x][cur.y] = '1' + bin2Int(cur_mask);
                if (dfs(board, step+1)) return true;
                board[cur.x][cur.y] = '.';
                candidate = candidate & (candidate-1);
            }
            cur_pq.push(cur);
            return false;
        }

        void solveSudoku(vector<vector<char> >& board) {
            make_candidates(board);
            if (dfs(board, 0)){
                return ;
            }
            else{
                cout << "no solution try all step!" << endl;
            }
        }
};

#endif /* end of include guard: SOLVE_SUDOKU_H */
