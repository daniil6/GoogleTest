#ifndef GTVALIDATOR_H
#define GTVALIDATOR_H

#include "check/validator.h"
#include "wparameters.h"

class GTValidator : public ::testing::Test
{
protected:
    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(GTValidator, ValidatorArray)
{
    int i = 0;
    while(i++ != COUNT_TEST) {
        char out[100] = { 0 };
        std::string in = { "jasg '9u8239 yf8" };
        ValidatorArray(&in[0], out);
        EXPECT_STREQ(out, "982398");
    }
}

TEST_F(GTValidator, ValidatorPoint)
{
    int i = 0;
    while(i++ != COUNT_TEST) {
        char out[100] = { 0 };
        std::string in = { "jasg '9u8239 yf8" };
        ValidatorPoint(&in[0], out);
        EXPECT_STREQ(out, "982398");
    }
}

TEST_F(GTValidator, ValidatorString)
{
    int i = 0;
    while(i++ != COUNT_TEST) {
        std::string out;
        std::string in = { "jasg '9u8239 yf8" };
        ValidatorString(in, out);
        EXPECT_STREQ(&out[0], "982398");
    }
}

TEST_F(GTValidator, ValidatorNewArray)
{
    int i = 0;
    while(i++ != COUNT_TEST) {
        std::string str0 = { "jasg 9u8239 yf8" };
        char* result = ValidatorNewArray(&str0[0]);
        ASSERT_STREQ(result, "982398");
    }
}

#endif // GTVALIDATOR_H