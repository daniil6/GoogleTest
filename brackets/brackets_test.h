#ifndef GTBRACKETS_H
#define GTBRACKETS_H

#include "include/check/brackets.h"

class GTBrackets : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

TEST_F(GTBrackets, CheckBrackets)
{
    bool result = false;

    result = Brackets(")()");
    ASSERT_EQ(result, false);

    result = Brackets("))()");
    ASSERT_EQ(result, false);

    result = Brackets("()()");
    ASSERT_EQ(result, true);

    result = Brackets("())");
    ASSERT_EQ(result, false);

    result = Brackets("()(");
    ASSERT_EQ(result, false);

    result = Brackets("(())");
    ASSERT_EQ(result, true);

    result = Brackets("()()()()()()()");
    ASSERT_EQ(result, true);

    result = Brackets("(((((())))))(((((())))))()()()()()");
    ASSERT_EQ(result, true);

    result = Brackets(")(");
    ASSERT_EQ(result, false);

    result = Brackets("(((");
    ASSERT_EQ(result, false);

    result = Brackets(")))(");
    ASSERT_EQ(result, false);

    result = Brackets("(()()()");
    ASSERT_EQ(result, false);
}

#endif // GTBRACKETS_H