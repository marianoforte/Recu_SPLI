#include "Controller.h"

#define HEADER_CLIENTS "id,id_car,first_name,last_name,email,phone"
#define HEADER_CARS "id,maker,model,year"

int forte_controller_loadFromText(char* path , LinkedList* myList, int option){
    int gotData = ll_isEmpty(myList);
    FILE* pFile;

    if(gotData != -1 && path != NULL){
        if(!gotData){
            puts("\nYa existen elementos cargados en la lista. Si continua, se perderan los datos no guardados");
            if(Input_Confirmation("\nDesea continuar? s/n: ", "Esta opcion no es valida", 's', 'n')){
                ll_clear(myList);
                gotData = 1;
            }
        }
        if(gotData == 1){
            pFile = fopen(path,"r");
            if(pFile != NULL){
                if(option == 0){
                    gotData = parser_ClientsFromText(pFile, myList);
                    printf("\nSe han cargado %d clientes\n", gotData);

                }
                else{
                    gotData = parser_CarsFromText(pFile, myList);
                    printf("\nSe han cargado %d autos\n", gotData);
                }
                fclose(pFile);
            }
        }

    }
    return gotData;
}

int forte_controller_ListClientsWithCars(LinkedList* myClients, LinkedList* myCars){
    eCliente* actual;
    eAuto* auxAuto;
    int indiceAuto;
    int idAuto;
    char nombre[51];
    char apellido[51];
    char email[51];
	char telefono[51];
	char fabricante[51];
	char modelo[51];
	int anio;
	int rtn = -1;
	int listStateClients;
	int listStateCars;
	listStateClients = ll_isEmpty(myClients);
	listStateCars = ll_isEmpty(myCars);
    if(listStateClients != -1 && listStateCars != -1){
    	if(listStateClients == 0 && listStateCars == 0){
    		printf("\n------------------------------------------------------------------------------------------------------\n");
    		printf("\n%-15s | %-15s | %-35s | %-15s | %-15s | %-20s | %-10s\n\n", "Nombre", "Apellido", "Email", "Telefono", "Marca", "Modelo", "Anio");
			for(int i=0;i<ll_len(myClients);i++){
				actual = ll_get(myClients, i);
				cliente_getIdAuto(actual, &idAuto);
				cliente_getNombre(actual, nombre);
				cliente_getApellido(actual, apellido);
				cliente_getEmail(actual, email);
				cliente_getTelefono(actual, telefono);
				indiceAuto = forte_controller_searchCarById(myCars, idAuto);
				auxAuto = (eAuto*) ll_get(myCars, indiceAuto);
				auto_getFabricante(auxAuto, fabricante);
				auto_getModelo(auxAuto, modelo);
				auto_getAnio(auxAuto, &anio);
				printf("%-15s | %-15s | %-35s | %-15s | %-15s | %-20s | %-10d\n", nombre, apellido, email, telefono, fabricante, modelo, anio);
			}
			printf("\n");
			rtn = 1;
    	}
    	else{
			puts("\nError: El listado esta vacio.");
			rtn = 0;
		}
	}
    else{
		puts("\nError: El listado no existe.");
	}
    return rtn;
}

int forte_controller_ListClientsWithIDs(LinkedList* myClients, LinkedList* myCars){
    eCliente* actual;
    eAuto* auxAuto;
    int indiceAuto;
    int idCliente;
    int idAuto;
    char nombre[51];
    char apellido[51];
    char email[51];
	char telefono[51];
	char fabricante[51];
	char modelo[51];
	int anio;
	int i = -1;
    if(!ll_isEmpty(myClients)){
    	printf("\n%-6s | %-6s | %-15s | %-15s | %-35s | %-15s | %-15s | %-20s | %-10s\n\n", "ID", "ID Auto", "Nombre", "Apellido", "Email", "Telefono", "Marca", "Modelo", "Anio");
        for(i=0;i<ll_len(myClients);i++){
            actual = ll_get(myClients, i);
            cliente_getIdCliente(actual, &idCliente);
            cliente_getIdAuto(actual, &idAuto);
            cliente_getNombre(actual, nombre);
			cliente_getApellido(actual, apellido);
			cliente_getEmail(actual, email);
			cliente_getTelefono(actual, telefono);
			indiceAuto = forte_controller_searchCarById(myCars, idAuto);
			auxAuto = (eAuto*) ll_get(myCars, indiceAuto);
			auto_getFabricante(auxAuto, fabricante);
			auto_getModelo(auxAuto, modelo);
			auto_getAnio(auxAuto, &anio);
			printf("%-6d | %-6d | %-15s | %-15s | %-35s | %-15s | %-15s | %-20s | %-10d\n", idCliente, idAuto, nombre, apellido, email, telefono, fabricante, modelo, anio);
        }
    }
    else{
        printf("\nError: El listado esta vacio o no existe.");
    }
    return i;
}

