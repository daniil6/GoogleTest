#include "gtest/gtest.h"

#include "line_interpolation/line_interpolation_test.h"
// #include "parse_string_v1/parse_string_v1_test.h"
// #include "parse_string_v2/parse_string_v2_test.h"
// #include "parse_string_v3/parse_string_v3_test.h"

int main(int argc, char** argv)
{
    argc++;
    char argvGT0[] = { "--gtest_repeat=1" };
    // argc++;
    // char argvGT1[] = { "--gtest_break_on_failure" };
    // argc++;
    // char argvGT2[] = { "--gtest_filter=GTBrackets" };
    // argc++;
    // char argvGT3[] = { "--gtest_filter=GTBrackets.*-GTBrackets.CheckSign" };

    char* chNewArgv[argc] = { argv[0], argvGT0 };

    ::testing::InitGoogleTest(&argc, chNewArgv);
    int result = RUN_ALL_TESTS();
    getchar();
    return result;
}