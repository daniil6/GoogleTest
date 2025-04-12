#ifndef GTREPLACE_H
#define GTREPLACE_H

#include "wparameters.h"
#include <algorithm>

class GTReplace : public ::testing::Test
{
protected:
    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(GTReplace, String)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        std::string address = "f0:79:59:1d:29:82";

        for(auto itr = address.begin(); itr != address.end(); ++itr)
            if(*itr == ':')
                address.erase(itr);

        ASSERT_STREQ(address.data(), "f079591d2982");
    }
}

TEST_F(GTReplace, Array)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        uint8_t ch = 0;
        uint8_t count = 0;

        const char* address = "f0:79:59:1d:29:82\0";

        uint8_t size = 0;

        // const char* p = address;
        // while(*p++ != '\0')
        //     size++;

        size = strlen(address);

        char result[size] = { 0 };

        while((ch = *address++) != '\0')
            if(ch != ':')
                result[count++] = ch;

        ASSERT_STREQ(result, "f079591d2982");
    }
}

TEST_F(GTReplace, StringArray)
{
    int i = 0;
    while(i++ != COUNT_TEST) {

        std::string address = "f0:79:59:1d:29:82";

        std::string result;

        uint8_t size = std::count(address.begin(), address.end(), ':');

        std::string split[size + 1];

        int count = 0;
        for(auto& p : address)
            if(p != ':')
                split[count].push_back(p);
            else
                count++;

        for(auto& p : split)
            result.append(p);

        ASSERT_STREQ(result.data(), "f079591d2982");
    }
}

#endif // GTREPLACE_H