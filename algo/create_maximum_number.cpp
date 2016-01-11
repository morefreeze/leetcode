#ifndef CREATE_MAXIMUM_NUMBER_H

#define CREATE_MAXIMUM_NUMBER_H

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
        VVI singleNumDP(const VI &nums) {
            int n(SZ(nums));
            VVI ans(n+1);
            ans[n] = nums;
            for (int i = n-1; i >= 0; --i) {
                ans[i] = ans[i+1];
                for (int j = 1;j < SZ(ans[i]);++j) {
                    if (ans[i][j] > ans[i][j-1]) {
                        ans[i].erase(ans[i].begin()+j-1);
                        break;
                    }
                }
                ans[i].resize(i);
            }
            return ans;
        }
        VI merge(const VI &nums1, const VI &nums2) {
            int idx1(0), idx2(0);
            VI ans;
            while (idx1 < SZ(nums1) && idx2 < SZ(nums2)) {
                if (nums1[idx1] > nums2[idx2]) {
                    ans.PB(nums1[idx1++]);
                }
                else if (nums1[idx1] < nums2[idx2]) {
                    ans.PB(nums2[idx2++]);
                }
                // nums1[idx1] == nums2[idx2]
                else {
                    if (lexicographical_compare( nums1.begin()+idx1, nums1.end(),
                                nums2.begin()+idx2, nums2.end())) {
                        while (idx2 < SZ(nums2) && nums2[idx2] == nums1[idx1])
                            ans.PB(nums2[idx2++]);
                    }
                    else {
                        while (idx1 < SZ(nums1) && nums1[idx1] == nums2[idx2])
                            ans.PB(nums1[idx1++]);
                    }
                }
            }
            for (;idx1 < SZ(nums1);++idx1)
                ans.PB(nums1[idx1]);
            for (;idx2 < SZ(nums2);++idx2)
                ans.PB(nums2[idx2]);
            return ans;
        }
        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int K) {
            VVI sn1 = singleNumDP(nums1);
            VVI sn2 = singleNumDP(nums2);
            VI ans;
            FOR (k, max(0, K-SZ(nums2)), min(K,SZ(nums1))+1) {
                ans = max(ans, merge(sn1[k], sn2[K-k]));
            }
            return ans;
        }
};
// O(N*M*K), TLE
class DPSolution {
    public:
        vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int K) {
            int n1(SZ(nums1)), n2(SZ(nums2));
            VI ans;
            string **f[2];
            f[0] = new string*[n1+1];
            f[1] = new string*[n1+1];
            REP (i, n1+1) {
                f[0][i] = new string[n2+1];
                f[1][i] = new string[n2+1];
            }
            REP (i, n1) nums1[i] += '0';
            REP (i, n2) nums2[i] += '0';
            FOR (k, 1, K+1) {
                int cur(k%2);
                int last(1-k%2);
                FOR (i, 0, n1+1) {
                    FOR (j, 0, n2+1) {
                        f[cur][i][j] = "";
                        if (i+j < k) continue;
                        if (i > 0) {
                           if (lt(f[cur][i][j], f[cur][i-1][j])) f[cur][i][j] = f[cur][i-1][j];
                           string tmp;
                           tmp = f[last][i-1][j] + char(nums1[i-1]);
                           if (lt(f[cur][i][j], tmp)) f[cur][i][j] = tmp;
                        }
                        if (j > 0) {
                           if (lt(f[cur][i][j], f[cur][i][j-1])) f[cur][i][j] = f[cur][i][j-1];
                           string tmp;
                           tmp = f[last][i][j-1] + char(nums2[j-1]);
                           if (lt(f[cur][i][j], tmp)) f[cur][i][j] = tmp;
                        }
                        //cout << i << " " << j << " " << f[cur][i][j] << endl;
                    }
                }
                //cout << endl;
            }
            REP (i, SZ(f[K%2][n1][n2])) {
                ans.PB(f[K%2][n1][n2][i]-'0');
                //cout << ans.back() << ",";
            }
            return ans;
        }

        static bool lt(const string &lhs, const string &rhs) {
            int n1(SZ(lhs));
            int n2(SZ(rhs));
            REP (i, n1)
                if (lhs[i] == '0') --n1;
                else break;
            REP (i, n2)
                if (rhs[i] == '0') --n2;
                else break;
            if (n1 != n2) return n1 < n2;
            int j(SZ(rhs)-n2);
            FOR (i, SZ(lhs)-n1, SZ(lhs)) {
                if (lhs[i] != rhs[j]) return lhs[i] < rhs[j];
                ++j;
            }
            return false;
        }
};

#endif /* end of include guard: CREATE_MAXIMUM_NUMBER_H */
