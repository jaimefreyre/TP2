#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
// #include "funciones.h"

#define MAX 20
#define VACIO 0
#define ACTIVO 1
#define BORRADO 2

struct agenda
{
    char nombre[50];
    long int dni;
    char email[25];
    char direccion[20];
    int edad;
    int estado;
};

typedef struct agenda agenda;


void menu();
void inicializador(agenda datos[20]);
agenda datos[20];

void alta(agenda datos[20]);
void baja(agenda datos[20]);
void mostrar(agenda datos[20]);
void mostrarActivos(agenda datos[20]);
void grafico(agenda datos[20]);
void buscar(agenda datos[20]);

int main()
{


    
    inicializador(datos);

    int op = 0;
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1 : alta(datos); break;
            case 2 : baja(datos); break;
            case 3 : buscar(datos); break;
            case 4 : mostrarActivos(datos); break;
            case 5 : mostrar(datos); break;
            case 6 : grafico(datos);break;
            case 7: op=7; break;
            system("cls");
        }

    }while(op!= 7);
    return 0;
}

void inicializador(agenda datos[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        strcpy(datos[i].nombre, "");
        datos[i].dni = 0;
        strcpy(datos[i].email, "NULA");
        strcpy(datos[i].direccion, "NULA");
        datos[i].edad = 0;
        datos[i].estado = VACIO;
    }
}

void menu(){
    system("color 17");
    printf("                                                                                                                    \n");
    printf("                                             Elija una opcion \a                                                    \n");
    printf("                                                                                                                    \n");
    printf("                                             1.Agregar persona                                                      \n");
    printf("                                                                                                                    \n");
    printf("                                             2.Borrar persona                                                       \n");
    printf("                                                                                                                    \n");
    printf("                                             3.Busqueda de nombre                                                   \n");
    printf("                                                                                                                    \n");
    printf("                                             4.Activos                                                              \n");
    printf("                                                                                                                    \n");
    printf("                                             5.Imprimir lista ordenada por  nombre                                  \n");
    printf("                                                                                                                    \n");
    printf("                                             6.Imprimir grafico                                                     \n");
    printf("                                                                                                                    \n");
    printf("                                             7.Salir                                                                \n");
    printf("                                                                                                                    \n");
    printf("                                                                                                                      \n");
    printf("                                           Seleccione una opcion: " );
}

// void alta(agenda datos[20]);
// void baja(agenda datos[20]);
// void mostrar(agenda datos[20]);
// void mostrarActivos(agenda datos[20]);
// void grafico(agenda datos[20]);
// void buscar(agenda datos[20]);

