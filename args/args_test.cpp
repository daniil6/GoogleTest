#include <gtest/gtest.h>

#include <iostream>

#include "args.h"

class GTArgs : public ::testing::Test
{
protected:
    GTArgs() = default;
    ~GTArgs() override = default;

    void SetUp() override {};
    void TearDown() override {};
};

int a(const SKey& key)
{
    std::cout << key.data << " : ";
    for(auto& arg : key.args) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    return 0;
}

int p(const SKey& key)
{
    std::cout << key.data << " : ";
    for(auto& arg : key.args) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    return 0;
}

int f(const SKey& key)
{
    std::cout << key.data << " : ";
    for(auto& arg : key.args) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    return 0;
}

int z(const SKey& key)
{
    std::cout << key.data << " : ";
    for(auto& arg : key.args) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    return 0;
}

int o(const SKey& key)
{
    std::cout << key.data << " : ";
    for(auto& arg : key.args) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    return 0;
}

int l(const SKey& key)
{
    std::cout << key.data << " : ";
    for(auto& arg : key.args) {
        std::cout << arg << " ";
    }
    std::cout << std::endl;
    return 0;
}

TEST_F(GTArgs, Args)
{
    int argc = 1;
    const char* argv[] = { "app.exe", "-a", "s:a", "-p", "s:p", "-f", "s:f", "-z", "s:z", "-o", "s:o", "-l", "s:l" };

    CArgs args;

    args.add("-a", 2, &a);
    args.add("-p", 2, &p);
    args.add("-f", 2, &f);
    args.add("-z", 2, &z);
    args.add("-o", 2, &o);
    args.add("-l", 2, &l);

    args.parse(argc, const_cast<char**>(argv)); // NOT WORKS
}