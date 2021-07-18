#ifndef GTPARSE_STRING_V1_TEST_H
#define GTPARSE_STRING_V1_TEST_H

#include "wparameters.h"
#include <parse_string_v1/parsestring_v1.h>

class GTParseString_v1 : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

// COUNT_TEST == 1000
// [----------] 1 test from GTParseString_v1
// [ RUN      ] GTParseString_v1.ParseString_v1
// [       OK ] GTParseString_v1.ParseString_v1 (777 ms)
// [----------] 1 test from GTParseString_v1 (783 ms total)

TEST_F(GTParseString_v1, ParseString_v1)
{
    int i = 0;
    while(i++ < COUNT_TEST) {

        CParseStringV1 parse;
        StringTree* tree = nullptr;
        StringTree* root = nullptr;

        tree = parse.Make("1-2+3");

        // ASSERT_DOUBLE_EQ(result.value, 2);
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "3");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");

        tree = parse.Make("1-2*3");
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "1");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "3");
        // ASSERT_DOUBLE_EQ(result.value, -5);

        tree = parse.Make("(1-2)*3");
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "3");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        // ASSERT_DOUBLE_EQ(result.value, -3);

        root = parse.Make("-2+(3*4-2)*47/2-(-4+3)/2+(2-7*5)");

        tree = root->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "*");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "7");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "5");

        tree = root->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "/");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "/");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "3");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "0");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "4");

        tree = root->GetRight()->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "/");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "/");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "47");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "4");

        tree = root->GetRight()->GetRight()->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "0");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        // ASSERT_DOUBLE_EQ(result.value, 200.5);

        tree = parse.Make("x1+x2+x3");
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "x3");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "x1");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "x2");
        // ASSERT_DOUBLE_EQ(result.value, 0);

        root = parse.Make("-3-4*2-6+2*50+(4-(1-2)+8-(3-4)*(-1))");

        ASSERT_STREQ(&root->m_data[0], "+");
        ASSERT_STREQ(&root->GetRight()->m_data[0], "+");
        ASSERT_STREQ(&root->GetLeft()->m_data[0], "-");
        tree = root->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "*");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "50");
        tree = root->GetRight()->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "6");
        tree = root->GetRight()->GetRight()->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "*");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "4");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        tree = root->GetRight()->GetRight()->GetRight()->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "0");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "3");

        tree = root->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "*");
        tree = root->GetLeft()->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "0");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        tree = root->GetLeft()->GetLeft()->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "4");

        tree = root->GetLeft()->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "8");

        tree = root->GetLeft()->GetRight()->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "4");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "-");

        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        // ASSERT_DOUBLE_EQ(result.value, 95);

        root = parse.Make("(3+4)*5");
        ASSERT_STREQ(&root->m_data[0], "*");
        ASSERT_STREQ(&root->GetRight()->m_data[0], "+");
        ASSERT_STREQ(&root->GetLeft()->m_data[0], "5");

        tree = root->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "4");
        // ASSERT_DOUBLE_EQ(result.value, 35);

        root = parse.Make("3+4*5");
        ASSERT_STREQ(&root->m_data[0], "+");
        ASSERT_STREQ(&root->GetRight()->m_data[0], "3");
        ASSERT_STREQ(&root->GetLeft()->m_data[0], "*");

        tree = root->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "4");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "5");
        // ASSERT_DOUBLE_EQ(result.value, 23);
    }
}

#endif // GTPARSE_STRING_V1_TEST_H