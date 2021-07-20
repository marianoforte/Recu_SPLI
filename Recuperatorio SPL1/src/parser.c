#include "parser.h"

int parser_ClientsFromText(FILE* pFile , LinkedList* pArrayList){
	int returnAux;
    int elementsAdded = -1;
    char idClienteParseado[11];
    char idAutoParseado[11];
    char nombreParseado[51];
    char apellidoParseado[51];
    char emailParseado[51];
    char telefonoParseado[51];
    eCliente* new;

    if(pFile != NULL && pArrayList != NULL){
        elementsAdded = 0;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idClienteParseado, idAutoParseado, nombreParseado, apellidoParseado, emailParseado, telefonoParseado);
        while(!feof(pFile)){
            returnAux = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idClienteParseado, idAutoParseado, nombreParseado, apellidoParseado, emailParseado, telefonoParseado);
            if(returnAux == 6){
                new = cliente_newParametros(idClienteParseado, idAutoParseado, nombreParseado, apellidoParseado, emailParseado, telefonoParseado);
                if(new != NULL && ll_contains(pArrayList, new) == 0){
                    ll_add(pArrayList, new);
                    elementsAdded++;
                }
            }
        }
    }
    return elementsAdded;
}

int parser_CarsFromText(FILE* pFile, LinkedList* pArrayList){
	int returnAux;
	int elementsAdded = -1;
    char idParseado[11];
    char fabricanteParseado[51];
    char modeloParseado[51];
    char anioParseado[11];
    eAuto* new;

    if(pFile != NULL && pArrayList != NULL){
        elementsAdded = 0;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idParseado, fabricanteParseado, modeloParseado, anioParseado);

        while(!feof(pFile)){
            returnAux = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idParseado, fabricanteParseado, modeloParseado, anioParseado);
            if(returnAux == 4){
                new = auto_newParametros(idParseado, fabricanteParseado, modeloParseado, anioParseado);
                if(new != NULL && ll_contains(pArrayList, new) == 0){
                    ll_add(pArrayList, new);
                    elementsAdded++;
                }
            }
        }
    }
    return elementsAdded;
}
