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

        result = SubSearchMass("SS", "SS");
        ASSERT_EQ(result, true);
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

        result = SubSearchPoint("SS", "SS");
        ASSERT_EQ(result, true);
    }
}

TEST_F(GTFind, SearchThread)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        int result = 0;

        result = searchThread(" i9ih2hfu 9hfu29h9f f2j", 23, "29", 2);
        ASSERT_EQ(result, 16);

        result = searchThread("ooonni", 6, "nn", 2);
        ASSERT_EQ(result, 5);

        result = searchThread("ooonnipos", 9, "ipos", 4);
        ASSERT_EQ(result, 9);

        result = searchThread("ooonnoasbdj nni", 15, "nni", 3);
        ASSERT_EQ(result, 15);

        result = searchThread("nninnoasbdj nn7", 16, "nni", 3);
        ASSERT_EQ(result, 3);

        result = searchThread("nninnoasbdj nn7", 16, "jklk", 5);
        ASSERT_EQ(result, -1);

        result = searchThread("*&*@#*&*%^(#&", 14, "&*%NN", 6);
        ASSERT_EQ(result, -1);

        result = searchThread("SS", 2, "SS", 2);
        ASSERT_EQ(result, 2);
    }
}

TEST_F(GTFind, SearchLinear)
{
    int size = sizeof(in_value) / sizeof(in_value[0]);
    // printf("Size in value: %d\n", size);

    int result = SearchLinear(in_value, size, 56);
    ASSERT_EQ(result, 56);
}

#endif // GTFIND_H