#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED



#endif // INPUT_H_INCLUDED




#include "Text.h"

/** \brief Asks the user to input a character
 *
 * \param c char* Output variable. Stores the character inputed by the user
 * \param inputMsg[] char Input message
 * \param ... value to supply a format mask passed at inputMsg
 * \return int [-1] if either pointers are NULL
                [0] if ok
 *
 */
int Input_GetChar(char* c, char inputMsg[], ...);

/** \brief Asks the user to input a character. Usage of variable arguments passed is handled by another function that
            calls this one
 *
 * \param c char* Output variable. Stores the character inputed by the user
 * \param inputMsg[] char Input message
 * \param arguments va_list variable arguments list to supply a format mask passed at inputMsg
 * \return int [-1] if either pointers are NULL
                [0] if ok
 *
 */
int Input_GetChar_WithArguments(char* c, char inputMsg[], va_list arguments);

/** \brief Asks the user to input an integer number
 *
 * \param number int* Output variable. Stores the value inputed by the user
 * \param inputMsg char* Input message
 * \param ... value to supply a format mask passed at inputMsg
 * \return int [-1] if either pointers are NULL
                [0] if ok
 *
 */
int Input_Int(int* number, char* inputMsg, ...);

/** \brief Asks the user to input an integer number and validates that said value is over a min value
 *
 * \param number int* Output variable. Stores the value inputed by the user
 * \param inputMsg char* Input message
 * \param minValue int min value that the input should have. Any value lower results in an error
 * \param invalidInput[] char Error message printed when the user inputs a number lower than the minimum value
 * \param ... value to supply a format mask passed at inputMsg
 * \return int [-1] if either pointers are NULL
                [0] if ok
 *
 */
int Input_IntOverValue(int* number, char inputMsg[], int minValue, char invalidInput[],...);

/** \brief Asks the user to input an integer number and validates that said value is outside a given range
 *
 * \param number int* Output variable. Stores the value inputed by the user
 * \param inputMsg char* Input message
 * \param minValue int Min value of the range of invalid options
 * \param max int Max value of the range of invalid options
 * \param invalidInput[] char Error message printed when the user inputs a value inside the specified range
 * \param ... values to supply the format masks passed with messages
 * \return int [-2] if pointers are NULL or if min is bigger or equal to max
                [-1] if couldn't succesfully get an input from the user
                [0] if ok;
 *
 */
int Input_IntExcludingRange(int* number, char inputMsg[], int min, int max, char invalidInput[],...);

/** \brief Asks the user to input an integer number and validates that said value is inside a given range
 *
 * \param number int* Output variable. Stores the value inputed by the user
 * \param inputMsg char* Input message
 * \param minValue int Min value of the range of valid options
 * \param max int Max value of the range of valid options
 * \param invalidInput[] char Error message printed when the user inputs a value outside the specified range
 * \param ... values to supply the format masks passed with messages
 * \return int
 *
 */
int Input_IntInRange(int* number, char inputMsg[], int min, int max, char invalidInput[],...);

/** \brief Asks the user to input a float number
 *
 * \param number float* Output variable. Stores the value inserted by tyhe user
 * \param inputMsg[] char Input message
 * \param ... Variable arguments to supply the values for any format masks passed at inputMsg
 * \return int [-1] if either pointers are NULL
                [0] if ok
 *
 */
int Input_Float(float* number, char inputMsg[], ...);

/** \brief Asks the user to input a float number
 *
 * \param number float* Output variable. Stores the value inserted by tyhe user
 * \param inputMsg[] char Input message
 * \param minValue int min value accepted as input
 * \param ... Variable arguments to supply the values for any format masks passed at inputMsg
 * \return int [-1] if either pointers are NULL
                [0] if ok
 *
 *
 */
int Input_FloatOverValue(float* number, char inputMsg[], int minValue, ...);
/** \brief Asks the user to input an float number and validates that said value is outside a given range
 *
 * \param number float* Output variable. Stores the value inputed by the user
 * \param inputMsg char* Input message
 * \param minValue int Min value of the range of invalid options
 * \param max int Max value of the range of invalid options
 * \param invalidInput[] char Error message printed when the user inputs a value inside the specified range
 * \param ... values to supply the format masks passed with messages
 * \return int [-2] if pointers are NULL or if min is bigger or equal to max
                [-1] if couldn't succesfully get an input from the user
                [0] if ok;
 *
 */
int Input_FloatExcludingRange(float* number, char inputMsg[], int min, int max, ...);
/** \brief Asks the user to input an float number and validates that said value is inside a given range
 *
 * \param number float* Output variable. Stores the value inputed by the user
 * \param inputMsg char* Input message
 * \param minValue int Min value of the range of valid options
 * \param max int Max value of the range of valid options
 * \param invalidInput[] char Error message printed when the user inputs a value outside the specified range
 * \param ... values to supply the format masks passed with messages
 * \return int
 *
 */
int Input_FloatInRange(float* number, char inputMsg[], int min, int max, ...);

/** \brief Asks for the user confirmation
 *
 * \param inputMsg[] char Asks the user whether he is sure or not about doing an action
 * \param invalidInput[] char Error message in case no valid options are answered
 * \param confirmChar char Confirmation character
 * \param cancelChar char Cancel character
 * \param ... values to supply the format masks passed with messages
 * \return int [0]if the user cancels the operation
                [1] if the users confirms
 *
 */
int Input_Confirmation(char inputMsg[], char invalidInput[], char confirmChar, char cancelChar, ...);

/** \brief Asks the user to input a string of text
 *
 * \param myString[] char Output variable. Stores the string inserted by the user
 * \param sizeOfString int amount of characters the string has as maximum
 * \param inputMsg[] char Input message
 * \return int [-1] if either pointers are NULL
                [0] if ok
 *
 */
int Input_String(char myString[],int sizeOfString, char inputMsg[]);

/** \brief Asks the  user to input a string. Validates the absence of numbers and formats the string to add upper cases
 *
 * \param name[] char Variable that stores the name
 * \param sizeOfString int max length of the string
 * \param inputMsg[] char Input message
 * \param numberFound[] char Error message in case numbers are found
 * \return int [-1] if any pointers are NULL
                [0] if ok
 *
 */
int Input_String_Name(char name[],int sizeOfString, char inputMsg[], char numberFound[]);
