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

    generarTablaConDatosArchivo(table);

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
