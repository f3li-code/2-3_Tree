#include "gtest/gtest.h"
#include "../header/Tree.h"

TEST(insert, t1) {
    Tree tree;
    string a = "insert";
    tree.insert(a);
    tree.insert("b");
    tree.preOrder();
    // cout << endl;
}