int forte_controller_ListClientsWithSpecificCar(LinkedList* myClients, LinkedList* myCars, char* criteria){
    eCliente* actual;
    eAuto* auxAuto;
    int indiceAuto;
    int idAuto;
    char nombre[51];
    char apellido[51];
    char email[51];
	char telefono[51];
	char fabricante[51];
	char modelo[51];
	int anio;
	int rtn = -1;
	int listStateClients;
	int listStateCars;
	listStateClients = ll_isEmpty(myClients);
	listStateCars = ll_isEmpty(myCars);
    if(listStateClients != -1 && listStateCars != -1){
    	if(listStateClients == 0 && listStateCars == 0){
    		printf("\n------------------------------------------------------------------------------------------------------\n");
    		printf("\n%-15s | %-15s | %-35s | %-15s | %-15s | %-20s | %-10s\n\n", "Nombre", "Apellido", "Email", "Telefono", "Marca", "Modelo", "Anio");
			for(int i=0;i<ll_len(myClients);i++){
				actual = ll_get(myClients, i);
				cliente_getIdAuto(actual, &idAuto);
				cliente_getNombre(actual, nombre);
				cliente_getApellido(actual, apellido);
				cliente_getEmail(actual, email);
				cliente_getTelefono(actual, telefono);
				indiceAuto = forte_controller_searchCarById(myCars, idAuto);
				auxAuto = (eAuto*) ll_get(myCars, indiceAuto);
				auto_getFabricante(auxAuto, fabricante);
				auto_getModelo(auxAuto, modelo);
				auto_getAnio(auxAuto, &anio);
				if(!strcmp(modelo, criteria)){
					printf("%-15s | %-15s | %-35s | %-15s | %-15s | %-20s | %-10d\n", nombre, apellido, email, telefono, fabricante, modelo, anio);
				}
			}
			printf("\n");
			rtn = 1;
    	}
    	else{
			puts("\nError: El listado esta vacio.");
			rtn = 0;
		}
	}
    else{
		puts("\nError: El listado no existe.");
	}
    return rtn;
}

void forte_controller_printOne(eCliente* this, eAuto* car){
	int idCliente;
	char nombre[51];
	char apellido[51];
	char email[51];
	char telefono[51];
	char fabricante[51];
	char modelo[51];
	int anio;
	if(this != NULL){
		cliente_getIdCliente(this, &idCliente);
		cliente_getNombre(this, nombre);
		cliente_getApellido(this, apellido);
		cliente_getEmail(this, email);
		cliente_getTelefono(this, telefono);
		auto_getFabricante(car, fabricante);
		auto_getModelo(car, modelo);
		auto_getAnio(car, &anio);
		printf("%-15s | %-15s | %-35s | %-15s | %-15s | %-20s | %-10d\n", nombre, apellido, email, telefono, fabricante, modelo, anio);
	}
}

int forte_controller_ListClientsOnly(LinkedList* myList){
	eCliente* auxEmployee;
	int listState;
	int rtn = -1;
	listState = ll_isEmpty(myList);
	if(listState != -1){
		int listLength = ll_len(myList);
		if(listState == 0){
			puts("\n-------------------------------------------------------------------------------");
			puts("\nListado de Clientes:");
			printf("\n%-15s | %-15s | %-35s | %-15s\n\n", "Nombre", "Apellido", "Email", "Telefono");
			for(int i=0; i<listLength; i++){
					auxEmployee = (eCliente*)ll_get(myList, i);
					cliente_printOne(auxEmployee);
			}
			printf("\n");
			rtn = 1;
		}
		else{
			puts("\nNo hay empleados para mostrar\n");
			rtn = 0;
		}
	}
    return rtn;
}

int forte_controller_ListCarsOnly(LinkedList* myList){
	eAuto* auxAuto;
	int listState;
	int rtn = -1;
	listState = ll_isEmpty(myList);
	if(listState != -1){
		int listLength = ll_len(myList);
		if(listState == 0){
			puts("\n-------------------------------------------------------------------------------");
			puts("\nListado de Autos:");
			printf("\n%-3s | %-15s | %-20s | %-15s\n\n", "ID", "Fabricante", "Modelo", "Anio");
			for(int i=0; i<listLength; i++){
				auxAuto = (eAuto*)ll_get(myList, i);
				auto_printOne(auxAuto);
			}
			printf("\n");
			rtn = 1;
		}
		else{
			puts("\nNo hay autos para mostrar\n");
			rtn = 0;
		}
	}
    return rtn;
}

