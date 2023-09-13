/*!
\file
\brief main file of the program.
*/

/*! \mainpage matrix program.
*
*
*   meow
*/


#include "header.h"



/*!
 * \brief Runs a program that sorts the lines in a file
 */
int main()
    {
    FILE* file;
    file = fopen("Hamlet.txt", "rb");

    FILE* file1;
    file1  = fopen("output.txt", "w");

    const long BufSize = GetFileSize(file);
    char* Buf = (char*) calloc(BufSize + 1, sizeof(char));

    fread(Buf, sizeof(char), BufSize, file);

    fclose(file);

    int count_n = Number_lines(Buf, BufSize);
    char** text = (char**) calloc(count_n, sizeof(char*));

    replace_slash_n(Buf, BufSize);

    Parsing_pointers(Buf, BufSize, text);

    Sort(text, count_n, Strcmp);

    Output(file1, text, count_n);

    Sort(text, count_n, Strcmp_Reverse);

    Output(file1, text, count_n);

    Output1(file1, Buf, BufSize);

    fclose(file1);

    return 0;
    }



long GetFileSize(FILE* file)
    {
    assert(file);

    fseek(file, 0, SEEK_END);
    long bufsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    return bufsize;
    }



void replace_slash_n(char* Buf, size_t BufSize)
    {
    assert(Buf);

    for (size_t i = 0;  i < BufSize; i++)
        {
        if (*(Buf + i) == '\n')
            {
            *(Buf + i) = '\0';
            }
        }
    }


int Number_lines(char* Buf, size_t BufSize)
    {
    assert(Buf);

    int count_n = 0;
    for (size_t i = 0; i <= BufSize; i++)
        {
        if (*(Buf + i) == '\n')
            {
            count_n++;
            }
        }
    return count_n;
    }


void Parsing_pointers(char* Buf, int bufSize, char** text)
    {
    assert(Buf);
    assert(text);

    int i = 0;
    while (i < bufSize)
        {
        *text++ = Buf + i;
        while (*(Buf + i) != '\0')
            {
            i++;
            }
        i++;
        }

    }


void Output(FILE* file1, char** text, int count_n)
    {
    assert(text);
    assert(file1);

    for (int i = 0; i < count_n - 1; i++)
        {
        if (text[i][0] != '\r')
            {
            fprintf(file1, "%s\n", *(text + i));
            }
        }
    fprintf(file1, "\n");
    fprintf(file1, "\n");
    fprintf(file1, "---------------------------------------------------------------------------------------------------------\n");
    fprintf(file1, "\n");
    fprintf(file1, "\n");
    fprintf(file1, "\n");
    }
















