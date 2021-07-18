#ifndef GTWTIME_H
#define GTWTIME_H

class GTTime : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

TEST_F(GTTime, ShowTimeApp)
{
    unsigned int start_time = clock(); // Start time

    // App

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    printf("%d\n", search_time);
    system("pause");
}

TEST_F(GTTime, CheckSignShowCompactError)
{
}

#endif // GTWTIME_H