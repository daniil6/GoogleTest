#ifndef GTWTIME_H
#define GTWTIME_H

#include "wparameters.h"

class GTWTime : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

TEST_F(GTWTime, CheckSignShowCompactError)
{
}

#endif // GTWTIME_H