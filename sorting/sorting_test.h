#ifndef GTSORTING_H
#define GTSORTING_H

#include "sorting.h"
#include "wparameters.h"

#include <gmock\gmock-matchers.h>

class GTSorting : public ::testing::Test
{
protected:
    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(GTSorting, BubbleSort)
{
    int i = 0;

    while(i++ != COUNT_TEST) {

        int arrayOut[] = { 9, 9, 8, 8, 8, 7, 6, 4, 4, 3, 3, 2, 2, 0 };

        int array[] = { 7, 8, 9, 2, 6, 3, 8, 9, 4, 2, 3, 8, 4, 0 };
        int size = sizeof(array) / sizeof(array[0]);

        BubbleSort(array, size - 1);
        EXPECT_THAT(array, testing::ContainerEq(arrayOut));
    }
}
#endif // GTSORTING_H