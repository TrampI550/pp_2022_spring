// Copyright 2022 Kurnikova Anastasia
#include <gtest/gtest.h>
#include <omp.h>
#include "./sparse_ccs_mult.h"

TEST(sparse_ccs_mult, test1) {
    ASSERT_NO_THROW(mymat a(2, 2, 2));
}

TEST(sparse_ccs_mult, test2) {
    mymat a(1, 1, 0);
    mymat b(1, 1, 0);
    EXPECT_EQ(a, b);
}

TEST(sparse_ccs_mult, test3) {
    mymat a(5, 1, 2);
    ASSERT_NO_THROW(t(&a));
}

TEST(sparse_ccs_mult, test4) {
    mymat a(1, 1, 0);
    mymat b(5, 4, 1);
    bool q = true;
    if (a == b)
        q = true;
    else
        q = false;
    EXPECT_EQ(false, q);
}

TEST(sparse_ccs_mult, test5) {
    mymat a(5, 1, 2);
    mymat b(1, 4, 1);
    mymat ab(5, 4, 2);
    a.num = { 2, 1 };
    b.num = { 3 };
    a.rows = { 1, 2 };
    b.rows = { 0 };
    a.cols = { 0, 2 };
    b.cols = { 0, 0, 0, 1, 1 };
    ab.num = { 6, 3 };
    ab.rows = { 1, 2 };
    ab.cols = { 0, 0, 0, 2, 2 };
    EXPECT_EQ(ab, result(&a, &b));
}

TEST(sparse_ccs_mult, test6) {
    mymat a(2, 1, 0);
    mymat b(1, 1, 1);
    mymat ab(2, 1, 0);
    b.num = { 9 };
    EXPECT_EQ(ab, result(&a, &b));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
