#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST (TensorTest, TrivialTest) {
    EXPECT_EQ(1 + 1, 2);
}

int main (int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}