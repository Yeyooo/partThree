#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef HASH_ENCADENAMIENTO_H
#include "hash_encadenamiento.h"
#define HASH_ENCADENAMIENTO_H
#endif

int main(){
    Nodo *table[m];
    iniciarNodosTabla(table);

    //mostrarTabla(table);
    //generarTablaConDatos(table);
    generarTablaConDatosArchivo(table);
    //printf("\n\n%ld %s %s %s\n", table[0]->datos.rut,table[0]->datos.nombres, table[0]->datos.apellidoP, table[0]->datos.apellidoM);
    //printf("\n\n%ld %s %s %s\n", table[0]->sgte_dato->datos.rut,table[0]->sgte_dato->datos.nombres, table[0]->sgte_dato->datos.apellidoP, table[0]->sgte_dato->datos.apellidoM);
    //printf("\n\n%ld %s %s %s\n", table[0]->sgte_dato->sgte_dato->datos.rut,table[0]->sgte_dato->sgte_dato->datos.nombres, table[0]->sgte_dato->sgte_dato->datos.apellidoP, table[0]->sgte_dato->sgte_dato->datos.apellidoM);
    //printf("\n\n%ld %s %s %s\n", table[0]->sgte_dato->sgte_dato->sgte_dato->datos.rut,table[0]->sgte_dato->sgte_dato->sgte_dato->datos.nombres, table[0]->sgte_dato->sgte_dato->sgte_dato->datos.apellidoP, table[0]->sgte_dato->sgte_dato->sgte_dato->datos.apellidoM);
    //printf("\n\n%ld %s %s %s\n", table[1]->datos.rut,table[1]->datos.nombres, table[1]->datos.apellidoP, table[1]->datos.apellidoM);
    //printf("\n\n%ld %s %s %s\n", table[2]->datos.rut,table[2]->datos.nombres, table[2]->datos.apellidoP, table[2]->datos.apellidoM);
    //printf("\n\n%ld %s %s %s\n", table[3]->datos.rut,table[3]->datos.nombres, table[3]->datos.apellidoP, table[3]->datos.apellidoM);
    //printf("\n\n%ld %s %s %s\n", table[4]->datos.rut,table[4]->datos.nombres, table[4]->datos.apellidoP, table[4]->datos.apellidoM);
    int rutIngresado;
    printf("Ingrese el Rut de la persona...\n");
    scanf("%ld", &rutIngresado);

    Nodo* encontrado=buscarDatosEnTabla(table, hash(rutIngresado), rutIngresado);
    if(encontrado!=NULL){
        printf("\n\nDatos encontrados!:\n\n");
        printf("Rut: %ld\n", encontrado->datos.rut);
        printf("Nombres: %s\n", encontrado->datos.nombres);
        printf("ApellidoP: %s\n", encontrado->datos.apellidoP);
        printf("ApellidoM: %s\n", encontrado->datos.apellidoM);
    }else
        printf("\n\nLos Datos no se encuentran en la Tabla Hash...\n");

    return 0;
}
