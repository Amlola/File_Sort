/*!
\file
\brief File with sorting functions
This file sorts lines from the beginning and from the end
*/


#include "header.h"


void bubble_Sort(void* text1, size_t text_len, int (*CompFunc)(const void* s1, const void* s2))
    {
    assert(text1);
    String* text = (String*)text1;
    for (size_t i = 0; i < text_len; i++)
        {
        for (size_t j = 0; j < text_len - 1; j++)
            {
            if (CompFunc((text + j), (text + j + 1)) > 0)
                {
                SwapStrings((text + j), (text + j + 1));
                }
            }
        }
    }


void qSort(void* text1, size_t left, size_t right, int (*CompFunc)(const void* s1, const void* s2))
    {
    assert(text1);
    String* text = (String*) text1;
    size_t first = 0, last = 0, pivot = 0;

    if (left >= right)
        {
        return;
        }

    pivot = (left + right) / 2;
    first = left;
    last  = right;
    while (first <= last)
        {
        while (first <= last && CompFunc((text + first), (text + pivot)) < 0)
            {
            first++;
            }

        while (last >= 0 && CompFunc((text + last), (text + pivot)) > 0)
            {
            last--;
            }

        if (first >= last)
            {
            break;
            }

        SwapStrings((text + first), (text + last));
        ++first;
        --last;
        }

    qSort(text, left, last, CompFunc);
    qSort(text, last + 1, right, CompFunc);
    }


bool is_valid(char symbol)
    {
    return ('a' <= symbol && symbol <= 'z') || ('A' <= symbol && symbol <= 'Z');  //isalpha, but i dont like it :(((
    }


int find_valid(const String* str, int start, int delta)
    {
    for (int i = start; i >= 0 && i < str->length; i += delta)
        {
        char symbol = *(str->adress + i);

        if (is_valid(symbol))
            {
            return i;
            }
        }

    return -1;
    }


int Strcmp(const void* s1, const void* s2)
    {
    assert(s1);
    assert(s2);

    const String* str1 = (const String*) s1;
    const String* str2 = (const String*) s2;

    int i = 0;
    int j = 0;

    while (i < str1->length && j < str2->length)
        {
        int pos_i = find_valid(str1, i, 1);
        int pos_j = find_valid(str2, j, 1);

        if (pos_i == -1 && pos_j == -1)
            {
            return 0;
            }

        else if (pos_i == -1)
            {
            return 1;
            }

        else if (pos_j == -1)
            {
            return -1;
            }

        int delta = (toupper(*(str1->adress + pos_i)) - toupper(*(str2->adress + pos_j)));
        if (delta != 0)
            {
            return delta;
            }

        i = pos_i + 1;
        j = pos_j + 1;
        }

    return 0;
    }


int Strcmp_Reverse(const void* s1, const void* s2)
    {
    assert(s1);
    assert(s2);

    const String* str1 = (const String*) s1;
    const String* str2 = (const String*) s2;

    int i = str1->length - 1;
    int j = str2->length - 1;

    while (i >= 0 && j >= 0)
        {
        int pos_i = find_valid(str1, i, -1);
        int pos_j = find_valid(str2, j, -1);

        if (pos_i == -1 && pos_j == -1)
            {
            return 0;
            }

        else if (pos_i == -1)
            {
            return 1;
            }

        else if (pos_j == -1)
            {
            return -1;
            }

        int delta = (toupper(*(str1->adress + pos_i)) - toupper(*(str2->adress + pos_j)));
        if (delta != 0)
            {
            return delta;
            }

        i = pos_i - 1;
        j = pos_j - 1;

        }

    return 0;
    }


void SwapStrings(struct String* a, struct String* b)
    {
    struct String tmp = *b;
    *b = *a;
    *a = tmp;
    }


void OutputSourceFile(FILE* file1, char* Buf, size_t BufSize)
    {
    assert(file1);
    assert(Buf);

    int written = fwrite(Buf, sizeof(char), BufSize, file1);
    assert(written != BufSize + 1);
    }
