#include <gtest/gtest.h>

#define COUNT 1

// #define COUNT 150000000
// Array: 38 sec 773 ms
// Point: 32 sec 597 ms

class GTArrayVsPoint : public ::testing::Test
{
protected:
    GTArrayVsPoint() = default;
    ~GTArrayVsPoint() override = default;

    void SetUp() override{};
    void TearDown() override {};
};

void ASSERT_ARRAY(const char* aData, const int& aSize, const char* bData, const int& bSize)
{
    uint8_t av = 0;
    uint8_t bv = 0;
    size_t size = aSize;

    for(size_t i = 0; i < size; i++) {

        av = aData[i];
        bv = bData[i];

        EXPECT_EQ(av, bv);
        if(av != bv) {
            ASSERT_EQ(i, size_t(0));
        }
    }
}

int array(const char* data, const int& size, const char& ch)
{
    int count = 0;
    for(; count < size; count++) {
        if(count[data] == ch) {
            return count;
        }
    }

    return -1;
}

int array2(const char* data, const int& size, const char& ch)
{
    int count = 0;
    do {
        if(data[count] == ch) {
            return count;
        }
    } while(count++ < size);

    return -1;
}

int point(const char* data, const int& size, const char& ch)
{
    int count = size;

    do {
        if(*data++ == ch)
            return size - count;
    } while(count--);

    return -1;
}

TEST_F(GTArrayVsPoint, Array)
{
    for(int i = 0; i < COUNT; i++) {

        int result = 0;

        result = array("hjdsfdsafadsfasdfasdfas2djh", 27, '2');
        ASSERT_EQ(result, 23);

        result = array("hjsadfadsfasdfadsfas2dj3", 24, '3');
        ASSERT_EQ(result, 23);

        result = array("hjsadfadsfahe82beu2hb9cB9U89gGU(Bvd3n0B)UH0PGDsdfadsfas2djMMK<ASNPDOOASmQ", 73, 'Q');
        ASSERT_EQ(result, 72);

        result = array("Qjsadfadsfahe82beu2hb9cB9U89gGU(Bvd3n0B)UH0PGDsdfadsfas2djMMK<ASNPDOOASmQ", 73, 'Q');
        ASSERT_EQ(result, 0);
    }
}

TEST_F(GTArrayVsPoint, Array2)
{
    for(int i = 0; i < COUNT; i++) {

        int result = 0;

        result = array2("hjdsfdsafadsfasdfasdfas2djh", 27, '2');
        ASSERT_EQ(result, 23);

        result = array2("hjsadfadsfasdfadsfas2dj3", 24, '3');
        ASSERT_EQ(result, 23);

        result = array2("hjsadfadsfahe82beu2hb9cB9U89gGU(Bvd3n0B)UH0PGDsdfadsfas2djMMK<ASNPDOOASmQ", 73, 'Q');
        ASSERT_EQ(result, 72);

        result = array2("Qjsadfadsfahe82beu2hb9cB9U89gGU(Bvd3n0B)UH0PGDsdfadsfas2djMMK<ASNPDOOASmQ", 73, 'Q');
        ASSERT_EQ(result, 0);
    }
}

TEST_F(GTArrayVsPoint, Point)
{
    for(int i = 0; i < COUNT; i++) {

        int result = 0;

        result = point("hjdsfdsafadsfasdfasdfas2djh", 27, '2');
        ASSERT_EQ(result, 23);

        result = point("hjsadfadsfasdfadsfas2dj3", 24, '3');
        ASSERT_EQ(result, 23);

        result = point("hjsadfadsfahe82beu2hb9cB9U89gGU(Bvd3n0B)UH0PGDsdfadsfas2djMMK<ASNPDOOASmQ", 73, 'Q');
        ASSERT_EQ(result, 72);

        result = point("Qjsadfadsfahe82beu2hb9cB9U89gGU(Bvd3n0B)UH0PGDsdfadsfas2djMMK<ASNPDOOASmQ", 73, 'Q');
        ASSERT_EQ(result, 0);
    }
}