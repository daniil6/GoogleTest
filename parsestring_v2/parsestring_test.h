#ifndef GTPARSESTRING_H
#define GTPARSESTRING_H

#include <parse_string_v2/parsestring_v2.h>

#include "wparameters.h"

class GTParseString : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

// std::string in = { "-x0-x1*x2/x3*5+x4*x5+x6-x7-x8+x9-x10-x11+x12*x13" };
// std::string in = { "x0-x1*x2-x3+x4*x5+(x6*x7)+x8" };
// std::string in = { "-x0-x1*x2-x3+x4*x5+(x6-(x7-x8)+(x9-x10)*8/(-x11))+x12*x13" };

TEST_F(GTParseString, Make)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        CParseStringV2 parse;
        TParseResult result;
        StringTree* tree = nullptr;
        StringTree* root = nullptr;

        parse.Make("1-2+3", result);
        ASSERT_EQ(result.value, 2);
        root = result.stringTree;
        tree = root;
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        parse.DeleteParseResult(result);

        parse.Make("1-2*3", result);
        ASSERT_EQ(result.value, -5);
        root = result.stringTree;
        tree = root;
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        tree = tree->GetRight();
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "2");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        parse.DeleteParseResult(result);

        parse.Make("(1-2)*3", result);
        ASSERT_EQ(result.value, -3);
        root = result.stringTree;
        tree = root;
        ASSERT_STREQ(&tree->m_data[0], "*");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "-");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "2");
        parse.DeleteParseResult(result);

        parse.Make("-2+(3*4-2)*47/2-(-4+3)/2+(2-7*5)", result);
        ASSERT_EQ(result.value, 200.5);
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
        parse.DeleteParseResult(result);

        parse.Make("x1+x2+x3", result);
        ASSERT_EQ(result.value, 0);
        root = result.stringTree;
        tree = root;
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "+");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "x3");
        tree = tree->GetLeft();
        ASSERT_STREQ(&tree->m_data[0], "+");
        ASSERT_STREQ(&tree->GetLeft()->m_data[0], "x1");
        ASSERT_STREQ(&tree->GetRight()->m_data[0], "x2");
        parse.DeleteParseResult(result);

        parse.Make("-3-4*2-6+2*50+(4-(1-2)+8-(3-4)*(-1))", result);
        ASSERT_EQ(result.value, 95);
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
};

#endif // GTPARSESTRING_H
