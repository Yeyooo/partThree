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

void mostrarTabla(Nodo *unaTabla[m]){
    int i = 0;
    while( i < m ){
        printf("table[%d]: %d, table[%d]->sgte: %d\n", i, unaTabla[i]->datos.rut, i, unaTabla[i]->sgte_dato->datos.rut);
        i++;
    }

}

/*void generarTablaConDatos(Nodo *unaTabla[m]){
    //FILE *fp=fopen("aleatorios.csv", "r");
    long x;
    long contador=0;
    long rutI;
    printf("ingrese rut\n");
    scanf("%ld", &rutI);

    if(unaTabla[hash(rutI)]->datos.rut==0){
        unaTabla[hash(rutI)]=iniciarNodo(rutI);
    }else{
        Nodo *aux=unaTabla[hash(rutI)]->sgte_dato;
        unaTabla[hash(rutI)]->sgte_dato=iniciarNodo(rutI);
        unaTabla[hash(rutI)]->sgte_dato->sgte_dato=aux;
    }





}*/

void generarTablaConDatosArchivo(Nodo *unaTabla[m]){
    FILE *fp=fopen("datos.csv", "r");
    long rutI;
    char apellidop[30], apellidom[30], nombres[100];

    while(!feof(fp)){
        fscanf(fp, "%ld;", &rutI); //fscanf(fp, "%ld %s %s %s %[^\n]", &rutI, &apellidop, &apellidom, &nombres);
        fscanf(fp, "%[^;];", &apellidop);
        fscanf(fp, "%[^;];", &apellidom);
        fscanf(fp, "%[^\n];", &nombres);
        printf("rut: %ld app: %s apm: %s nombres: %s\n", rutI, apellidop, apellidom, nombres);

        if(unaTabla[hash(rutI)]->datos.rut==0){
            unaTabla[hash(rutI)]=iniciarNodo(rutI, nombres, apellidop, apellidom);
        }else{
            Nodo *aux=unaTabla[hash(rutI)]->sgte_dato;
            unaTabla[hash(rutI)]->sgte_dato=iniciarNodo(rutI, nombres, apellidop, apellidom);
            unaTabla[hash(rutI)]->sgte_dato->sgte_dato=aux;
        }
    }

    fclose(fp);


}

Nodo *buscarDatosEnTabla(Nodo * unaTabla[m], int indiceHashRut, long unRut){
    Nodo *recorrer=unaTabla[indiceHashRut];
    while(recorrer!=NULL){
        if(recorrer->datos.rut==unRut){
            return(recorrer);
        }
        recorrer=recorrer->sgte_dato;
    }
    return(NULL);

}





























