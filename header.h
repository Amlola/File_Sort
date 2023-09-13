/*!
\file
\brief Program header file.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>




/*!
 * The function returns the size of the input file.
 */
long GetFileSize(FILE* file);


/*!
 * The function replaces the newline character with a null character.
 * \param[in] BufSize - size of buffer.
 */
void replace_slash_n(char* Buf, size_t BufSize);


/*!
 * Function fills an array of pointers.
 * \param[in] Number_lines - number of lines.
 */
void Parsing_pointers(char* Buf, int Number_lines, char** text);


/*!
 * Function returns number of rows.
 */
int Number_lines(char* Buf, size_t BufSize);


/*!
 * \brief Sorting strings.
 *
 * The function, depending on the passed CompFunc function, sorts the strings either from the beginning or from the end.
 * \param[in] text_len - number of lines.
 */
void qSort(void* text1, size_t left, size_t right, int (*CompFunc)(const void* s1, const void* s2));


/*!
 * \brief Comparing two strings.
 *
 * The function compares two strings character by character from the beginning.
 * Punctuation marks are not taken into account.
 * \param[in] s1, s2 - strings to compare.
 */
int Strcmp(const void* s1, const void* s2);


/*!
 * \brief Comparing two strings.
 *
 * The function compares two strings character by character from the end.
 * Punctuation marks are not taken into account.
 * \param[in] s1, s2 - strings to compare.
 */
int Strcmp_Reverse(const void* s1, const void* s2);


/*!
 * Function outputs sorted rows.
 * \param[in] count_n - number of lines in text.
 */
void Output(FILE* file1, char** text, int count_n);


/*!
 * Function outputs source text.
 * \param[in] BufSize - size of buffer.
 */
void Output1(FILE* file1, char* Buf, size_t BufSize);


void Swap(char** text, size_t i, size_t j);


void Sort(void* text1, size_t text_len, int (*CompFunc)(const void* s1, const void* s2));









