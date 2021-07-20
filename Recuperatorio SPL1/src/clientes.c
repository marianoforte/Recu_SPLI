#include "clientes.h"

static int lastClientId = 0;

int cliente_setLastId(int newId){
	int set = -1;
	if(lastClientId>0){
		lastClientId = newId;
		set = 0;
	}
	return set;
}

int cliente_getLastId(void){
	return lastClientId;
}

int cliente_increaseLastId(void){
	lastClientId++;
	return lastClientId;
}

int cliente_decreaseLastId(void){
	lastClientId--;
	return lastClientId;
}

eCliente* cliente_new(void){
    return (eCliente*)calloc(1, sizeof(eCliente));
}

eCliente* cliente_newParametros(char* idCliente, char* idAuto, char* nombre, char* apellido, char* email, char* telefono){
	eCliente* auxCliente;
	int idAux;
	int idAutoAux;
    int parametersFlag = 1;
    auxCliente = cliente_new();
	if(auxCliente != NULL){
		if(idCliente != NULL){
			idAux = atoi(idCliente);
			cliente_setIdCliente(auxCliente, idAux);
		}
		if(idAuto != NULL){
			idAutoAux = atoi(idAuto);
			cliente_setIdAuto(auxCliente, idAutoAux);
		}
		if(nombre != NULL){
			cliente_setNombre(auxCliente, nombre);
		}
		if(apellido != NULL){
			cliente_setApellido(auxCliente, apellido);
		}
		if(email != NULL){
			cliente_setEmail(auxCliente, email);
		}
		if(telefono != NULL){
			cliente_setTelefono(auxCliente, telefono);
		}
			parametersFlag = 0;
    }
	if(parametersFlag){
		cliente_delete(auxCliente);
	}
    return auxCliente;
}

int cliente_getIdCliente(eCliente* this,int* id){
    int rtn = -1;
    if(this!=NULL && id != NULL){
        *id = this->id;
        rtn = 0;
    }
    return rtn;
}

int cliente_setIdCliente(eCliente* this,int id){
	int rtn = -1;
    if(this!=NULL && id>0){
		this->id = id;
		rtn = 0;
    }
    return rtn;
}

int cliente_getIdAuto(eCliente* this,int* id){
	int rtn = -1;
    if(this!=NULL && id != NULL){
        *id = this->idAuto;
        rtn = 0;
    }
    return rtn;
}

int cliente_setIdAuto(eCliente* this,int id){
	int rtn = -1;
    if(this!=NULL && id>0){
		this->idAuto = id;
		rtn = 0;
    }
    return rtn;
}

int cliente_getNombre(eCliente* this,char* nombre){
	int rtn = -1;
    if(this!=NULL && nombre != NULL){
        strcpy(nombre, this->nombre); //
        rtn = 0;
    }
    return rtn;
}

int cliente_setNombre(eCliente* this,char* nombre){
	int rtn = -1;
    if(this!=NULL  && strlen(nombre) != 0){
        strcpy(this->nombre, nombre);
        rtn = 0;
    }
    return rtn;
}

int cliente_getApellido(eCliente* this,char* apellido){
	int rtn = -1;
    if(this!=NULL && apellido != NULL){
        strcpy(apellido, this->apellido); //
        rtn = 0;
    }
    return rtn;
}

int cliente_setApellido(eCliente* this,char* apellido){
	int rtn = -1;
    if(this!=NULL  && strlen(apellido) != 0){
        strcpy(this->apellido, apellido);
        rtn = 0;
    }
    return rtn;
}

int cliente_getEmail(eCliente* this,char* email){
	int rtn = -1;
    if(this!=NULL && email != NULL){
        strcpy(email, this->email); //
        rtn = 0;
    }
    return rtn;
}

int cliente_setEmail(eCliente* this,char* email){
	int rtn = -1;
    if(this!=NULL  && strlen(email) != 0){
        strcpy(this->email, email);
        rtn = 0;
    }
    return rtn;
}

int cliente_getTelefono(eCliente* this,char* telefono){
	int rtn = -1;
    if(this!=NULL && telefono != NULL){
        strcpy(telefono, this->telefono); //
        rtn = 0;
    }
    return rtn;
}

int cliente_setTelefono(eCliente* this,char* telefono){
	int rtn = -1;
    if(this!=NULL  && strlen(telefono) != 0){
        strcpy(this->telefono, telefono);
        rtn = 0;
    }
    return rtn;
}

void cliente_delete(eCliente* this){
    if(this!=NULL){
    	free(this);
    }
}

void cliente_printOne(eCliente* this){
	int idCliente;
	char nombre[51];
	char apellido[51];
	char email[51];
	char telefono[51];
	if(this != NULL){
		cliente_getIdCliente(this, &idCliente);
		cliente_getNombre(this, nombre);
		cliente_getApellido(this, apellido);
		cliente_getEmail(this, email);
		cliente_getTelefono(this, telefono);
		printf("%-15s | %-15s | %-35s | %-15s\n", nombre, apellido, email, telefono);
	}
}

