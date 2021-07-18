#ifndef GTBRACKETS_H
#define GTBRACKETS_H

#include "check/brackets.h"
#include "wparameters.h"

class GTBrackets : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

TEST_F(GTBrackets, BracketsStack)
{
    bool result = false;
    uint8_t count = 0;

    int i = 0;
    while(i++ != COUNT_TEST) {

        result = BracketsStack(")()", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsStack("))()", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsStack("()()", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 4);

        result = BracketsStack("())", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);

        result = BracketsStack("()(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);

        result = BracketsStack("(())", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 4);

        result = BracketsStack("()()()()()()()", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 14);

        result = BracketsStack("(((((())))))(((((())))))()()()()()", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 34);

        result = BracketsStack(")(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsStack("(((", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);

        result = BracketsStack(")))(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsStack("(()()()", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 7);

        result = BracketsStack("())(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);
    }
}

TEST_F(GTBrackets, BracketsBool)
{
    bool result = false;
    int count = 0;

    int i = 0;
    while(i++ != COUNT_TEST) {

        result = BracketsBool(")()", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsBool("))()", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsBool("()()", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 4);

        result = BracketsBool("())", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);

        result = BracketsBool("()(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);

        result = BracketsBool("(())", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 4);

        result = BracketsBool("()()()()()()()", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 14);

        result = BracketsBool("(((((())))))(((((())))))()()()()()", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 34);

        result = BracketsBool(")(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsBool("(((", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);

        result = BracketsBool(")))(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsBool("(()()()", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 7);

        result = BracketsBool("())(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);
    }
}

TEST_F(GTBrackets, BracketsCount)
{
    bool result = false;
    int count = 0;

    int i = 0;
    while(i++ != COUNT_TEST) {

        result = BracketsCount(")()", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsCount("))()", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsCount("()()", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 4);

        result = BracketsCount("())", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);

        result = BracketsCount("()(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);

        result = BracketsCount("(())", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 4);

        result = BracketsCount("()()()()()()()", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 14);

        result = BracketsCount("(((((())))))(((((())))))()()()()()", count);
        ASSERT_EQ(result, true);
        ASSERT_EQ(count, 34);

        result = BracketsCount(")(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsCount("(((", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);

        result = BracketsCount(")))(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 1);

        result = BracketsCount("(()()()", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 7);

        result = BracketsCount("())(", count);
        ASSERT_EQ(result, false);
        ASSERT_EQ(count, 3);
    }
}

#endif // GTBRACKETS_H