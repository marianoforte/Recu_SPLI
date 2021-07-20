#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED



#endif // TEXT_H_INCLUDED

#include "Comparison.h"


/** \brief Formats the given string as a name (first letter in any word in upper case)
 *
 * \param name[] char String to format
 * \return int [-1] if pointer is NULL
                [0] if ok
 *
 */
int Text_NormalizeName(char name[]);

/** \brief Initializes the given string
 *
 * \param myString[] char string to initialize
 * \return int [-1] if string is NULL
                [0] if ok
 *
 */
int Text_Initialize(char myString[]);

/** \brief Checks if a given string contains numbers
 *
 * \param myString[] char String to analyze
 * \return int [0] if doesn't contain numbers
                [1] if it does
 *
 */
int Text_ContainsNumbers(char myString[]);

/** \brief Prints a passed string. Can read format masks and replace them with values passed as variable arguments
 *
 * \param myString[] char String to prind
 * \param ... Values to supply any format masks passed along the string
 * \return int
 *
 */
int Text_PrintString(char myString[], ...);

/** \brief Prints a passed string. Receives a list of variable arguments processed by another function, making this an
            internal function
 *
 * \param myString[] char String to print
 * \param arguments va_list List of variable arguments
 * \return int [-1] if string is NULL
                [0] if ok
 *
 */
int Text_PrintString_Internal(char myString[], va_list arguments);


/** \brief Reads a format mask and returns a vaule based on the type of mask (Work in Progress)
 *
 * \param myString char* Pointer to char to analyze
 * \return int  [0] if no format mask was detected
                [1] if detected a char format mask. Expects an int representing the ASCII value of said char
                [2] if detected an int format mask;
                [3] if detected a float format mask;
 *
 */
int Text_ReadFormatMask(char* myChar);
