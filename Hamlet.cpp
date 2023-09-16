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

    Text data {};

    FILE* file = fopen("hamlet1.txt", "rb");

    File_input(file, &data);

    FILE* file1 = fopen("output.txt", "w");

    //qSort(text, 0, count_n - 1, Strcmp);
    //bubble_Sort(text, count_n, Strcmp);

    qsort(data.str, data.count_n, sizeof(String), Strcmp);

    Output(file1, data.str, data.count_n);

    qSort(data.str, 0, data.count_n - 1, Strcmp_Reverse);

    Output(file1, data.str, data.count_n);

    OutputSourceFile(file1, data.Buf, data.BufSize);

    fclose(file1);

    Free(&data);

    return 0;
    }


long long GetFileSize(FILE* file)
    {
    assert(file);

    long long start = ftell(file);
    fseek(file, start, SEEK_END);

    long long bufsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    return bufsize;
    }


void replace_slash_n(char* Buf, size_t BufSize)
    {
    assert(Buf);

    for (size_t i = 0; i < BufSize; i++)
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
    for (size_t i = 0; i < BufSize; i++)
        {
        if (*(Buf + i) == '\n')
            {
            count_n++;
            }
        }

    return count_n + 1;
    }


void Parsing_pointers(char* Buf, int bufSize, String* text)
    {
    assert(Buf);
    assert(text);

    int i = 0;
    while (i < bufSize)
        {
        text->adress = Buf + i;
        text->length = strlen(text->adress);
        ++text;

        while (*(Buf + i) != '\0')
            {
            i++;
            }

        i++;
        }
    }


void Output(FILE* file1, String* text, int count_n)
    {
    assert(text);
    assert(file1);

    for (int i = 0; i < count_n; i++)
        {
        if ((*((text + i)->adress)) != '\r')
            {
            fprintf(file1, "%s\n", ((text + i)->adress));
            }
        }
    fprintf(file1, "\n");
    fprintf(file1, "\n");
    fprintf(file1, "---------------------------------------------------------------------------------------------------------\n");
    fprintf(file1, "\n");
    fprintf(file1, "\n");
    fprintf(file1, "\n");
    }


void OutputToCmd(String* text, int count_n)
    {
    assert(text);

    for (int i = 0; i < count_n; i++)
        {
        if ((*((text + i)->adress)) != '\r')
            {
            printf("%s\n", ((text + i)->adress));
            }
        }
    printf("\n");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    }


void File_input(FILE* file, Text* data)
    {
    data->BufSize = GetFileSize(file);
    data->Buf = (char*) calloc(data->BufSize + 1, sizeof(char));

    fread(data->Buf, sizeof(char), data->BufSize, file);

    fclose(file);

    data->count_n = Number_lines(data->Buf, data->BufSize);
    data->str = (String*) calloc(data->count_n, sizeof(String));

    replace_slash_n(data->Buf, data->BufSize);

    Parsing_pointers(data->Buf, data->BufSize, data->str);
    }


void Free(Text* data)
    {
    free(data->Buf);
    free(data->str);
    }
