#ifndef GTQUEUE_H
#define GTQUEUE_H

#include "queue/queue.h"
#include "wparameters.h"

class GTQueue : public ::testing::Test
{
protected:
    void SetUp() override {};
    void TearDown() override {};
};

TEST_F(GTQueue, AllFunction)
{
    CQueue<char> queue;

    int i = 0;
    while(i++ != COUNT_TEST) {

        {
            std::string in = "123456";

            queue.push(in.data(), in.size());

            const char* out = queue.pop();
            ASSERT_STREQ(out, in.data());
            delete[] out;
        }

        {
            const char* in_0 = "1234567890";
            const char* in_1 = "1234567891";
            const char* in_2 = "1234567892";
            const char* in_3 = "1234567893";

            queue.push(in_0, 10);
            queue.push(in_1, 10);
            queue.push(in_2, 10);
            queue.push(in_3, 10);

            const char* out_0 = queue.pop();
            const char* out_1 = queue.pop();
            const char* out_2 = queue.pop();
            const char* out_3 = queue.pop();

            ASSERT_STREQ(out_0, in_0);
            ASSERT_STREQ(out_1, in_1);
            ASSERT_STREQ(out_2, in_2);
            ASSERT_STREQ(out_3, in_3);
            ASSERT_STREQ(queue.pop(), nullptr);

            delete[] out_0;
            delete[] out_1;
            delete[] out_2;
            delete[] out_3;

            const char* in_4 = "1234567894";
            const char* in_5 = "1234567895";
            const char* in_6 = "1234567896";
            const char* in_7 = "1234567897";

            queue.push(in_4, 10);
            queue.push(in_5, 10);
            queue.push(in_6, 10);
            queue.push(in_7, 10);

            const char* out_4 = queue.pop();
            const char* out_5 = queue.pop();
            const char* out_6 = queue.pop();
            const char* out_7 = queue.pop();

            ASSERT_STREQ(out_4, in_4);
            ASSERT_STREQ(out_5, in_5);
            ASSERT_STREQ(out_6, in_6);
            ASSERT_STREQ(out_7, in_7);
            ASSERT_STREQ(queue.pop(), nullptr);

            delete[] out_4;
            delete[] out_5;
            delete[] out_6;
            delete[] out_7;

            const char* in_8 = "1234567898";
            const char* in_9 = "1234567899";
            const char* in_10 = "12345678910";
            const char* in_11 = "12345678911";

            queue.push(in_8, 10);
            queue.push(in_9, 10);
            queue.push(in_10, 11);
            queue.push(in_11, 11);

            const char* out_8 = queue.pop();
            const char* out_9 = queue.pop();

            ASSERT_STREQ(out_8, in_8);
            ASSERT_STREQ(out_9, in_9);

            delete[] out_8;
            delete[] out_9;

            const char* in_12 = "12345678912";
            const char* in_13 = "12345678913";

            queue.push(in_12, 11);
            queue.push(in_13, 11);

            const char* out_10 = queue.pop();
            const char* out_11 = queue.pop();
            const char* out_12 = queue.pop();
            const char* out_13 = queue.pop();

            ASSERT_STREQ(out_10, in_10);
            ASSERT_STREQ(out_11, in_11);
            ASSERT_STREQ(out_12, in_12);
            ASSERT_STREQ(out_13, in_13);

            delete[] out_10;
            delete[] out_11;
            delete[] out_12;
            delete[] out_13;

            const char* in_14 = "12345678914";
            const char* in_15 = "12345678915";

            queue.push(in_14, 11);
            queue.push(in_15, 11);
        }
    }
}

#endif // GTQUEUE_H