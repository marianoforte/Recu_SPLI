#ifndef COMPARISON_H_INCLUDED
#define COMPARISON_H_INCLUDED

typedef enum bool
{
    false,
    true,
}bool;

#endif // COMPARISON_H_INCLUDED

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/** \brief Compares the first "size" bytes from the two received memory addresses
 *
 * \param firstObject void* pointer to first variable
 * \param secondObject void* pointer to second variable
 * \param size size_t amount of bytes to compare
 * \return int  [-1] if the value of the bytes of firstObject is smaller than secondObject's
                 [0] if both are equal
                 [1] if the value of the bytes of firstObject is bigger than secondObject's
 *
 */
int Compare_Elements(void* firstObject, void* secondObject, size_t size);

/** \brief Swaps the first "size" bytes pointed to by firstObject and secondObject
 *
 * \param firstObject void* pointer to first variable
 * \param secondObject void* pointer to second variable
 * \param size size_t amount of bytes to swap
 * \return int -1 if either firstObject or secondObject are NULL
 *
 */
int Comparison_Swap(void* firstObject, void* secondObject, size_t size);

/** \brief Checks whether a given number is even or odd
 *
 * \param number int number to check
 * \return int 0 if is even
                1 if odd
 *
 */
int Comparison_CheckParityInt(int number);

/** \brief Checks if a given integer is a prime number
 *
 * \param number int number to check
 * \return int [0] if numbers is not prime
                [1] if number is prime
 *
 */
int Comparison_NumberIsPrime(int number);
