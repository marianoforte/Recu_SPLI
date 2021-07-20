
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "clientes.h"
#include "autos.h"

/** \brief Parses the data stored in a text file and loads it into the employee list.
 *
 * \param pFile FILE* Pointer to file where the data is stored
 * \param pArrayList LinkedList* Pointer to employee list
 * \return int [-1] if either pointers is NULL
                amount of elements parsed otherwise
 *
 */
int parser_ClientsFromText(FILE* pFile , LinkedList* pArrayList);

/** \brief Parses the data stored in a text file and loads it into the employee list.
 *
 * \param pFile FILE* Pointer to file where the data is stored
 * \param pArrayList LinkedList* Pointer to employee list
 * \return int [-1] if either pointers is NULL
                amount of elements parsed otherwise
 *
 */
int parser_CarsFromText(FILE* pFile, LinkedList* pArrayList);
