#ifndef GTLINEINTERPOLATION_H
#define GTLINEINTERPOLATION_H

#include "wparameters.h"

class GTLineInterpolation : public ::testing::Test
{
protected:
    void SetUp() override {};
    void TearDown() override {};
};

void LineInterpolationApp()
{
    double x1 = 0;
    double y1 = 0;
    double x2 = 0;
    double y2 = 0;
    double ix = 0;
    double iy = 0;

    while(1) {

        printf("X1: ");
        scanf("%lf", &x1);

        printf("X2: ");
        scanf("%lf", &x2);

        printf("Y1: ");
        scanf("%lf", &y1);

        printf("Y2: ");
        scanf("%lf", &y2);

        printf("X: ");
        scanf("%lf", &ix);

        if(x2 != x1)
            iy = (y2 - y1) / (x2 - x1) * (ix - x1) + y1;

        printf("Result: %f\n", iy);
    }
}

TEST_F(GTLineInterpolation, LineInterpolation)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        double x1 = 1;
        double y1 = 2;
        double x2 = 3;
        double y2 = 4;
        double ix = 5;
        double iy = 6;

        if(x2 != x1)
            iy = (y2 - y1) / (x2 - x1) * (ix - x1) + y1;

        (void)iy;
    }
}

#endif // GTLINEINTERPOLATION_H