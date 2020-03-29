#include "gtest/gtest.h"

#include "brackets/check_test.h"
#include "time/wtime_test.h"

int main(int argc, char** argv)
{
    argc++;
    char argvGT0[] = { "--gtest_repeat=2" };
    argc++;
    char argvGT1[] = { "--gtest_break_on_failure" };
    argc++;
    char argvGT2[] = { "--gtest_filter=GTBrackets" };
    // argc++;
    // char argvGT3[] = { "--gtest_filter=GTBrackets.*-GTBrackets.CheckSign" };

    char* chNewArgv[argc] = { argv[0], argvGT0, argvGT1, argvGT2 };

    ::testing::InitGoogleTest(&argc, chNewArgv);
    // return RUN_ALL_TESTS();
    RUN_ALL_TESTS();
    getchar();
}