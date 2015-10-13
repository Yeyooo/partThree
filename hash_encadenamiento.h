#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef STRING_H
#include <string.h>
#define STRING_H
#endif

#ifndef TIME_H
#include <time.h>
#define TIME_H
#endif

#define m 10

typedef long int Clave;

typedef struct registro{
    Clave rut; // agregar nombre y apellidos
    char nombres[100];
    char apellidoP[30];
    char apellidoM[30];
}Registro;

typedef struct nodo{
    Registro datos;
    struct nodo *sgte_dato;
}Nodo;

int hash(Clave unRut){
    return (unRut%m);
}

Nodo *iniciarNodo(long unRut, char unosNombres[100], char unApellidoP[30], char unApellidoM[30]){
	Nodo *tmp=(Nodo*)malloc(sizeof(struct nodo));
	tmp->datos.rut=unRut;
	strcpy(tmp->datos.nombres, unosNombres);
	strcpy(tmp->datos.apellidoP, unApellidoP);
	strcpy(tmp->datos.apellidoM, unApellidoM);
	tmp->sgte_dato=NULL;
	return tmp;
}

void iniciarNodosTabla(Nodo *unaTabla[m]){
    int i = 0;
    while( i < m ){
        unaTabla[i]=iniciarNodo(0,"0","0","0");
        i++;
    }

}



void generarTablaConDatosArchivo(Nodo *unaTabla[m]){
    FILE *fp=fopen("datos.csv", "r");
    long rutI;
    char apellidop[30], apellidom[30], nombres[100];
    clock_t start = clock();

    while(!feof(fp)){
        fscanf(fp, "%ld;", &rutI);
        fscanf(fp, "%[^;];", &apellidop);
        fscanf(fp, "%[^;];", &apellidom);
        fscanf(fp, "%[^\n];", &nombres);

        if(unaTabla[hash(rutI)]->datos.rut==0){
            unaTabla[hash(rutI)]=iniciarNodo(rutI, nombres, apellidop, apellidom);
        }else{
            Nodo *aux=unaTabla[hash(rutI)]->sgte_dato;
            unaTabla[hash(rutI)]->sgte_dato=iniciarNodo(rutI, nombres, apellidop, apellidom);
            unaTabla[hash(rutI)]->sgte_dato->sgte_dato=aux;
        }
    }

    fclose(fp);
    printf("Tiempo transcurrido: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);


}

Nodo *buscarDatosEnTabla(Nodo * unaTabla[m], int indiceHashRut, long unRut){
    Nodo *recorrer=unaTabla[indiceHashRut];
    clock_t start = clock();
    while(recorrer!=NULL){
        if(recorrer->datos.rut==unRut){
            printf("Tiempo transcurrido de Búsqueda: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
            return(recorrer);
        }
        recorrer=recorrer->sgte_dato;
    }
    return(NULL);

}





























