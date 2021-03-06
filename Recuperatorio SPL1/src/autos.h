#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


#ifndef AUTOS_H_INCLUDED
#define AUTOS_H_INCLUDED

typedef struct{
    int id;
    char fabricante[51];
    char modelo[51];
    int anio;
}eAuto;


/////////////// ID ///////////////


/** \brief Sets the last ID generated by the user
 *
 * \param newId int The ID to set
 * \return int [-1] if ID is lower or equals than zero
               [0] if the ID was setted correctly
 *
 */
int auto_setLastId(int newId);

/** \brief Gets the last ID registered on the system
 *
 * \param void
 * \return the last ID
 *
 */
int auto_getLastId(void);

/** \brief Increases the last ID registered on the system
 *
 * \param void
 * \return the increased ID by one
 *
 */
int auto_increaseLastId(void);

/** \brief Increases the last ID registered on the system
 *
 * \param void
 * \return the decreased ID by one
 *
 */
int auto_decreaseLastId(void);


/////////////// CONSTRUCTOR ///////////////


/** \brief Creates dynamic space on memmory for a list
 *
 * \param void
 * \return the memmory allocation for the specific list
 *
 */
eAuto* auto_new();

/** \brief Constructs an input of a new parameter for the listing
 *
 * \param id char* The ID to receive
 * \param fabricante char* The maker to input
 * \param modelo char* The model to input
 * \param anio char* The year to input
 * \return The new parameter to set on the list
 *
 */
eAuto* auto_newParametros(char* id, char* fabricante, char* modelo, char* anio);


/////////////// GETTERS ///////////////


/** \brief Gets the car's ID
 *
 * \param this eAuto* The pointer to the list
 * \param id int* The pointer to the variable where to store the Id after being getted
 * \return int [-1] if the list or the id pointer is NULL
               [0] if the ID was getted correctly
 *
 */
int auto_getId(eAuto* this, int* id);

/** \brief Gets the car's maker
 *
 * \param this eAuto* The pointer to the list
 * \param fabricante char* The pointer to the variable where to store the maker after being getted
 * \return int [-1] if the list or the maker pointer is NULL
               [0] if the ID was getted correctly
 *
 */
int auto_getFabricante(eAuto* this, char* fabricante);

/** \brief Gets the car's model
 *
 * \param this eAuto* The pointer to the list
 * \param modelo char* The pointer to the variable where to store the model after being getted
 * \return int [-1] if the list or the model pointer is NULL
               [0] if the name was getted correctly
 *
 */
int auto_getModelo(eAuto* this, char* modelo);

/** \brief Gets the car's year
 *
 * \param this eCliente* The pointer to the list
 * \param anio int* The pointer to the variable where to store the year after being getted
 * \return int [-1] if the list or the year pointer is NULL
               [0] if the year was getted correctly
 *
 */
int auto_getAnio(eAuto* this, int* anio);


/////////////// SETTERS ///////////////


/** \brief Sets the car's ID
 *
 * \param this eAuto* The pointer to the list
 * \param id int The ID to set
 * \return int [-1] if the list or the id pointer is NULL
               [0] if the ID was getted correctly
 *
 */
int auto_setId(eAuto* this, int id);

/** \brief Sets the car's maker
 *
 * \param this eCliente* The pointer to the list
 * \param fabricante int The maker to set
 * \return int [-1] if the list or the maker pointer is NULL
               [0] if the maker was setted correctly
 *
 */
int auto_setFabricante(eAuto* this, char* fabricante);

/** \brief Sets the car's model
 *
 * \param this eCliente* The pointer to the list
 * \param modelo int The model to set
 * \return int [-1] if the list or the model pointer is NULL
               [0] if the model was setted correctly
 *
 */
int auto_setModelo(eAuto* this, char* modelo);

/** \brief Sets the car's year
 *
 * \param this eCliente* The pointer to the list
 * \param anio int The year to set
 * \return int [-1] if the list or the year pointer is NULL
               [0] if the year was getted correctly
 *
 */
int auto_setAnio(eAuto* this, int anio);


/////////////// ABM ///////////////


/** \brief Deletes the car's list
 *
 * \param this eAuto* The pointer to the list
 * \return void
 *
 */
int auto_delete(eAuto* this);

/** \brief Print's one element of the listing
 *
 * \param this eAuto* The pointer to the list
 * \return void
 *
 */
int auto_printOne(eAuto* this);


///////////////COMPARISONS ///////////////


/** \brief Compares two elements by their ID
 *
 * \param firstCar void* The first element to compare
 * \param secondCar void* The second element to compare
 * \return int [-2] if the elements are NULL
               [-1] if the first element is smaller than the second
               [0] if both elements are equal
               [1] if the first element is bigger than the second
 *
 */
int auto_compareById(void* firstCar, void* secondCar);

/** \brief Compares two elements by their brand
 *
 * \param firstCar void* The first element to compare
 * \param secondCar void* The second element to compare
 * \return int [-2] if the elements are NULL
               [-1] if the first element is smaller than the second
               [0] if both elements are equal
               [1] if the first element is bigger than the second
 *
 */
int auto_compareByBrand(void* firstCar, void* secondCar);

/** \brief Compares two elements by their model
 *
 * \param firstCar void* The first element to compare
 * \param secondCar void* The second element to compare
 * \return int [-2] if the elements are NULL
               [-1] if the first element is smaller than the second
               [0] if both elements are equal
               [1] if the first element is bigger than the second
 *
 */
int auto_compareByModel(void* firstCar, void* secondCar);

/** \brief Compares two elements by their year
 *
 * \param firstCar void* The first element to compare
 * \param secondCar void* The second element to compare
 * \return int [-2] if the elements are NULL
               [-1] if the first element is smaller than the second
               [0] if both elements are equal
               [1] if the first element is bigger than the second
 *
 */
int auto_compareByYear(void* firstCar, void* secondCar);


/////////////// FILTERS ///////////////


/** \brief Filters a list by a criteria
 *
 * \param this void* The list to filter
 * \param criteria void* The criteria to filter
 * \return int [-1] if the list or criteria are NULL
               [0] if the filtering was successfull
 *
 */
int auto_filterByBrand(void* this, void* criteria);

/** \brief Filters a list by a criteria
 *
 * \param this void* The list to filter
 * \param criteria void* The criteria to filter
 * \return int [-1] if the list or criteria are NULL
               [0] if the filtering was successfull
 *
 */
int auto_filterByModel(void* this, void* criteria);

/** \brief Filters a list by a criteria
 *
 * \param this void* The list to filter
 * \param criteria void* The criteria to filter
 * \return int [-1] if the list or criteria are NULL
               [0] if the filtering was successfull
 *
 */
int auto_filterByYear(void* this, void* criteria);

/** \brief Counts the number of appearences of a single element on the listing
 *
 * \param pElement void* The element to count
 * \return int [-1] if the list or criteria are NULL
               [0] if the filtering was successfull
 *
 */
int auto_countCarsByBrand(void* pElement);

#endif /* AUTOS_H_ */
