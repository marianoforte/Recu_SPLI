#include "autos.h"

static int lastCarId = 0;

int auto_setLastId(int newId){
    int set = -1;
    if(newId>0){
    	lastCarId = newId;
        set = 0;
    }
    return set;
}

int auto_getLastId(void){
    return lastCarId;
}

int auto_increaseLastId(void){
	lastCarId++;
    return lastCarId;
}

int auto_decreaseLastId(void){
	lastCarId--;
    return lastCarId;
}

eAuto* auto_new(void){
    return (eAuto*)calloc(1, sizeof(eAuto));
}

eAuto* auto_newParametros(char* id, char* fabricante, char* modelo, char* anio){
    eAuto* auxAuto;
    int idAux;
    int anioAux;
    int parametersFlag = 1;
    auxAuto = auto_new();
	if(auxAuto != NULL){
		if(id != NULL){
			idAux = atoi(id);
			auto_setId(auxAuto, idAux);
		}
		if(fabricante != NULL){
			auto_setFabricante(auxAuto, fabricante);
		}
		if(modelo != NULL){
			auto_setModelo(auxAuto, modelo);
		}
		if(anio != NULL){
			anioAux = atoi(anio);
			auto_setAnio(auxAuto, anioAux);
		}
		parametersFlag = 0;

	}
	if(parametersFlag){
		auto_delete(auxAuto);
	}
    return auxAuto;
}

int auto_getId(eAuto* this, int* id){
    int set = -1;

    if(this != NULL){
        *id=this->id;
        set = 0;
    }
    return set;
}

int auto_setId(eAuto* this, int id){
    int set = -1;

    if(this != NULL){
        this->id = id;
        set = 0;
    }
    return set;
}

int auto_getFabricante(eAuto* this, char* fabricante){
    int set = -1;

    if(this != NULL){
        strcpy(fabricante,this->fabricante);
        set = 0;
    }
    return set;
}

int auto_setFabricante(eAuto* this, char* fabricante){
    int set = -1;

    if(this != NULL){
        strcpy(this->fabricante, fabricante);
        set = 0;
    }
    return set;
}

int auto_getModelo(eAuto* this, char* modelo){
    int set = -1;

    if(this != NULL){
        strcpy(modelo,this->modelo);
        set = 0;
    }
    return set;
}

int auto_setModelo(eAuto* this, char* modelo){
    int set = -1;

    if(this != NULL){
        strcpy(this->modelo, modelo);
        set = 0;
    }
    return set;
}

int auto_getAnio(eAuto* this, int* anio){
    int set = -1;

    if(this != NULL){
        *anio=this->anio;
        set = 0;
    }
    return set;
}

int auto_setAnio(eAuto* this, int anio){
    int set = -1;

    if(this != NULL){
        this->anio = anio;
        set = 0;
    }
    return set;
}


int auto_delete(eAuto* this){
    int deletedElement = -1;
    if(this != NULL){
        free(this);
        this = NULL;
        deletedElement = 0;
    }
    return deletedElement;
}

int auto_printOne(eAuto* this){
    int id;
    char fabricante[51];
    char modelo[51];
    int anio;
    int printedCar = -1;
    if(this != NULL){
		auto_getId(this, &id);
		auto_getFabricante(this, fabricante);
		auto_getModelo(this, modelo);
		auto_getAnio(this, &anio);
		printf("%-3d | %-15s | %-20s | %-15d\n", id, fabricante, modelo, anio);
		printedCar = 0;
    }
    return printedCar;
}

int auto_filterByBrand(void* this, void* criteria){
    int meetsCriteria = -1;
    char criteriaString[51];
    char marcaAuto[51];
    eAuto* automovil;

    if(this != NULL && criteria != NULL){
    	automovil = (eAuto*) this;
        strcpy(criteriaString,(char*)criteria);
        if(!auto_getFabricante(automovil, marcaAuto)){
            if(!strcmp(marcaAuto, criteriaString)){
                meetsCriteria = 0;
            }
        }
    }
    return meetsCriteria;
}

int auto_filterByModel(void* this, void* criteria){
    int meetsCriteria = -1;
    char* criteriaString;
    char modeloAuto[51];
    eAuto* automovil;

    if(this != NULL && criteria != NULL){
    	automovil = (eAuto*) this;
        criteriaString = (char*)criteria;
        if(auto_getModelo(automovil, modeloAuto) == 0){
        	printf("\n%d\n", strcmp(modeloAuto, criteriaString));
            if(strcmp(modeloAuto, criteriaString) == 0){
                meetsCriteria = 1;
            }
        }
    }
    return meetsCriteria;
}

int auto_filterByYear(void* this, void* criteria){
    int meetsCriteria = -1;
    int* criteriaInt;
    int anioAuto;
    eAuto* automovil;

    if(this != NULL && criteria != NULL){
    	automovil = (eAuto*) this;
    	criteriaInt = (int*)criteria;
        if(!auto_getAnio(automovil, &anioAuto)){
            if(*criteriaInt == anioAuto){
                meetsCriteria = 1;
            }
        }
    }
    return meetsCriteria;
}

int auto_countCarsByBrand(void* pElement){
    int returnAux = 0;
    char auxCarBrand[51];
    eAuto* car;
    car = (eAuto*)pElement;
    if(car != NULL){
    	auto_getFabricante(car, auxCarBrand);
    	if(strcmp(auxCarBrand, "Toyota") == 0){
    		returnAux = 1;
    	}
    }
    return returnAux;
}

