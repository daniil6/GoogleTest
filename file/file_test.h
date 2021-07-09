#ifndef GTWTIME_H
#define GTWTIME_H

#include "include.h"
#include <win/file.h>

#include <fstream>

#define MB 1048576    // 1 Mb
#define GB 1073741824 // 1 Gb

class GTFile : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
};

TEST_F(GTFile, FillingAskiSymbol)
{
    int size = 256;
    uint8_t data[size] = { 0 };

    for(int i = 0; i < size; i++)
        data[i] = i;

    CFile::CreateWriteFile("aski.txt", (char*)data, size);
}

TEST_F(GTFile, ReadAskiSymbol)
{
    int size = 256;
    uint8_t data[size] = { 0 };

    CFile::OpenReadFile("aski.txt", (char*)data, size);
}

TEST_F(GTFile, Create2GigabyteAtSeekByStream)
{
    /*
    int count = 2;

    std::ofstream ofs("gigabyte.txt", std::ios::binary | std::ios::out);

    ofs.seekp(((uint64_t)GB * count) - 1);
    ofs.write("", 1);
    ofs.close();
    */
}

TEST_F(GTFile, CreateGigabyteThrowCreateFile1) // ???
{
    /*
    for(int i = 0; i < MAIN_COUNT; i++) {

        DWORD bytesWriter = 0;
        uint8_t data[MAX_SIZE]; //  = { '' };

        // int i = 0;
        do {
            data[i] = rand() % 26 + 0 + 'A';
        } while(++i < MAX_SIZE);
        // array[i] = ;

        HANDLE handle = CreateFile("a.txt", GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

        WriteFile(handle, "Z", 10, &bytesWriter, nullptr);

        i = 0;
        do {
            WriteFile(handle, "Z", GB, &bytesWriter, nullptr);
            // WriteFile(handle, "\n", 1, &bytesWriter, nullptr);
        } while(i++ < GB);

        CloseHandle(handle);

        // CFile::CreateWriteFile(std::string("ss_" + std::to_string(i) + ".txt").c_str(), (char*)array, MAX_SIZE);
    }
    */
}

TEST_F(GTFile, CreateGigabyteThrowCreateFile2) // ???
{
    /*
    int i = 0;
    int count = 1024;
    DWORD bytesWriter = 0;

    HANDLE handle = CreateFile("a.txt", GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

    WriteFile(handle, "Z1", GB, &bytesWriter, nullptr);

    do {
        WriteFile(handle, "Z1", MB + 1, &bytesWriter, nullptr);
    } while(i++ < count);

    CloseHandle(handle);
    */
}

TEST_F(GTFile, CreateGigabyteCStyle) // ???
{
    /*
    FILE* fp = fopen("out1.txt", "w");

    char data[MAX_SIZE];

    // this writes the whole array
    fwrite(, 1, MAX_SIZE, fp);
    // so does this
    fwrite(a2, sizeof(a2[0]), 4, fp);
    fseek();
    // this does not write the whole array -- only "Hello" is written
    fprintf(fp, "%s\n", a3);
    // but this does
    fwrite(a3, sizeof(a3[0]), 12, fp);
    fclose(fp);
    */
}

#endif // GTWTIME_H