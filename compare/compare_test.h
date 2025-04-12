#ifndef GTCOMPARE_H
#define GTCOMPARE_H

#include "compare_symbol.h"
#include "wparameters.h"

class GTCompare : public ::testing::Test
{
protected:
    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(GTCompare, compare)
{
    int position = 0;

    int i = 0;
    while(i++ != COUNT_TEST) {

        position = compare("ABC", 3, "ABC", 3);
        EXPECT_EQ(position, -1);

        position = compare("ABC", 3, "ABCD", 4);
        EXPECT_EQ(position, 3);

        position = compare("ABCD", 4, "ABC", 3);
        EXPECT_EQ(position, 3);

        position = compare("X1", 2, "Y1", 2);
        EXPECT_EQ(position, 0);

        position = compare("X12", 3, "Y1", 2);
        EXPECT_EQ(position, 0);

        position = compare("X1", 2, "Y12", 3);
        EXPECT_EQ(position, 0);
    }
}

#endif // GTCOMPARE_H