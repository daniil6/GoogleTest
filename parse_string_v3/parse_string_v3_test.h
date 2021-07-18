#ifndef GTPARSE_STRING_V3_TEST_H
#define GTPARSE_STRING_V3_TEST_H

#include "wparameters.h"
#include <parse_string_v3/parsestring_v3.h>

class GTParseString_v3 : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

// MAIN_COUNT == 1000
// [----------] 1 test from GTParseString_v3
// [ RUN      ] GTParseString_v3.ParseString_v3
// [       OK ] GTParseString_v3.ParseString_v3 (210 ms)
// [----------] 1 test from GTParseString_v3 (215 ms total)

TEST_F(GTParseString_v3, CalculateParseString_v3)
{
    CParseStringV3 parse;
    CStringTree* tree = nullptr;

    tree = parse.Make("-2*(-1+1-3)*2/3");
    parse.Calculate(tree);
    ASSERT_DOUBLE_EQ(tree->GetSecond(), 4);

    tree = parse.Make("1-4*8");
    parse.Calculate(tree);
    ASSERT_DOUBLE_EQ(tree->GetSecond(), -31);

    tree = parse.Make("30");
    parse.Calculate(tree);
    ASSERT_DOUBLE_EQ(tree->GetSecond(), 30);

    tree = parse.Make("3.5*4.8");
    parse.Calculate(tree);
    ASSERT_DOUBLE_EQ(tree->GetSecond(), 16.8);
}

TEST_F(GTParseString_v3, ParseString_v3)
{
    int i = 0;
    while(i++ < COUNT_TEST) {

        CParseStringV3 parse;
        CStringTree* tree = nullptr;
        CStringTree* root = nullptr;

        root = tree = parse.Make("1-2+3");
        parse.Calculate(tree);
        ASSERT_DOUBLE_EQ(tree->GetSecond(), 2);
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        CParseStringV3::DeleteTree(root);

        root = tree = parse.Make("1-2*3");
        parse.Calculate(tree);
        ASSERT_DOUBLE_EQ(tree->GetSecond(), -5);
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        CParseStringV3::DeleteTree(root);

        root = tree = parse.Make("(1-2)*3");
        parse.Calculate(tree);
        ASSERT_DOUBLE_EQ(tree->GetSecond(), -3);
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        CParseStringV3::DeleteTree(root);

        root = parse.Make("-2+(3*4-2)*47/2-(-4+3)/2+(2-7*5)");
        parse.Calculate(root);
        ASSERT_DOUBLE_EQ(root->GetSecond(), 200.5);

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
        CParseStringV3::DeleteTree(root);

        root = tree = parse.Make("x1+x2+x3");

        try {
            parse.Calculate(tree);
        } catch(const ErrorParse& err) {
            ASSERT_EQ(err, ErrorMapPoint);
        }
        ASSERT_DOUBLE_EQ(tree->GetSecond(), 0);
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "x3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "x1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "x2");
        CParseStringV3::DeleteTree(root);

        root = parse.Make("-3-4*2-6+2*50+(4-(1-2)+8-(3-4)*(-1))");
        parse.Calculate(root);
        ASSERT_DOUBLE_EQ(root->GetSecond(), 95);

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
        CParseStringV3::DeleteTree(root);

        root = parse.Make("(3+4)*5");
        parse.Calculate(root);
        ASSERT_DOUBLE_EQ(root->GetSecond(), 35);
        ASSERT_STREQ(&root->m_data[0], "*");
        ASSERT_STREQ(&root->GetLeft()->m_data[0], "+");
        ASSERT_STREQ(&root->GetRight()->m_data[0], "5");

        tree = root->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "3");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "4");
        CParseStringV3::DeleteTree(root);

        root = parse.Make("3+4*5");
        parse.Calculate(root);
        ASSERT_DOUBLE_EQ(root->GetSecond(), 23);
        ASSERT_STREQ(&root->m_data[0], "+");
        ASSERT_STREQ(&root->GetLeft()->m_data[0], "3");
        ASSERT_STREQ(&root->GetRight()->m_data[0], "*");

        tree = root->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "4");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "5");
        CParseStringV3::DeleteTree(root);
    }
}

#endif // GTPARSE_STRING_V3_TEST_H