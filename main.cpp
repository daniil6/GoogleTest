#include "gtest/gtest.h"

#include "brackets/brackets_test.h"
#include "find/find_test.h"
#include "parse_string_v1/parsestring_v1.h"
#include "parse_string_v2/parsestring_v2.h"
#include "parse_string_v3/parsestring_v3.h"
#include "sign/sign_test.h"
#include "simple/passing.h"
#include "sorting/sorting_test.h"
#include "time/wtime_test.h"
#include "validator/validator_test.h"

// ASSERT_EQ(result, false); - прекращает тест
// EXPECT_EQ(result, false); - тест продолжается

int main(int argc, char** argv)
{
    argc++;
    char argvGT0[] = { "--gtest_repeat=1" };
    // argc++;
    // char argvGT1[] = { "--gtest_break_on_failure" };
    // argc++;
    // char argvGT2[] = { "--gtest_filter=GTPassing.*" };

    // argc++;
    // char argvGT2[] = { "--gtest_filter=GTValidator.ValidatorPoint" };

    // argc++;
    // char argvGT2[] = { "--gtest_filter=GTValidator.ValidatorPoint:GTValidator.ValidatorString" };

    // argc++;
    // char argvGT3[] = { "--gtest_filter=GTBrackets.*-GTBrackets.CheckSign" };

    char* chNewArgv[argc] = { argv[0], argvGT0 };

    ::testing::InitGoogleTest(&argc, chNewArgv);

    int result = RUN_ALL_TESTS();
    getchar();
    return result;
}