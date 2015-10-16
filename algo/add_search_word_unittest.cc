#include <gtest/gtest.h>
#include "add_search_word.cpp"

class AddSearchWordTest: public testing::Test{
};
TEST_F(AddSearchWordTest, Small){
    WordDictionary wd;
    wd.addWord("word");
    wd.addWord("pattern");
    wd.printTree();
    EXPECT_EQ(true, wd.search("pattern"));
    EXPECT_EQ(false, wd.search("work"));
}
TEST_F(AddSearchWordTest, WildCard){
    WordDictionary wd;
    wd.addWord("word");
    wd.addWord("pattern");
    wd.printTree();
    EXPECT_EQ(true, wd.search("pa..ern"));
    EXPECT_EQ(true, wd.search("wor."));
}
