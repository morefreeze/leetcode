#include <gtest/gtest.h>
#include "reconstruct_itinerary.cpp"

class ReconstructItineraryTest: public testing::Test{
    protected:
        Solution sol;
};
TEST_F(ReconstructItineraryTest, Small){
    vector< pair<string,string> > a;
    a.PB(MP("MUC", "LHR"));
    a.PB(MP("JFK", "MUC"));
    a.PB(MP("SFO", "SJC"));
    a.PB(MP("LHR", "SFO"));
    string z[] = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.findItinerary(a));
}
TEST_F(ReconstructItineraryTest, Small2){
    vector< pair<string,string> > a;
    a.PB(MP("JFK","SFO"));
    a.PB(MP("JFK","ATL"));
    a.PB(MP("SFO","ATL"));
    a.PB(MP("ATL","JFK"));
    a.PB(MP("ATL","SFO"));

    string z[] = {"JFK","ATL","JFK","SFO","ATL","SFO"};
    VS ans(ASZ(z));
    EXPECT_EQ(ans, sol.findItinerary(a));
}
