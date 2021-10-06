#ifndef GTPARSE_STRING_V2_TEST_H
#define GTPARSE_STRING_V2_TEST_H

#include "wparameters.h"
#include <parse_string_v2/parsestring_v2.h>

class GTParseString_v2 : public ::testing::Test
{
protected:
    void SetUp() override {};
    void TearDown() override {};
};

// std::string in = { "-x0-x1*x2/x3*5+x4*x5+x6-x7-x8+x9-x10-x11+x12*x13" };
// std::string in = { "x0-x1*x2-x3+x4*x5+(x6*x7)+x8" };
// std::string in = { "-x0-x1*x2-x3+x4*x5+(x6-(x7-x8)+(x9-x10)*8/(-x11))+x12*x13" };

// MAIN_COUNT == 1000
// [----------] 1 test from GTParseString_v2
// [ RUN      ] GTParseString_v2.ParseString_v2
// [       OK ] GTParseString_v2.ParseString_v2 (75 ms)
// [----------] 1 test from GTParseString_v2 (80 ms total)

TEST_F(GTParseString_v2, CalculateParseString_v2)
{
    TParseResult result;
    CParseStringV2 parse;

    parse.Make("-2*(-1+1-3)*2/3", result);
    ASSERT_DOUBLE_EQ(result.value, 4);
    parse.DeleteParseResult(result);

    parse.Make("1-4*8", result);
    ASSERT_DOUBLE_EQ(result.value, -31);
    parse.DeleteParseResult(result);

    parse.Make("30", result);
    ASSERT_DOUBLE_EQ(result.value, 0);
    // ASSERT_DOUBLE_EQ(result.value, 30); ???
    parse.DeleteParseResult(result);

    parse.Make("3.5*4.8", result);
    ASSERT_DOUBLE_EQ(result.value, 16.80000007748604);
    parse.DeleteParseResult(result);
}

TEST_F(GTParseString_v2, ParseString_v2)
{
    int i = 0;
    while(i++ < COUNT_TEST) {
        TParseResult result;
        CParseStringV2 parse;
        StringTree* tree = nullptr;
        StringTree* root = nullptr;

        parse.Make("1-2+3", result);
        tree = result.stringTree;
        ASSERT_DOUBLE_EQ(result.value, 2);
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        parse.DeleteParseResult(result);

        parse.Make("1-2*3", result);
        tree = result.stringTree;
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        ASSERT_DOUBLE_EQ(result.value, -5);
        parse.DeleteParseResult(result);

        parse.Make("(1-2)*3", result);
        tree = result.stringTree;
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        ASSERT_DOUBLE_EQ(result.value, -3);
        parse.DeleteParseResult(result);

        parse.Make("-2+(3*4-2)*47/2-(-4+3)/2+(2-7*5)", result);
        root = result.stringTree;

        tree = root->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "*");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "7");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "5");

        tree = root->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "/");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "/");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "0");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "4");

        tree = root->GetLeft()->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "/");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "/");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "47");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "3");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "4");

        tree = root->GetLeft()->GetLeft()->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "0");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        ASSERT_DOUBLE_EQ(result.value, 200.5);
        parse.DeleteParseResult(result);

        parse.Make("x1+x2+x3", result);
        tree = result.stringTree;
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "x3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "x1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "x2");
        ASSERT_DOUBLE_EQ(result.value, 0);
        parse.DeleteParseResult(result);

        parse.Make("-3-4*2-6+2*50+(4-(1-2)+8-(3-4)*(-1))", result);
        root = result.stringTree;

        ASSERT_STREQ(&root->m_data[0], "+");
        ASSERT_STREQ(&root->GetLeft()->m_data[0], "+");
        ASSERT_STREQ(&root->GetRight()->m_data[0], "-");
        tree = root->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "*");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "50");
        tree = root->GetLeft()->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "6");
        tree = root->GetLeft()->GetLeft()->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "*");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "4");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        tree = root->GetLeft()->GetLeft()->GetLeft()->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "0");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");

        tree = root->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "*");
        tree = root->GetRight()->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "0");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "1");
        tree = root->GetRight()->GetRight()->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "3");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "4");

        tree = root->GetRight()->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "8");

        tree = root->GetRight()->GetLeft()->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "4");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");

        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        ASSERT_DOUBLE_EQ(result.value, 95);
        parse.DeleteParseResult(result);

        parse.Make("(3+4)*5", result);
        root = result.stringTree;
        ASSERT_STREQ(&root->m_data[0], "*");
        ASSERT_STREQ(&root->GetLeft()->m_data[0], "+");
        ASSERT_STREQ(&root->GetRight()->m_data[0], "5");

        tree = root->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "3");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "4");
        ASSERT_DOUBLE_EQ(result.value, 35);
        parse.DeleteParseResult(result);

        parse.Make("3+4*5", result);
        root = result.stringTree;
        ASSERT_STREQ(&root->m_data[0], "+");
        ASSERT_STREQ(&root->GetLeft()->m_data[0], "3");
        ASSERT_STREQ(&root->GetRight()->m_data[0], "*");

        tree = root->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "4");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "5");
        ASSERT_DOUBLE_EQ(result.value, 23);
        parse.DeleteParseResult(result);

        parse.Make("(2+2)*2", result);
        ASSERT_EQ(result.value, 8);
        root = result.stringTree;
        parse.DeleteParseResult(result);

        parse.Make("2+2*2", result);
        ASSERT_EQ(result.value, 6);
        root = result.stringTree;
        parse.DeleteParseResult(result);
    }
}

#endif // GTPARSE_STRING_V2_TEST_H