/*!
\file
\brief File with sorting functions

This file sorts lines from the beginning and from the end
*/


#include "header.h"


void Sort(void* text1, size_t text_len, int (*CompFunc)(const void* s1, const void* s2))
    {
    assert(text1);

    char** text = (char**) text1;
    for (size_t i = 0; i < text_len; i++)
        {
        for (size_t j = 0; j < text_len - 1; j++)
            {
            if (CompFunc(text[j], text[j + 1]) > 0)
                {
                char* tmp = text[j];
                text[j] = text[j + 1];
                text[j + 1] = tmp;
                }
            }
        }
    }


/*void qSort(void* text1, size_t left, size_t right, int (*CompFunc)(const void* s1, const void* s2))
    {
    char** text = (char**) text1;

    size_t first = 0, last = 0, pivot = 0;
    if (left >= right)
        {
        return;
        }
    else
        {
        pivot = (left + right) / 2;
        first = left;
        last = right;
        while (first <= last)
            {
            while (CompFunc(text[first], text[pivot]) <= 0)
                {
                first++;
                }
            while (CompFunc(text[last], text[pivot]) > 0)
                {
                last--;
                }
            if (first >= last)
                {
                break;
                }
            Swap(text, first++, last--);
            }

        qSort(text, left, last, CompFunc);
        qSort(text, last + 1, right, CompFunc);
        }
    }
*/

int Strcmp(const void* s1, const void* s2)
    {
    assert(s1 && s2);

    const char* str1 = (const char*) s1;
    const char* str2 = (const char*) s2;

    char garbage[] = {' ', ',', '`', '!', '?', '-', '^', ';', ':', '>', '.', '(', ')', '{', '}', '[', ']', '"', '\'', '\0'};

    int i = 0;
    int j = 0;

    while (true)
        {
        if (strchr(garbage, str1[i]) != NULL)
            {
            i++;
            continue;
            }
        if (strchr(garbage, str2[j]) != NULL)
            {
            j++;
            continue;
            }

        if (toupper(str1[i]) != toupper(str2[j]))
            {
            break;
            }
        if (str1[i] == '\0')
            {
            break;
            }
        i++;
        j++;
        }

    return (toupper(str1[i]) - toupper(str2[j]));
    }


int Strcmp_Reverse(const void* s1, const void* s2)
    {
    assert(s1 && s2);

    const char* str1 = (const char*) s1;
    const char* str2 = (const char*) s2;

    char garbage[] = {' ', ',', '`', '!', '?', '-', '^', ';', ':', '>', '.', '(', ')', '{', '}', '[', ']', '"', '\'', '\0'};

    int i = strlen(str1) - 1;
    int j = strlen(str2) - 1;
    while (i > 0 && j > 0)
        {
        if (strchr(garbage, str1[i]) != NULL)
            {
            i--;
            continue;
            }
        if (strchr(garbage, str2[j]) != NULL)
            {
            j--;
            continue;
            }

        if (toupper(str1[i]) != toupper(str2[j]))
            {
            break;
            }
        i--;
        j--;
        }

    return (toupper(str1[i]) - toupper(str2[j]));
    }

/*
void Swap(char** text, size_t i, size_t j)
    {
    char* tmp;
    tmp = text[i];
    text[i] = text[j];
    text[j] = tmp;
    }
*/

void Output1(FILE* file1, char* Buf, size_t BufSize)
    {
    assert(file1);
    assert(Buf);

    fwrite(Buf, sizeof(char), BufSize, file1);
    }
