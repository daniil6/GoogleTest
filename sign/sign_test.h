#ifndef GBRACKETS_H
#define GBRACKETS_H

#include "include/check/sign.h"

class GTBrackets : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

TEST_F(GTBrackets, SignCompactError)
{
    int i = 0;
    while(i++ != 10000) {

        CheckError result = SUCCESS;

        result = SignCompactError("1+1");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("+1+1");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("1++1");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("1+1+");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("1+.1+");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("1+.1");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("-1");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("1324234*235341");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("13/(24234*235341)*(23+1//)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("*13/(24234*235341)*(23+1/)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("(23+1/)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("13/(24234*235341)*(23+1/)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("0/");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("---");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("0+0");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("0-(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("0-(-1)*");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("0-((-1)*)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("0-((-1)*24)");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("0-((-1)*(/1)))");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("0-(-(-1)*(/1))");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("*(-1)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("+(-1)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("-(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("/(-1)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError(".(-1)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError(",(-1)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("(-1,2)");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("(-1,.2)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("(-1,(.2)");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("(-1*(-2))");
        EXPECT_EQ(result, SUCCESS);

        result = SignCompactError("(-1*(-.2))");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("(-1*(-2.))");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("(-1*(.-2))");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("(-1*(-2)).");
        EXPECT_EQ(result, ERRORS);

        result = SignCompactError("(-1.*(-2))");
        EXPECT_EQ(result, ERRORS);
    }
}

TEST_F(GTBrackets, SignFullError)
{
    int i = 0;
    while(i++ != 10000) {

        CheckError result = SUCCESS;

        result = SignFullError("1+1");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("+1+1");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = SignFullError("1++1");
        EXPECT_EQ(result, SIGN_SIGN);

        result = SignFullError("1+1+");
        EXPECT_EQ(result, SIGN_END);

        result = SignFullError("1+.1+");
        EXPECT_EQ(result, SIGN_SIGN);

        result = SignFullError("1+.1");
        EXPECT_EQ(result, SIGN_SIGN);

        result = SignFullError("-1");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("1324234*235341");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("13/(24234*235341)*(23+1//)");
        EXPECT_EQ(result, SIGN_SIGN);

        result = SignFullError("*13/(24234*235341)*(23+1/)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = SignFullError("(23+1/)");
        EXPECT_EQ(result, SIGN_BRACKET_CLOSE);

        result = SignFullError("13/(24234*235341)*(23+1/)");
        EXPECT_EQ(result, SIGN_BRACKET_CLOSE);

        result = SignFullError("0/");
        EXPECT_EQ(result, SIGN_END);

        result = SignFullError("---");
        EXPECT_EQ(result, SIGN_SIGN);

        result = SignFullError("0+0");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("0-(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("0-(-1)*");
        EXPECT_EQ(result, SIGN_END);

        result = SignFullError("0-((-1)*)");
        EXPECT_EQ(result, SIGN_BRACKET_CLOSE);

        result = SignFullError("0-((-1)*24)");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("0-((-1)*(/1)))");
        EXPECT_EQ(result, BRACKET_OPEN_SIGN);

        result = SignFullError("0-(-(-1)*(/1))");
        EXPECT_EQ(result, BRACKET_OPEN_SIGN);

        result = SignFullError("*(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = SignFullError("+(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = SignFullError("-(-1)");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("/(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = SignFullError(".(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = SignFullError(",(-1)");
        EXPECT_EQ(result, EMPTY_SIGN);

        result = SignFullError("(-1,2)");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("(-1,.2)");
        EXPECT_EQ(result, POINT_SIGN);

        result = SignFullError("(-1,(.2)");
        EXPECT_EQ(result, POINT_BRACKET_OPEN);

        result = SignFullError("(-1*(-2))");
        EXPECT_EQ(result, SUCCESS);

        result = SignFullError("(-1*(-.2))");
        EXPECT_EQ(result, SIGN_SIGN);

        result = SignFullError("(-1*(-2.))");
        EXPECT_EQ(result, POINT_BRACKET_CLOSE);

        result = SignFullError("(-1*(.-2))");
        EXPECT_EQ(result, BRACKET_OPEN_SIGN);

        result = SignFullError("(-1*(-2)).");
        EXPECT_EQ(result, POINT_END);

        result = SignFullError("(-1.*(-2))");
        EXPECT_EQ(result, POINT_SIGN);
    }
}

#endif // GBRACKETS_H