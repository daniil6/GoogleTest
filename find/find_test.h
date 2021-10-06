#ifndef GTFIND_H
#define GTFIND_H

#include "in_value.h"
#include "wparameters.h"
#include <find.h>

class GTFind : public ::testing::Test
{
protected:
    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(GTFind, FindMass)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        bool result = false;

        result = SubSearchMass(" i9ih2hfu 9hfu29h9f f2j", "29");
        ASSERT_EQ(result, true);

        result = SubSearchMass("ooonni", "nn");
        ASSERT_EQ(result, true);

        result = SubSearchMass("ooonnipos", "ipos");
        ASSERT_EQ(result, true);

        result = SubSearchMass("ooonnoasbdj nni", "nni");
        ASSERT_EQ(result, true);

        result = SubSearchMass("nninnoasbdj nn7", "nni");
        ASSERT_EQ(result, true);

        result = SubSearchMass("nninnoasbdj nn7", "jklk");
        ASSERT_EQ(result, false);

        result = SubSearchMass("*&*@#*&*%^(#&", "&*%NN");
        ASSERT_EQ(result, false);
    }
}

TEST_F(GTFind, FindPoint)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        bool result = false;

        result = SubSearchPoint(" i9ih2hfu 9hfu29h9f f2j", "29");
        ASSERT_EQ(result, true);

        result = SubSearchPoint("ooonni", "nn");
        ASSERT_EQ(result, true);

        result = SubSearchPoint("ooonnipos", "ipos");
        ASSERT_EQ(result, true);

        result = SubSearchPoint("ooonnoasbdj nni", "nni");
        ASSERT_EQ(result, true);

        result = SubSearchPoint("nninnoasbdj nn7", "nni");
        ASSERT_EQ(result, true);

        result = SubSearchPoint("nninnoasbdj nn7", "jklk");
        ASSERT_EQ(result, false);

        result = SubSearchPoint("*&*@#*&*%^(#&", "&*%NN");
        ASSERT_EQ(result, false);
    }
}

TEST_F(GTFind, SearchLinear)
{
    int size = sizeof(in_value) / sizeof(in_value[0]);
    std::cout << "size=" << size << std::endl;

    int result = SearchLinear(in_value, size, 56);
    std::cout << result << std::endl;
}

#endif // GTFIND_H