int cliente_compareByIdCliente(void* primerCliente, void* segundoCliente){
    int comparison = -2;
    int idPrimerCliente;
    int idSegundoCliente;

    if(primerCliente != NULL && segundoCliente != NULL){
        if(!cliente_getIdCliente(primerCliente, &idPrimerCliente)){
            if(!cliente_getIdCliente(segundoCliente, &idSegundoCliente)){

                if(idPrimerCliente<idSegundoCliente){
                    comparison = -1;
                }
                else{
                    comparison = 0;
                    if(idPrimerCliente>idSegundoCliente){
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int cliente_compareByCarId(void* primerCliente, void* segundoCliente){
    int comparison = -2;
    int idPrimerAuto;
    int idSegundoAuto;

    if(primerCliente != NULL && segundoCliente != NULL){
        if(!cliente_getIdAuto(primerCliente, &idPrimerAuto)){
            if(!cliente_getIdAuto(segundoCliente, &idSegundoAuto)){

                if(idPrimerAuto<idSegundoAuto){
                    comparison = -1;
                }
                else{
                    comparison = 0;
                    if(idPrimerAuto>idSegundoAuto){
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int cliente_compareByName(void* primerCliente, void* segundoCliente){
    int comparison = -2;
    char firstName[51];
    char secondName[51];

    if(primerCliente != NULL && primerCliente != NULL){
        if(!cliente_getNombre(primerCliente, firstName)){
            if(!cliente_getNombre(segundoCliente, secondName)){
                comparison = strcmp(firstName, secondName);
                if(comparison > 0){
                    comparison = 1;
                }
                else{
                    if(comparison < 0){
                        comparison = -1;
                    }
                }
            }
        }
    }
    return comparison;
}

int cliente_compareByLastName(void* primerCliente, void* segundoCliente){
    int comparison = -2;
    char firstLastName[51];
    char secondLastName[51];

    if(primerCliente != NULL && primerCliente != NULL){
        if(!cliente_getApellido(primerCliente, firstLastName)){
            if(!cliente_getApellido(segundoCliente, secondLastName)){
                comparison = strcmp(firstLastName, secondLastName);
                if(comparison > 0){
                    comparison = 1;
                }
                else{
                    if(comparison < 0){
                        comparison = -1;
                    }
                }
            }
        }
    }
    return comparison;
}

int cliente_compareByEmail(void* primerCliente, void* segundoCliente){
    int comparison = -2;
    char firstEmail[51];
    char secondEmail[51];

    if(primerCliente != NULL && primerCliente != NULL){
        if(!cliente_getEmail(primerCliente, firstEmail)){
            if(!cliente_getEmail(segundoCliente, secondEmail)){
                comparison = strcmp(firstEmail, secondEmail);
                if(comparison > 0){
                    comparison = 1;
                }
                else{
                    if(comparison < 0){
                        comparison = -1;
                    }
                }
            }
        }
    }
    return comparison;
}

int cliente_compareByPhone(void* primerCliente, void* segundoCliente){
    int comparison = -2;
    char firstPhone[51];
    char secondPhone[51];

    if(primerCliente != NULL && primerCliente != NULL){
        if(!cliente_getTelefono(primerCliente, firstPhone)){
            if(!cliente_getTelefono(segundoCliente, secondPhone)){
                comparison = strcmp(firstPhone, secondPhone);
                if(comparison > 0){
                    comparison = 1;
                }
                else{
                    if(comparison < 0){
                        comparison = -1;
                    }
                }
            }
        }
    }
    return comparison;
}

int cliente_filterByName(void* this, void* criteria){
    int meetsCriteria = -1;
    char criteriaString[51];
    char nombreCliente[51];
    eCliente* cliente;

    if(this != NULL && criteria != NULL){
        cliente = (eCliente*) this;
        strcpy(criteriaString,(char*)criteria);
        if(!cliente_getNombre(cliente, nombreCliente)){
            if(!strcmp(nombreCliente, criteriaString)){
                meetsCriteria = 0;
            }
        }
    }
    return meetsCriteria;
}

int cliente_filterByLastName(void* this, void* criteria){
    int meetsCriteria = -1;
    char criteriaString[51];
    char apellidoCliente[51];
    eCliente* cliente;

    if(this != NULL && criteria != NULL){
        cliente = (eCliente*) this;
        strcpy(criteriaString,(char*)criteria);
        if(!cliente_getApellido(cliente, apellidoCliente)){
            if(!strcmp(apellidoCliente, criteriaString)){
                meetsCriteria = 0;
            }
        }
    }
    return meetsCriteria;
}

int cliente_filterByCarId(void* this, void* criteria){
    int meetsCriteria = -1;
    int* criteriaId;
    int carId;
    eCliente* cliente;

    if(this != NULL && criteria != NULL){
        cliente = (eCliente*) this;
        criteriaId = (int*)criteria;
        if(!cliente_getIdAuto(cliente, &carId)){
            if(*criteriaId == carId){
                meetsCriteria = 1;
            }
        }
    }
    return meetsCriteria;
}

int cliente_countClientsByLastName(void* pElement){
    int returnAux = 0;
    char auxClientLastName[51];
    eCliente* cliente;
    cliente = (eCliente*)pElement;
    if(cliente != NULL){
    	cliente_getApellido(cliente, auxClientLastName);
    	if(strcmp(auxClientLastName, "Stollard") == 0){
    		returnAux = 1;
    	}
    }
    return returnAux;
}
