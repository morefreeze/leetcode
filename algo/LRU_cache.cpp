#ifndef LRU_CACHE_H

#define LRU_CACHE_H

#include <unordered_map>
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

class LRUCache{
private:
    int cap;
    unordered_map<int,list<PII>::iterator> data;
    list<PII> l;
    void touch(list<PII>::iterator &it) {
        l.PB(*it);
        data[it->first] = --(l.end());
        l.erase(it);
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (!EXIST(data, key)) return -1;
        list<PII>::iterator it = data[key];
        touch(it);
        return it->second;
    }

    void set(int key, int value) {
        list<PII>::iterator it;
        if (EXIST(data, key)) {
            it = data[key];
            it->second = value;
        }
        else {
            if (SZ(l) >= cap) {
                data.erase(l.begin()->first);
                l.erase(l.begin());
            }
            // tmp add to front, will remove in touch()
            l.push_front(MP(key,value));
            it = l.begin();
        }
        touch(it);
    }
};

class BruteLRUCache{
private:
    map<int,int> data;
    list<int> l;
    int cap;
    void add_queue(int key) {
        for (auto it = l.begin(); it != l.end(); ++it) {
            if (*it == key) {
                l.erase(it);
                break;
            }
        }
        l.PB(key);
        while (SZ(l) > cap) {
            data[l.front()] = -1;
            l.pop_front();
        }
    }
public:
    BruteLRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (EXIST(data, key)) {
            add_queue(key);
            return data[key];
        }
        return -1;
    }

    void set(int key, int value) {
        add_queue(key);
        data[key] = value;
    }
};
#endif /* end of include guard: LRU_CACHE_H */
