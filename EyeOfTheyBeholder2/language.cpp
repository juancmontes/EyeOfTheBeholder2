#pragma warning(disable : 4996)

#include "language.h"
#include <cstdio>
#include <string>

void Language::init(short language = 0)
{
    // 0 = English, 1 = German
    FILE* file;
    std::string fileName;
    if (language == 0)
        fileName = "data/english.lang";
    if (language == 1)
        fileName = "data/german.lang";

    file = fopen(fileName.c_str(), "r");

    char data[512];
    short arrayPointer = 0;
    while (!feof(file)) {
        fgets(data, 512, file);
        if (strlen(data) > 1) {
            data[strlen(data) - 1] = '\0';
            mText[arrayPointer++] = strdup(data);
        }
        data[0] = '\0';
    }
    fclose(file);
}
