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

    FILE* file1 = fopen("output.txt", "w");

    FILE* file = fopen("test.txt", "rb");



    const long BufSize = GetFileSize(file);
    char* Buf = (char*) calloc(BufSize + 1, sizeof(char));

    fread(Buf, sizeof(char), BufSize, file);

    fclose(file);

    int count_n = Number_lines(Buf, BufSize);
    String* text = (String*) calloc(count_n, sizeof(String));

    replace_slash_n(Buf, BufSize);

    Parsing_pointers(Buf, BufSize, text);

    Sort(text, count_n, Strcmp);

    Output(file1, text, count_n);

    Sort(text, count_n, Strcmp_Reverse);

    Output(file1, text, count_n);

    Output1(file1, Buf, BufSize);

    fclose(file1);

    free(Buf);
    free(text);

    return 0;
    }



long GetFileSize(FILE* file)
    {
    assert(file);
    //ftell
    fseek(file, 0, SEEK_END);
    long bufsize = ftell(file);
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
            fprintf(file1, "%s\n", *((text + i)->adress));
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
            printf("%s\n", *((text + i)->adress));
            }
        }
    printf("\n");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("\n");
    printf("\n");
    }
//void File_input(FILE* file,