int forte_controller_saveClientsAsText(char* path , LinkedList* myList){
    int savedData = ll_isEmpty(myList);
    FILE* pFile;
    eCliente* actual;
    int idCliente;
    int idAuto;
    char nombre[51];
    char apellido[51];
    char email[51];
    char telefono[51];

    if(path != NULL && savedData != -1){
        savedData = 0;
        pFile = fopen(path, "w");
        if(pFile != NULL){
            fprintf(pFile, "%s\n", HEADER_CLIENTS);
            for(int i=0;i<ll_len(myList);i++){
                actual = ll_get(myList, i);
                cliente_getIdCliente(actual, &idCliente);
                cliente_getIdAuto(actual, &idAuto);
                cliente_getNombre(actual, nombre);
                cliente_getApellido(actual, apellido);
				cliente_getEmail(actual, email);
				cliente_getTelefono(actual, telefono);
				fprintf(pFile, "%d,%d,%s,%s,%s,%s\n", idCliente, idAuto, nombre, apellido, email, telefono);
				savedData++;
            }
            fclose(pFile);
            printf("\nListado guardado exitosamente. %d elementos registrados\n\n", savedData);
        }
    }
    return savedData;
}

int forte_controller_saveCarsAsText(char* path , LinkedList* myList){
    int savedData = ll_isEmpty(myList);
    FILE* pFile;
    eAuto* actual;
    int idAuto;
    char fabricante[51];
    char modelo[51];
    int anio;

    if(path != NULL && savedData != -1){
        savedData = 0;
        pFile = fopen(path, "w");
        if(pFile != NULL){
            fprintf(pFile, "%s\n", HEADER_CARS);
            for(int i=0;i<ll_len(myList);i++){
                actual = ll_get(myList, i);
                auto_getId(actual, &idAuto);
                auto_getFabricante(actual, fabricante);
                auto_getModelo(actual, modelo);
                auto_getAnio(actual, &anio);
				fprintf(pFile, "%d,%s,%s,%d\n", idAuto, fabricante, modelo, anio);
				savedData++;
            }
            fclose(pFile);
            printf("\nListado guardado exitosamente. %d elementos registrados\n\n", savedData);
        }
    }
    return savedData;
}

int forte_controller_searchClientById(LinkedList* myList, int targetId){
    int index = -2;
    int actualId;
    eCliente* target;
    if(!ll_isEmpty(myList)){
        for(index=0;index<ll_len(myList);index++){
            target = ll_get(myList, index);
            if(!cliente_getIdCliente(target, &actualId)){
                if(actualId == targetId){
                    break;
                }
            }
        }
        if(index == ll_len(myList)){
            index = -1;
        }
    }
    return index;
}

int forte_controller_searchCarById(LinkedList* myList, int targetId){
    int index = -2;
    int actualId;
    eAuto* target;
    if(!ll_isEmpty(myList)){
        for(index=0;index<ll_len(myList);index++){
            target = ll_get(myList, index);
            if(!auto_getId(target, &actualId)){
                if(actualId == targetId){
                    break;
                }
            }
        }
        if(index == ll_len(myList)){
            index = -1;
        }
    }
    return index;
}

int forte_controller_FilterClientsByCar(LinkedList* clients, LinkedList* cars, int criterio){
    LinkedList* tempList;
    int rtn = -1;

    if(clients != NULL && cars != NULL){
        tempList = ll_filter(clients, cliente_filterByCarId, &criterio);
        if(tempList != NULL){
        	forte_controller_ListClientsWithCars(tempList, cars);
        	rtn = 0;
        }
        ll_deleteLinkedList(tempList);
    }
    return rtn;
}

int forte_controller_FilterCarsByYear(LinkedList* cars, int criterio){
    LinkedList* tempList;
    int rtn = -1;

    if(cars != NULL){
        tempList = ll_filter(cars, auto_filterByYear, &criterio);
        if(tempList != NULL){
        	forte_controller_ListCarsOnly(tempList);
        	forte_controller_saveCarsAsText("Autos2012.csv", tempList);
        	rtn = 0;
        }
        ll_deleteLinkedList(tempList);
    }
    return rtn;
}

int forte_controller_CountClientsByLastName(LinkedList* this, char* criteria)
{
    int totalCars = -1;


    if(this != NULL )
    {
    	totalCars = 0;
		totalCars = ll_count(this, cliente_countClientsByLastName);
		printf("\nHay un total de %d clientes con el apellido %s\n\n", totalCars, criteria);

    }
    return totalCars;
}

int forte_controller_CountCarsByBrand(LinkedList* this, LinkedList* cars, char* criteria)
{
    int totalCars = -1;


    if(this != NULL )
    {
    	totalCars = 0;
		totalCars = ll_count(cars, auto_countCarsByBrand);
		printf("\nHay un total de %d auto(s) %s\n\n", totalCars, criteria);

    }
    return totalCars;
}

int forte_controller_saveLastId(char* path){
    int id = -1;
    FILE* pFile;

    if(path != NULL){
        pFile = fopen(path, "wb");
        if(pFile != NULL){
            id = cliente_getLastId();
            fwrite(&id, sizeof(int), 1, pFile);
            fclose(pFile);
        }
    }
    return id;
}

int forte_controller_loadLastId(char* path){
    int id = -1;
    FILE* pFile;

    if(path != NULL){
        pFile = fopen(path, "rb");
        if(pFile != NULL){
            fread(&id, sizeof(int), 1, pFile);
            cliente_setLastId(id);
            fclose(pFile);
        }
    }
    return id;
}
