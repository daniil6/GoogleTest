#ifndef GTSIGN_H
#define GTSIGN_H

#include "check/sign.h"
#include "wparameters.h"

class GTSign : public ::testing::Test
{
protected:
    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(GTSign, SignCompactError)
{
    int number = 0;
    CheckError result = SUCCESS;

    int i = 0;
    while(i++ != COUNT_TEST) {

        result = SignCompactError("1+1", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 3);

        result = SignCompactError("+1+1", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 1);

        result = SignCompactError("1++1", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 3);

        result = SignCompactError("1+1+", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 4);

        result = SignCompactError("1+.1+", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 3);

        result = SignCompactError("1+.1", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 3);

        result = SignCompactError("-1", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 2);

        result = SignCompactError("(-1)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 4);

        result = SignCompactError("1324234*235341", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 14);

        result = SignCompactError("13/(24234*235341)*(23+1//)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 25);

        result = SignCompactError("*13/(24234*235341)*(23+1/)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 1);

        result = SignCompactError("(23+1/)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 7);

        result = SignCompactError("13/(24234*235341)*(23+1/)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 25);

        result = SignCompactError("0/", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 2);

        result = SignCompactError("---", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 2);

        result = SignCompactError("0+0", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 3);

        result = SignCompactError("0-(-1)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 6);

        result = SignCompactError("0-(-1)*", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 7);

        result = SignCompactError("0-((-1)*)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 9);

        result = SignCompactError("0-((-1)*24)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 11);

        result = SignCompactError("0-((-1)*(/1)))", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 10);

        result = SignCompactError("0-(-(-1)*(/1))", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 11);

        result = SignCompactError("*(-1)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 1);

        result = SignCompactError("+(-1)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 1);

        result = SignCompactError("-(-1)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 5);

        result = SignCompactError("/(-1)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 1);

        result = SignCompactError(".(-1)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 1);

        result = SignCompactError(",(-1)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 1);

        result = SignCompactError("(-1,2)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 6);

        result = SignCompactError("(-1,.2)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 5);

        result = SignCompactError("(-1,(.2)", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 5);

        result = SignCompactError("(-1*(-2))", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 9);

        result = SignCompactError("(-1*(-.2))", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 7);

        result = SignCompactError("(-1*(-2.))", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 9);

        result = SignCompactError("(-1*(.-2))", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 6);

        result = SignCompactError("(-1*(-2)).", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 10);

        result = SignCompactError("(-1.*(-2))", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 5);

        result = SignCompactError("2-(-1)*", number);
        EXPECT_EQ(result, ERRORS);
        EXPECT_EQ(number, 7);
    }
}

TEST_F(GTSign, SignFullError)
{
    CheckError result = SUCCESS;
    int number = 0;

    int i = 0;
    while(i++ != COUNT_TEST) {

        result = SignFullError("1+1", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 3);

        result = SignFullError("+1+1", number);
        EXPECT_EQ(result, EMPTY_SIGN);
        EXPECT_EQ(number, 1);

        result = SignFullError("1++1", number);
        EXPECT_EQ(result, SIGN_SIGN);
        EXPECT_EQ(number, 3);

        result = SignFullError("1+1+", number);
        EXPECT_EQ(result, SIGN_END);
        EXPECT_EQ(number, 4);

        result = SignFullError("1+.1+", number);
        EXPECT_EQ(result, SIGN_SIGN);
        EXPECT_EQ(number, 3);

        result = SignFullError("1+.1", number);
        EXPECT_EQ(result, SIGN_SIGN);
        EXPECT_EQ(number, 3);

        result = SignFullError("-1", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 2);

        result = SignFullError("(-1)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 4);

        result = SignFullError("1324234*235341", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 14);

        result = SignFullError("13/(24234*235341)*(23+1//)", number);
        EXPECT_EQ(result, SIGN_SIGN);
        EXPECT_EQ(number, 25);

        result = SignFullError("*13/(24234*235341)*(23+1/)", number);
        EXPECT_EQ(result, EMPTY_SIGN);
        EXPECT_EQ(number, 1);

        result = SignFullError("(23+1/)", number);
        EXPECT_EQ(result, SIGN_BRACKET_CLOSE);
        EXPECT_EQ(number, 7);

        result = SignFullError("13/(24234*235341)*(23+1/)", number);
        EXPECT_EQ(result, SIGN_BRACKET_CLOSE);
        EXPECT_EQ(number, 25);

        result = SignFullError("0/", number);
        EXPECT_EQ(result, SIGN_END);
        EXPECT_EQ(number, 2);

        result = SignFullError("---", number);
        EXPECT_EQ(result, SIGN_SIGN);
        EXPECT_EQ(number, 2);

        result = SignFullError("0+0", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 3);

        result = SignFullError("0-(-1)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 6);

        result = SignFullError("0-(-1)*", number);
        EXPECT_EQ(result, SIGN_END);
        EXPECT_EQ(number, 7);

        result = SignFullError("0-((-1)*)", number);
        EXPECT_EQ(result, SIGN_BRACKET_CLOSE);
        EXPECT_EQ(number, 9);

        result = SignFullError("0-((-1)*24)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 11);

        result = SignFullError("0-((-1)*(/1)))", number);
        EXPECT_EQ(result, BRACKET_OPEN_SIGN);
        EXPECT_EQ(number, 10);

        result = SignFullError("0-(-(-1)*(/1))", number);
        EXPECT_EQ(result, BRACKET_OPEN_SIGN);
        EXPECT_EQ(number, 11);

        result = SignFullError("*(-1)", number);
        EXPECT_EQ(result, EMPTY_SIGN);
        EXPECT_EQ(number, 1);

        result = SignFullError("+(-1)", number);
        EXPECT_EQ(result, EMPTY_SIGN);
        EXPECT_EQ(number, 1);

        result = SignFullError("-(-1)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 5);

        result = SignFullError("/(-1)", number);
        EXPECT_EQ(result, EMPTY_SIGN);
        EXPECT_EQ(number, 1);

        result = SignFullError(".(-1)", number);
        EXPECT_EQ(result, EMPTY_SIGN);
        EXPECT_EQ(number, 1);

        result = SignFullError(",(-1)", number);
        EXPECT_EQ(result, EMPTY_SIGN);
        EXPECT_EQ(number, 1);

        result = SignFullError("(-1,2)", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 6);

        result = SignFullError("(-1,.2)", number);
        EXPECT_EQ(result, POINT_SIGN);
        EXPECT_EQ(number, 5);

        result = SignFullError("(-1,(.2)", number);
        EXPECT_EQ(result, POINT_BRACKET_OPEN);
        EXPECT_EQ(number, 5);

        result = SignFullError("(-1*(-2))", number);
        EXPECT_EQ(result, SUCCESS);
        EXPECT_EQ(number, 9);

        result = SignFullError("(-1*(-.2))", number);
        EXPECT_EQ(result, SIGN_SIGN);
        EXPECT_EQ(number, 7);

        result = SignFullError("(-1*(-2.))", number);
        EXPECT_EQ(result, POINT_BRACKET_CLOSE);
        EXPECT_EQ(number, 9);

        result = SignFullError("(-1*(.-2))", number);
        EXPECT_EQ(result, BRACKET_OPEN_SIGN);
        EXPECT_EQ(number, 6);

        result = SignFullError("(-1*(-2)).", number);
        EXPECT_EQ(result, SIGN_END);
        EXPECT_EQ(number, 10);

        result = SignFullError("(-1.*(-2))", number);
        EXPECT_EQ(result, POINT_SIGN);
        EXPECT_EQ(number, 5);

        result = SignFullError("2-(-1)*", number);
        EXPECT_EQ(result, SIGN_END);
        EXPECT_EQ(number, 7);
    }
}

#endif // GTSIGN_H