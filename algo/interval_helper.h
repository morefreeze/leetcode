#ifndef INTERVAL_HELPER_H

#define INTERVAL_HELPER_H
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool interval_array_eq(const vector<Interval> lhs, const vector<Interval> rhs);
#endif /* end of include guard: INTERVAL_HELPER_H */
