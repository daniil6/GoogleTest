#include "gtest/gtest.h"

#include "sign/sign_test.h"
//#include "brackets/brackets_test.h"
//#include "simple/passing.h"
//#include "time/wtime_test.h"
//#include "validator/validator_test.h"

int main(int argc, char** argv)
{
    argc++;
    char argvGT0[] = { "--gtest_repeat=1" };
    argc++;
    char argvGT1[] = { "--gtest_break_on_failure" };
    // argc++;
    // char argvGT2[] = { "--gtest_filter=GTPassing.*" };

    // argc++;
    // char argvGT2[] = { "--gtest_filter=GTBrackets.SenReference:GTBrackets.SenPoint:GTBrackets.SenMass" };

    // argc++;
    // char argvGT3[] = { "--gtest_filter=GTBrackets.*-GTBrackets.CheckSign" };

    char* chNewArgv[argc] = { argv[0], argvGT0, argvGT1 };

    ::testing::InitGoogleTest(&argc, chNewArgv);
    // return RUN_ALL_TESTS();
    RUN_ALL_TESTS();
    getchar();
}