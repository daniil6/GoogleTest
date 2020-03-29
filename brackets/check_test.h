#ifndef GBRACKETS_H
#define GBRACKETS_H

#include "E:\WorkSpace\x32a\GraphManager\plot\check.h"

class GTBrackets : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

TEST_F(GTBrackets, CheckSignShowCompactError)
{
    int i = 0;
    while(i++ != 10000) {

        CCheck ch;
        CheckError result = SUCCESS;

        result = ch.SignCompact("1+1");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("+1+1");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("1++1");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("1+1+");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("1+.1+");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("1+.1");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("-1");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("1324234*235341");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("13/(24234*235341)*(23+1//)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("*13/(24234*235341)*(23+1/)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("(23+1/)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("13/(24234*235341)*(23+1/)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("0/");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("---");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("0+0");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("0-(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("0-(-1)*");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("0-((-1)*)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("0-((-1)*24)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("0-((-1)*(/1)))");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("0-(-(-1)*(/1))");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("*(-1)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("+(-1)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("-(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("/(-1)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact(".(-1)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact(",(-1)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("(-1,2)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("(-1,.2)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("(-1,(.2)");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("(-1*(-2))");
        EXPECT_EQ(result, SUCCESS);

        result = ch.SignCompact("(-1*(-.2))");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("(-1*(-2.))");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("(-1*(.-2))");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("(-1*(-2)).");
        EXPECT_EQ(result, ERROR);

        result = ch.SignCompact("(-1.*(-2))");
        EXPECT_EQ(result, ERROR);
    }
}

TEST_F(GTBrackets, CheckSignShowFullError)
{
    int i = 0;
    while(i++ != 10000) {

        CCheck ch;
        CheckError result = SUCCESS;

        result = ch.Sign("1+1");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("+1+1");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = ch.Sign("1++1");
        EXPECT_EQ(result, SIGN_SIGN);

        result = ch.Sign("1+1+");
        EXPECT_EQ(result, SIGN_END);

        result = ch.Sign("1+.1+");
        EXPECT_EQ(result, SIGN_SIGN);

        result = ch.Sign("1+.1");
        EXPECT_EQ(result, SIGN_SIGN);

        result = ch.Sign("-1");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("1324234*235341");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("13/(24234*235341)*(23+1//)");
        EXPECT_EQ(result, SIGN_SIGN);

        result = ch.Sign("*13/(24234*235341)*(23+1/)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = ch.Sign("(23+1/)");
        EXPECT_EQ(result, SIGN_BRACKET_CLOSE);

        result = ch.Sign("13/(24234*235341)*(23+1/)");
        EXPECT_EQ(result, SIGN_BRACKET_CLOSE);

        result = ch.Sign("0/");
        EXPECT_EQ(result, SIGN_END);

        result = ch.Sign("---");
        EXPECT_EQ(result, SIGN_SIGN);

        result = ch.Sign("0+0");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("0-(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("0-(-1)*");
        EXPECT_EQ(result, SIGN_END);

        result = ch.Sign("0-((-1)*)");
        EXPECT_EQ(result, SIGN_BRACKET_CLOSE);

        result = ch.Sign("0-((-1)*24)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("0-((-1)*(/1)))");
        EXPECT_EQ(result, BRACKET_OPEN_SIGN);

        result = ch.Sign("0-(-(-1)*(/1))");
        EXPECT_EQ(result, BRACKET_OPEN_SIGN);

        result = ch.Sign("*(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = ch.Sign("+(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = ch.Sign("-(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("/(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = ch.Sign(".(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = ch.Sign(",(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = ch.Sign("(-1,2)");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("(-1,.2)");
        EXPECT_EQ(result, POINT_SIGN);

        result = ch.Sign("(-1,(.2)");
        EXPECT_EQ(result, POINT_BRACKET_OPEN);

        result = ch.Sign("(-1*(-2))");
        EXPECT_EQ(result, SUCCESS);

        result = ch.Sign("(-1*(-.2))");
        EXPECT_EQ(result, SIGN_SIGN);

        result = ch.Sign("(-1*(-2.))");
        EXPECT_EQ(result, POINT_BRACKET_CLOSE);

        result = ch.Sign("(-1*(.-2))");
        EXPECT_EQ(result, BRACKET_OPEN_SIGN);

        result = ch.Sign("(-1*(-2)).");
        EXPECT_EQ(result, POINT_END);

        result = ch.Sign("(-1.*(-2))");
        EXPECT_EQ(result, POINT_SIGN);
    }
}

TEST_F(GTBrackets, CheckBrackets)
{
    CCheck ch;
    bool result = false;

    result = ch.Brackets(")()");
    ASSERT_EQ(result, false);

    result = ch.Brackets("))()");
    ASSERT_EQ(result, false);

    result = ch.Brackets("()()");
    ASSERT_EQ(result, true);

    result = ch.Brackets("())");
    ASSERT_EQ(result, false);

    result = ch.Brackets("()(");
    ASSERT_EQ(result, false);

    result = ch.Brackets("(())");
    ASSERT_EQ(result, true);

    result = ch.Brackets("()()()()()()()");
    ASSERT_EQ(result, true);

    result = ch.Brackets("(((((())))))(((((())))))()()()()()");
    ASSERT_EQ(result, true);

    result = ch.Brackets(")(");
    ASSERT_EQ(result, false);

    result = ch.Brackets("(((");
    ASSERT_EQ(result, false);

    result = ch.Brackets(")))(");
    ASSERT_EQ(result, false);

    result = ch.Brackets("(()()()");
    ASSERT_EQ(result, false);
}

#endif // GBRACKETS_H