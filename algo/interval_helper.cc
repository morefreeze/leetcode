#include "interval_helper.h"

ostream& operator <<(ostream &out, const Interval &ivl) {
    out << ivl.start << "," << ivl.end;
    return out;
}

bool operator==(const Interval& lhs, const Interval& rhs) {
    return lhs.start == rhs.start && lhs.end == rhs.end;
}

bool interval_array_eq(const vector<Interval> lhs, const vector<Interval> rhs) {
    if (lhs.size() != rhs.size()) {
        cerr << "Size don't match: A[" << lhs.size() << "] "
            << "B[" << rhs.size() << "]" << endl;
        return false;
    }
    for (int i = 0; i < int(lhs.size()); ++i) {
        if (!(lhs[i] == rhs[i])) {
            cerr << "Element don't match at Position " << i
                << "A[" << lhs[i] << "] "
                << "B[" << rhs[i] << "]" << endl;
            return false;
        }
    }
    return true;
}
