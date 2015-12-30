#include "interval_helper.h"

bool operator==(const Interval& lhs, const Interval& rhs) {
    return lhs.start == rhs.start && lhs.end == rhs.end;
}

bool interval_array_eq(const vector<Interval> lhs, const vector<Interval> rhs) {
    if (lhs.size() != rhs.size()) return false;
    for (int i = 0; i < int(lhs.size()); ++i) {
        if (!(lhs[i] == rhs[i])) return false;
    }
    return true;
}
