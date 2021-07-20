#include <stdio.h>
#include <stdlib.h>
#include "autos.h"
#include "Input.h"
#include "LinkedList.h"
#include "parser.h"
#include "clientes.h"



/** \brief Loads data from a text file
 *
 * \param path char* Path where to find the file
 * \param myList LinkedList* Pointer to the linkedlist
 * \param option int The option of which list to load
 * \return int  [-1] if path or pointer to list are NULL
                [0] if elements already exists in the list and the users cancel the load
                 OR amount of elements successfully loaded
 *
 */
int forte_controller_loadFromText(char* path , LinkedList* myList, int option);

/** \brief Shows all clients with their cars, no IDs
 *
 * \param myClients LinkedList* pointer to client's list
 * \param myCars LinkedList* pointer to car's list
 * \return int [-1] if pointer to list is NULL
               [0] if the list is empty
               [1] if the print was successfull
 *
 */
int forte_controller_ListClientsWithCars(LinkedList* myClients, LinkedList* myCars);

/** \brief Shows all clients with their cars and IDs
 *
 * \param myClients LinkedList* pointer to client's list
 * \param myCars LinkedList* pointer to car's list
 * \return int [-1] if pointer to list is NULL
               [0] if the list is empty
               [1] if the print was successfull
 *
 */
int forte_controller_ListClientsWithIDs(LinkedList* myClients, LinkedList* myCars);

/** \brief Shows clients with an specific car
 *
 * \param myClients LinkedList* pointer to client's list
 * \param myCars LinkedList* pointer to car's list
 * \param criteria char* The criteria to filter the list
 * \return int [-1] if pointer to list is NULL
               [0] if the list is empty
               [1] if the print was successfull
 *
 */
int forte_controller_ListClientsWithSpecificCar(LinkedList* myClients, LinkedList* myCars, char* criteria);

/** \brief Shows one clients
 *
 * \param this LinkedList* pointer to client's list
 * \param car LinkedList* pointer to car's list
 * \return void
 *
 */
void forte_controller_printOne(eCliente* this, eAuto* car);

/** \brief Shows only clients
 *
 * \param myList LinkedList* pointer to client's list
 * \return int [-1] if pointer to list is NULL
               [0] if the list is empty
               [1] if the print was successfull
 *
 */
int forte_controller_ListClientsOnly(LinkedList* myList);

/** \brief Shows only cars
 *
 * \param myList LinkedList* pointer to car's list
 * \return int [-1] if pointer to list is NULL
               [0] if the list is empty
               [1] if the print was successfull
 *
 */
int forte_controller_ListCarsOnly(LinkedList* myList);

/** \brief Saves all the client's data in a text file
 *
 * \param path char* Path to file
 * \param myList LinkedList* Pointer to client's list
 * \return int [-1] if pointer to list is NULL
               [ 0] if the list is empty
               The amount of successfully saved elements
 *
 */
int forte_controller_saveClientsAsText(char* path , LinkedList* myList);

/** \brief Saves all the cars's data in a text file
 *
 * \param path char* Path to file
 * \param myList LinkedList* Pointer to car's list
 * \return int [-1] if pointer to list is NULL
               [ 0] if the list is empty
               The amount of successfully saved elements
 *
 */
int forte_controller_saveCarsAsText(char* path , LinkedList* myList);

/** \brief Searchs the clients list for the client that matches the passed id
 *
 * \param myList LinkedList* pointer to client list
 * \param targetId int searched ID
 * \return int  [-2] if pointer to employee list is NULL or the list is empty
                [-1] if passed id is not found
                Index of employee if ok
 *
 */
int forte_controller_searchClientById(LinkedList* myList, int targetId);

/** \brief Searchs the cars list for the car that matches the passed id
 *
 * \param myList LinkedList* pointer to car list
 * \param targetId int searched ID
 * \return int  [-2] if pointer to employee list is NULL or the list is empty
                [-1] if passed id is not found
                Index of employee if ok
 *
 */
int forte_controller_searchCarById(LinkedList* myList, int targetId);

/** \brief Filters a list by a criteria
 *
 * \param clients LinkedList* The list to filter
 * \param cars LinkedList* The list to filter
 * \param criterio void* The criteria to filter
 * \return int [-1] if the list is NULL
               [0] if the filtering was successfull
 *
 */
int forte_controller_FilterClientsByCar(LinkedList* clients, LinkedList* cars, int criterio);

/** \brief Filters a list by a criteria
 *
 * \param cars LinkedList* The list to filter
 * \param criterio void* The criteria to filter
 * \return int [-1] if the list is NULL
               [0] if the filtering was successfull
 *
 */
int forte_controller_FilterCarsByYear(LinkedList* cars, int criterio);

/** \brief Counts the number of appearences of a single element on the listing
 *
 * \param this LinkedList* The list where to count
 * \param criteria char* The criteria to filter
 * \return int [-1] if the list is NULL
               [0] If none element was found
               The amount of elements if the count was successfull
 *
 */
int forte_controller_CountClientsByLastName(LinkedList* this, char* criteria);

/** \brief Counts the number of appearences of a single element on the listing
 *
 * \param this LinkedList* The list where to count
 * \param cars LinkedList* The list where to count
 * \param criteria char* The criteria to filter
 * \return int [-1] if the list is NULL
               [0] If none element was found
               The amount of elements if the count was successfull
 *
 */
int forte_controller_CountCarsByBrand(LinkedList* this, LinkedList* cars, char* destination);

/** \brief Saves the last id generated by the user
 *
 * \param path char* path to last id file
 * \return int [-1] if path is NULL
                saved value otherwise
 *
 */
int forte_controller_saveLastId(char* path);

/** \brief Loads the last id generated by the user
 *
 * \param path char* path to last id file
 * \return int [-1] if path is NULL
                loaded value otherwise
 *
 */
int forte_controller_loadLastId(char* path);
