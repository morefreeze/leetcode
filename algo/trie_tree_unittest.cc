#include <gtest/gtest.h>
#include "trie_tree.cpp"

class TrieTreeTest: public testing::Test{
    protected:
};
TEST_F(TrieTreeTest, Small){
    Trie trie;
    trie.insert("abc");
    trie.insert("abd");
    EXPECT_EQ(true, trie.search("abc"));
    EXPECT_EQ(false, trie.search("ac"));
    EXPECT_EQ(true, trie.startsWith("ab"));
    EXPECT_EQ(true, trie.startsWith("abc"));
    EXPECT_EQ(false, trie.startsWith("ac"));
}
