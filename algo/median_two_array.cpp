#ifndef LEETCODE_H_
#define LEETCODE_H_
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
        int findKTh(VI& nums1, VI& nums2, int goal){
            int lh(0), rh(SZ(nums1));
            VI::iterator lit2(nums2.begin()), rit2(nums2.end());
            int md((lh+rh)/2);
            if (SZ(nums1) == 0) return (nums2[goal]);
            if (SZ(nums2) == 0) return (nums1[goal]);
            do{
                VI::iterator lowit = lower_bound(lit2, rit2, nums1[md]);
                VI::iterator uppit = upper_bound(lit2, rit2, nums1[md]);
                int low(lowit-nums2.begin()), upp(uppit-nums2.begin());
                if (md+low <= goal && goal < md+upp){
                    return nums1[md];
                }
                // this number is in nums1
                if (low == upp && goal == md+low){
                    return nums1[md];
                }
                if (goal < md+low){
                    rh = md;
                }
                else if(goal >= md+upp){
                    lh = md + 1;
                }
                md = (lh+rh) / 2;
            }while(lh < rh);
            return (nums2[goal-md]);
        }
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int goal((SZ(nums1)+SZ(nums2)-1)/2),goal2((SZ(nums1)+SZ(nums2))/2);
            if (goal == goal2){
                return findKTh(nums1, nums2, goal);
            }
            else{
                return (findKTh(nums1, nums2, goal) + findKTh(nums1, nums2, goal2)) * 0.5;
            }
        }
        // in fact, sort brutely will be accepted
        int findKThAllSorted(VI& nums1, VI& nums2, int k){
            VI nums(nums1);
            nums.insert(nums.end(), ALL(nums2));
            sort(ALL(nums));
            return nums[k];
        }
};

//void print_ans(VI& nums1, VI& nums2){
    //VI nums(nums1);
    //nums.insert(nums.end(), ALL(nums2));
    //sort(ALL(nums));
    //EACH(i, nums)
        //cout << *i << " ";
    //cout << endl;
    //Solution sol;
    //cout << sol.findMedianSortedArrays(nums1, nums2) << "==" << (nums[(SZ(nums)-1)/2]+nums[SZ(nums)/2]) * 0.5 << endl;
//}
//void t1(){
    //int a[] = {};
    //int b[] = {4, 5, 6, 7};
    //VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    //print_ans(nums1, nums2);
//}
//void t2(){
    //int a[] = {1};
    //int b[] = {4, 5, 6, 7};
    //VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    //print_ans(nums1, nums2);
//}
//void t3(){
    //int a[] = {9};
    //int b[] = {4, 5, 6, 7};
    //VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    //print_ans(nums1, nums2);
//}
//void t4(){
    //int a[] = {1, 9};
    //int b[] = {4, 5, 6, 7};
    //VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    //print_ans(nums1, nums2);
//}
//void t5(){
    //int a[] = {4, 5, 6, 7};
    //int b[] = {};
    //VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    //print_ans(nums1, nums2);
//}
//void t6(){
    //int a[] = {1};
    //int b[] = {1};
    //VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    //print_ans(nums1, nums2);
//}
//void t7(){
    //int a[] = {1,3};
    //int b[] = {2,4};
    //VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    //print_ans(nums1, nums2);
//}
//void t8(){
    //int a[] = {1,2};
    //int b[] = {1,2};
    //VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    //print_ans(nums1, nums2);
//}
//void t9(){
    //int a[] = {1,2};
    //int b[] = {1,1};
    //VI nums1(a, a+sizeof(a) / sizeof(*a)), nums2(b, b+sizeof(b) / sizeof(*b));
    //print_ans(nums1, nums2);
//}
//int main(){
    //t1();
    //t2();
    //t3();
    //t4();
    //t5();
    //t6();
    //t7();
    //t8();
    //t9();
    //return 0;
//}
#endif
