#ifndef GTPASSING_H
#define GTPASSING_H

#include "wparameters.h"

class GTPassing : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};

    void SendReference(int& a){};
    void SendPoint(int* a){};
    void SendMass(int a[]){};
};

TEST_F(GTPassing, SendReference)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        int a = 0;
        SendReference(a);
    }
}

TEST_F(GTPassing, SendPoint)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        int* a = nullptr;
        SendPoint(a);
    }
}

TEST_F(GTPassing, SendMass)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        int a[1] = { 0 };
        SendMass(a);
    }
}

#endif // GTPASSING_H